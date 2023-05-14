#include "ui.h"

void Ui::setup(QMainWindow* pMainWindow)
{
    pMainWindow->resize(1280, 720);

    setupBar(pMainWindow);

    pCentralWidget = new QWidget(pMainWindow);
    pMainWindow->setCentralWidget(pCentralWidget);
    pCentralHorizontalLayout = new QHBoxLayout(pCentralWidget);

    setupSide();
    pCentralHorizontalLayout->addWidget(pSideGrp);

    setupProgram();
    pCentralHorizontalLayout->addWidget(pProgramGrp);

    QMetaObject::connectSlotsByName(pMainWindow);
}

void Ui::setupBar(QMainWindow* pMainWindow)
{
    pMenuBar = new QMenuBar(pMainWindow);
    pMainWindow->setMenuBar(pMenuBar);
    pMenuBar->setGeometry(QRect(0, 0, 957, 26));
    pMenuFile = new QMenu(pMenuBar);
    pMenuFile->setTitle("File");
    pMenuHelp = new QMenu(pMenuBar);
    pMenuHelp->setTitle("Help");

    pMenuBar->addAction(pMenuFile->menuAction());
    pFileOpenAct = new QAction(pMainWindow);
    pFileOpenAct->setObjectName("FileOpen");
    pFileOpenAct->setText("Open");
    pMenuFile->addAction(pFileOpenAct);

    pMenuBar->addAction(pMenuHelp->menuAction());
    pConstraintsAct = new QAction(pMainWindow);
    pConstraintsAct->setObjectName("Constraints");
    pConstraintsAct->setText("Constraints");
    pMenuHelp->addAction(pConstraintsAct);
    pAboutAct = new QAction(pMainWindow);
    pAboutAct->setObjectName("About");
    pAboutAct->setText("About");
    pMenuHelp->addAction(pAboutAct);
}

