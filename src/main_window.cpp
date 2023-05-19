#include "main_window.h"

MainWindow::MainWindow(QWidget* pParent) : QMainWindow{ pParent }
{
    mpGcodeDrawer = new GcodeDrawer(this, mGcodeViewParser);

    mUi.setup(this);

    mUi.pProgramTbl->setModel(&mTblModel);
    mUi.pProgramTbl->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    mUi.pGraph->addDrawable(mpGcodeDrawer);
    mUi.pGraph->addDrawable(&mToolDrawer);

    QObject::connect(mUi.pConsoleCmdTxt, &QLineEdit::returnPressed, this, &MainWindow::sendConsole);

    searchPorts();
    updateControlsState();

    connect(&mSerialPort, &QSerialPort::readyRead, this, &MainWindow::onSerialPortReadyRead);
    connect(&mSerialPort, &QSerialPort::errorOccurred, this, &MainWindow::onSerialPortError);

    connect(&mTimerConnection, &QTimer::timeout, this, &MainWindow::onTimerConnection);
    connect(&mTimerStateQuery, &QTimer::timeout, this, &MainWindow::onTimerStateQuery);
}

MainWindow::~MainWindow()
{
    if (mSerialPort.isOpen())
    {
        mSerialPort.close();
    }
}

void MainWindow::processFile(QString fileName)
{
    QFile file{ fileName };

    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }

    mIsFileLoading = true;
    updateControlsState();

    QTextStream textStream(&file);

    mTblModel.clear();
    mTblModel.insertRow(0);

    GcodeParser gp;
    while (!textStream.atEnd())
    {
        QString command{ textStream.readLine() };

        gp.addCommand(command);
        auto index{ mTblModel.rowCount() };
        mTblModel.setData(mTblModel.index(index - 1, 0), command);
        mTblModel.setData(mTblModel.index(index - 1, 1), "In queue");
        mTblModel.insertRow(mTblModel.rowCount());
    }

    mGcodeViewParser.getLinesFromParser(&gp);

    mIsFileLoading = false;
    updateControlsState();
}

void MainWindow::on_Send_clicked()
{
    if (mTblModel.rowCount() == 0)
    {
        return;
    }

    reset();

    mIsFileSending = true;
    updateControlsState();

    sendNextFileCommands();

    updateControlsState();
}

void MainWindow::on_Stop_clicked()
{
    mSerialPort.write(mIsStopped ? "~" : "!");
    mIsStopped = !mIsStopped;
}


void MainWindow::sendNextFileCommands()
{
    QString command{ mTblModel.data(mTblModel.index(mFileCommandIndex, 0)).toString() };

    while (((bufferLength() + command.length() + 1) <= maxBufferLength) && (mFileCommandIndex < mTblModel.rowCount() - 1))
    {
        mTblModel.setData(mTblModel.index(mFileCommandIndex, 1), "Sended");
        sendCommand(command, mFileCommandIndex);
        mFileCommandIndex++;
        command = mTblModel.data(mTblModel.index(mFileCommandIndex, 0)).toString();
    }
}

void MainWindow::sendCommand(QString command, int idx)
{
    if (!mSerialPort.isOpen())
    {
        QMessageBox::critical(this, "Critical", "Milling machine is not connected");
        return;
    }

    CommandAttributes ca;
    ca.command = command;
    ca.length = command.length() + 1;
    ca.tableIndex = idx;
    mCommands.append(ca);
    mSerialPort.write((command + "\r").toLatin1());
}

int MainWindow::bufferLength()
{
    int length{};

    for (const auto ca : mCommands)
    {
        length += ca.length;
    }

    return length;
}

void MainWindow::reset()
{
    mFileCommandIndex = 0;
    mIsFileSending = false;
    mIsStopped = false;
    mCommands.clear();

    for (int i{}; i < mTblModel.rowCount() - 1; ++i)
    {
        mTblModel.setData(mTblModel.index(i, 1), "In queue");
    }

    updateControlsState();
}

void MainWindow::searchPorts()
{
    mUi.pConnPortCbo->clear();

    for (const auto& info : QSerialPortInfo::availablePorts())
    {
        mUi.pConnPortCbo->insertItem(0, info.portName());
    }
}

void MainWindow::sendConsole()
{
    auto command{ mUi.pConsoleCmdTxt->text() };
    if (command.isEmpty())
    {
        return;
    }

    sendCommand(command, -1);
    mUi.pConsoleOutputTxt->appendPlainText(command);
    mUi.pConsoleCmdTxt->clear();
}


