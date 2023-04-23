#include "main_window.h"

MainWindow::MainWindow(QWidget* pParent) : QMainWindow(pParent)
{
    mUi.setup(this);
}

MainWindow::~MainWindow() = default;

void MainWindow::on_Connect_clicked()
{
    if (mGrblCtrl.openPort())
    {
        mUi.pConnStatus->setText(tr("Connected"));
    }
}

void MainWindow::on_FileOpen_triggered()
{
    if (!mGrblCtrl.sendCommand("G91G0Y" + 10))
    {
        QMessageBox::critical(this, "Error", "Something went wrong!\n");
    }
}

void MainWindow::on_About_triggered()
{
    QMessageBox::information(this, "About",
        "Simple GRBL Controller made for Michelin Olsztyn\n"
        "as the part of the University of Warmia and Mazury assingment project\n\n"
        "Authors: Damian Tomczak, Dominik Slodkowski, Szymon Chura");
}


void MainWindow::on_BaudRefresh_clicked()
{
    mUi.pConnPortCbo->clear();

    for (const auto& info : QSerialPortInfo::availablePorts())
    {
        mUi.pConnPortCbo->insertItem(0, info.portName());
    }
}