void Ui::setupSide()
{
    pSideGrp = new QGroupBox(pCentralWidget);
    pSideGrp->setTitle("Menu");
    pSideVerticalLayout = new QVBoxLayout(pSideGrp);

    pConnGrp = new QGroupBox(pSideGrp);
    pConnGrp->setTitle("Connection");
    pConnVerticalLayout = new QVBoxLayout(pConnGrp);
    pConnFormLayout = new QFormLayout();
    pConnStatusLabel = new QLabel(pConnGrp);
    pConnStatusLabel->setText("Status:");
    pConnFormLayout->setWidget(0, QFormLayout::LabelRole, pConnStatusLabel);
    pConnStatus = new QLineEdit(pConnGrp);
    pConnStatus->setAlignment(Qt::AlignCenter);
    pConnStatus->setReadOnly(true);
    pConnFormLayout->setWidget(0, QFormLayout::FieldRole, pConnStatus);
    pConnStatus->setText("Not connected");
    pConnVerticalLayout->addLayout(pConnFormLayout);

    pConnHorizontalLayoutParams = new QHBoxLayout();
    pConnPortLabel = new QLabel(pConnGrp);
    pConnPortLabel->setText("Port: ");
    pConnHorizontalLayoutParams->addWidget(pConnPortLabel);
    pConnPortCbo = new QComboBox(pConnGrp);
    pConnHorizontalLayoutParams->addWidget(pConnPortCbo);
    pConnButtonRefresh = new QToolButton(pConnGrp);
    pConnButtonRefresh->setObjectName("Refresh");
    pConnButtonRefresh->setText("Refresh");
    pConnHorizontalLayoutParams->addWidget(pConnButtonRefresh);
    pConnBaudLabel = new QLabel(pConnGrp);
    pConnBaudLabel->setText("Baud: ");
    pConnHorizontalLayoutParams->addWidget(pConnBaudLabel);
    pConnBaudCbo = new QComboBox(pConnGrp);
    pConnBaudCbo->addItem("115200");
    pConnBaudCbo->addItem("57600");
    pConnBaudCbo->addItem("38400");
    pConnBaudCbo->addItem("19200");
    pConnBaudCbo->addItem("14400");
    pConnBaudCbo->addItem("9600");
    pConnHorizontalLayoutParams->addWidget(pConnBaudCbo);
    pConnVerticalLayout->addLayout(pConnHorizontalLayoutParams);
    pConnHorizontalLayoutActions = new QHBoxLayout();
    pConnBtnConnect = new QToolButton(pConnGrp);
    pConnBtnConnect->setObjectName("Connect");
    pConnBtnConnect->setText("Connect");
    pConnHorizontalLayoutActions->addWidget(pConnBtnConnect);
    pConnBtnStop = new QToolButton(pConnGrp);
    pConnBtnStop->setObjectName("Stop");
    pConnBtnStop->setText("Stop");
    pConnHorizontalLayoutActions->addWidget(pConnBtnStop);
    pConnVerticalLayout->addLayout(pConnHorizontalLayoutActions);
    pSendHLayoutActs = new QHBoxLayout();
    pConnBtnSend = new QToolButton(pConnGrp);
    pConnBtnSend->setObjectName("Send");
    pConnBtnSend->setText("Send");
    pSendHLayoutActs->addWidget(pConnBtnSend);
    pConnVerticalLayout->addLayout(pSendHLayoutActs);
    pSideVerticalLayout->addWidget(pConnGrp);

    pStateGrp = new QGroupBox(pSideGrp);
    pStateGrp->setTitle("State");
    pStateVerticalLayout = new QVBoxLayout(pStateGrp);
    pStateLabel = new QLabel(pStateGrp);
    pStateLabel->setText("Coordinates:");
    pStateVerticalLayout->addWidget(pStateLabel);
    pStateHorizontalLayout = new QHBoxLayout();
    pStatePosXtxt = new QLineEdit(pStateGrp);
    pStatePosXtxt->setText("0");
    pStatePosXtxt->setAlignment(Qt::AlignCenter);
    pStatePosXtxt->setReadOnly(true);
    pStateHorizontalLayout->addWidget(pStatePosXtxt);
    pStatePosYtxt = new QLineEdit(pStateGrp);
    pStatePosYtxt->setText("0");
    pStatePosYtxt->setAlignment(Qt::AlignCenter);
    pStatePosYtxt->setReadOnly(true);
    pStateHorizontalLayout->addWidget(pStatePosYtxt);
    pStatePosZtxt = new QLineEdit(pStateGrp);
    pStatePosZtxt->setAlignment(Qt::AlignCenter);
    pStatePosZtxt->setReadOnly(true);
    pStatePosZtxt->setText("0");
    pStateHorizontalLayout->addWidget(pStatePosZtxt);
    pStateVerticalLayout->addLayout(pStateHorizontalLayout);
    pSideVerticalLayout->addWidget(pStateGrp);

    pConsoleGrp = new QGroupBox(pSideGrp);
    pConsoleGrp->setTitle("Console");
    pConsoleVerticalLayout = new QVBoxLayout(pConsoleGrp);
    pConsoleOutputTxt = new QPlainTextEdit(pConsoleGrp);
    pConsoleOutputTxt->setReadOnly(true);
    pConsoleVerticalLayout->addWidget(pConsoleOutputTxt);
    pConsoleHorizontalLayout = new QHBoxLayout();
    pConsoleCmdTxt = new QLineEdit(pConsoleGrp);
    pConsoleHorizontalLayout->addWidget(pConsoleCmdTxt);
    pConBtn = new QPushButton(pConsoleGrp);
    pConBtn->setObjectName("ConsoleSend");
    pConBtn->setText(">");
    pConsoleHorizontalLayout->addWidget(pConBtn);
    pConsoleVerticalLayout->addLayout(pConsoleHorizontalLayout);
    pSideVerticalLayout->addWidget(pConsoleGrp);
}

void Ui::setupProgram()
{
    pProgramGrp = new QGroupBox(pCentralWidget);
    pProgramGrp->setTitle("Program");
    pProgramVerticalLayout = new QVBoxLayout(pProgramGrp);

    pGraph = new Graph(pProgramGrp);
    pProgramVerticalLayout->addWidget(pGraph, 1);

    pProgramTbl = new QTableView(pProgramGrp);
    pProgramTbl->setObjectName("ProgramTbl");
    pProgramVerticalLayout->addWidget(pProgramTbl, 1);
}