void MainWindow::updateControlsState()
{
    bool portOpened{ mSerialPort.isOpen() };

    mUi.pConnPortCbo->setEnabled(!mIsFileLoading);
    mUi.pConnButtonRefresh->setEnabled(!mIsFileLoading);
    mUi.pConnBaudCbo->setEnabled(!mIsFileLoading);
    mUi.pConnBtnConnect->setEnabled(!mIsFileLoading);
    mUi.pConnBtnStop->setEnabled(!mIsFileLoading && portOpened);
    mUi.pConnBtnSend->setEnabled(!mIsFileLoading && portOpened && !mIsFileSending);
    mUi.pStatePosXtxt->setEnabled(!mIsFileLoading && portOpened);
    mUi.pStatePosYtxt->setEnabled(!mIsFileLoading && portOpened);
    mUi.pStatePosZtxt->setEnabled(!mIsFileLoading && portOpened);
    mUi.pConsoleCmdTxt->setEnabled(!mIsFileLoading && portOpened);
    mUi.pConBtn->setEnabled(!mIsFileLoading && portOpened);

    mUi.pConnBtnConnect->setText(portOpened ? "Reset" : "Connect");
    mUi.pConnStatus->setText(portOpened ? "Connected" : "Not connected");
    mUi.pConnBtnStop->setText(!mIsStopped ? "Stop" : "Resume");

    qApp->processEvents();
    update();
}

bool MainWindow::openPort()
{
    if (mSerialPort.open(QIODevice::ReadWrite))
    {
        reset();
        return true;
    }

    return false;
}

void MainWindow::onSerialPortError(QSerialPort::SerialPortError e)
{
    static QSerialPort::SerialPortError previousError;

    if (e != QSerialPort::NoError && e != previousError)
    {
        mUi.pConsoleOutputTxt->appendPlainText("Serial port error " + QString::number(e) + ": " + mSerialPort.errorString());
        if (mSerialPort.isOpen())
        {
            mSerialPort.close();
            updateControlsState();
        }
        previousError = e;
    }
}

void MainWindow::onSerialPortReadyRead()
{
    while (mSerialPort.canReadLine())
    {
        QString data{ mSerialPort.readLine().trimmed() };
#ifdef _DEBUG
        if (data[0] != '<')
        {
            qDebug() << data;
        }
#endif
        if (data.startsWith("Grbl"))
        {
            mCommands.clear();
        }
        else if (data.startsWith("error:"))
        {
            mUi.pConsoleOutputTxt->appendPlainText(data);
        }
        else if (data[0] == '<')
        {
            QRegExp rx("<([^,]*),MPos:([^,]*),([^,]*),([^,]*),WPos:([^,]*),([^,]*),([^,]*)>");
            if (rx.indexIn(data) != -1)
            {
                mUi.pStatePosXtxt->setText(rx.cap(5));
                mUi.pStatePosYtxt->setText(rx.cap(6));
                mUi.pStatePosZtxt->setText(rx.cap(7));
            }

            mToolDrawer.setToolPosition( {
                mUi.pStatePosXtxt->text().toFloat(),
                mUi.pStatePosYtxt->text().toFloat(),
                mUi.pStatePosZtxt->text().toFloat()
            });
        }
        else if (mCommands.length() > 0)
        {
            CommandAttributes ca = mCommands.takeFirst();

            if (mIsFileSending)
            {
                if (ca.tableIndex != -1)
                {
                    mTblModel.setData(mTblModel.index(ca.tableIndex, 1), "Processed");
                    mUi.pProgramTbl->scrollTo(mTblModel.index(ca.tableIndex + 1, 0));
                    mUi.pProgramTbl->setCurrentIndex(mTblModel.index(ca.tableIndex, 1));

                    if (ca.tableIndex == (mTblModel.rowCount() - 1))
                    {
                        mIsFileSending = false;
                    }
                }
                sendNextFileCommands();
            }
        }
    }
}

void MainWindow::onTimerConnection()
{
    if (!mSerialPort.isOpen())
    {
        openPort();
    }
}

void MainWindow::onTimerStateQuery()
{
    if (mSerialPort.isOpen())
    {
        mSerialPort.write(QByteArray(1, '?'));
    }
}

void MainWindow::on_Connect_clicked()
{
    if (mSerialPort.isOpen())
    {
        mSerialPort.close();
    }

    auto port{ getPort() };
    auto baud{ getBaud().toInt() };
    if ((port != "") && (port != mSerialPort.portName() || (baud != mSerialPort.baudRate())))
    {
        mSerialPort.setPortName(port);
        mSerialPort.setBaudRate(baud);
    }

    if (openPort())
    {
        mTimerConnection.start(1000);
        mTimerStateQuery.start();
    }
    else
    {
        QMessageBox::critical(this, "Critical", "Couldn't connect to the milling machine");
    }
}

void MainWindow::on_FileOpen_triggered()
{
    QString fileName{ QFileDialog::getOpenFileName(this, "Open", "", "G-Code files (*.nc)") };

    if (fileName.size() > 0)
    {
        processFile(fileName);
    }
}

void MainWindow::on_About_triggered()
{
    QMessageBox::information(this, "About",
        "Simple GRBL Controller made for Michelin Olsztyn\n"
        "as the part of the University of Warmia and Mazury assingment project\n\n"
        "Authors: Damian Tomczak, Dominik Slodkowski, Szymon Chura");
}

void MainWindow::on_Constraints_triggered()
{
    QMessageBox::information(this, "Constraints",
        "Program was tested only on CNC 3018 with workspace 300x180x45\n"
        "Files should be formmated to the format:\n"
        "G1 X-22.027 Y-5.037 Z-0.281");
}
