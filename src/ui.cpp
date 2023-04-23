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
    pFileOpenAct->setObjectName(QString::fromUtf8("FileOpen"));
    pFileOpenAct->setText("Open");
    pMenuFile->addAction(pFileOpenAct);
    pMenuBar->addAction(pMenuHelp->menuAction());
    pAboutAct = new QAction(pMainWindow);
    pAboutAct->setObjectName(QString::fromUtf8("About"));
    pAboutAct->setText("About");
    pMenuHelp->addAction(pAboutAct);
}

void Ui::setupSide()
{
    pSideGrp = new QGroupBox(pCentralWidget);
    pSideGrp->setTitle(QString::fromUtf8("Menu"));
    pSideVerticalLayout = new QVBoxLayout(pSideGrp);

    pConnGrp = new QGroupBox(pSideGrp);
    pConnGrp->setTitle(QString::fromUtf8("Connection"));
    pConnVerticalLayout = new QVBoxLayout(pConnGrp);
    pConnFormLayout = new QFormLayout();
    pConnStatusLabel = new QLabel(pConnGrp);
    pConnStatusLabel->setText(QString::fromUtf8("Status:"));
    pConnFormLayout->setWidget(0, QFormLayout::LabelRole, pConnStatusLabel);
    pConnStatus = new QLineEdit(pConnGrp);
    pConnStatus->setEnabled(false);
    pConnStatus->setAlignment(Qt::AlignCenter);
    pConnStatus->setReadOnly(true);
    pConnFormLayout->setWidget(0, QFormLayout::FieldRole, pConnStatus);
    pConnStatus->setText(QString::fromUtf8("Not connected"));
    pConnVerticalLayout->addLayout(pConnFormLayout);

    pConnHorizontalLayoutParams = new QHBoxLayout();
    pConnPortLabel = new QLabel(pConnGrp);
    pConnPortLabel->setText(QString::fromUtf8("Port: "));
    pConnHorizontalLayoutParams->addWidget(pConnPortLabel);
    pConnPortCbo = new QComboBox(pConnGrp);
    pConnHorizontalLayoutParams->addWidget(pConnPortCbo);
    pConnButtonRefresh = new QToolButton(pConnGrp);
    pConnButtonRefresh->setObjectName(QString::fromUtf8("BaudRefresh"));
    pConnButtonRefresh->setText(QString::fromUtf8("Refresh"));
    pConnHorizontalLayoutParams->addWidget(pConnButtonRefresh);
    pConnBaudLabel = new QLabel(pConnGrp);
    pConnBaudLabel->setText(QString::fromUtf8("Boud: "));
    pConnHorizontalLayoutParams->addWidget(pConnBaudLabel);
    pConnBaudCbo = new QComboBox(pConnGrp);
    pConnBaudCbo->addItem(QString::fromUtf8("9600"));
    pConnBaudCbo->addItem(QString::fromUtf8("14400"));
    pConnBaudCbo->addItem(QString::fromUtf8("19200"));
    pConnBaudCbo->addItem(QString::fromUtf8("38400"));
    pConnBaudCbo->addItem(QString::fromUtf8("57600"));
    pConnBaudCbo->addItem(QString::fromUtf8("115200"));
    pConnHorizontalLayoutParams->addWidget(pConnBaudCbo);
    pConnVerticalLayout->addLayout(pConnHorizontalLayoutParams);
    pConnHorizontalLayoutActions = new QHBoxLayout();
    pConnBtnConnect = new QToolButton(pConnGrp);
    pConnBtnConnect->setObjectName(QString::fromUtf8("Connect"));
    pConnBtnConnect->setText(QString::fromUtf8("Connect"));
    pConnHorizontalLayoutActions->addWidget(pConnBtnConnect);
    pConnBtnStop = new QToolButton(pConnGrp);
    pConnBtnStop->setText(QString::fromUtf8("Stop"));
    pConnHorizontalLayoutActions->addWidget(pConnBtnStop);
    pConnVerticalLayout->addLayout(pConnHorizontalLayoutActions);
    pSideVerticalLayout->addWidget(pConnGrp);

    pStateGrp = new QGroupBox(pSideGrp);
    pStateGrp->setTitle(QString::fromUtf8("State"));
    pStateVerticalLayout = new QVBoxLayout(pStateGrp);
    pStateLabel = new QLabel(pStateGrp);
    pStateLabel->setText(QString::fromUtf8("Coordinates:"));
    pStateVerticalLayout->addWidget(pStateLabel);
    pStateHorizontalLayout = new QHBoxLayout();
    pPosXtxt = new QLineEdit(pStateGrp);
    pPosXtxt->setText(QString::fromUtf8("0"));
    pPosXtxt->setAlignment(Qt::AlignCenter);
    pPosXtxt->setReadOnly(true);
    pStateHorizontalLayout->addWidget(pPosXtxt);
    pPosYtxt = new QLineEdit(pStateGrp);
    pPosYtxt->setText(QString::fromUtf8("0"));
    pPosYtxt->setAlignment(Qt::AlignCenter);
    pPosYtxt->setReadOnly(true);
    pStateHorizontalLayout->addWidget(pPosYtxt);
    pPosZtxt = new QLineEdit(pStateGrp);
    pPosZtxt->setAlignment(Qt::AlignCenter);
    pPosZtxt->setReadOnly(true);
    pPosZtxt->setText(QString::fromUtf8("0"));
    pStateHorizontalLayout->addWidget(pPosZtxt);
    pStateVerticalLayout->addLayout(pStateHorizontalLayout);
    pSideVerticalLayout->addWidget(pStateGrp);

    pConsoleGrp = new QGroupBox(pSideGrp);
    pConsoleGrp->setTitle(QString::fromUtf8("Console"));
    pConsoleVerticalLayout = new QVBoxLayout(pConsoleGrp);
    pConsoleOutputTxt = new QPlainTextEdit(pConsoleGrp);
    pConsoleVerticalLayout->addWidget(pConsoleOutputTxt);
    pConsoleHorizontalLayout = new QHBoxLayout();
    pConsoleCmdTxt = new QLineEdit(pConsoleGrp);
    pConsoleHorizontalLayout->addWidget(pConsoleCmdTxt);
    pConsoleButton = new QPushButton(pConsoleGrp);
    pConsoleButton->setText(QString::fromUtf8(">"));
    pConsoleHorizontalLayout->addWidget(pConsoleButton);
    pConsoleVerticalLayout->addLayout(pConsoleHorizontalLayout);
    pSideVerticalLayout->addWidget(pConsoleGrp);
}

void Ui::setupProgram()
{
    pProgramGrp = new QGroupBox(pCentralWidget);
    pProgramGrp->setTitle(QString::fromUtf8("Program"));
    pProgramVerticalLayout = new QVBoxLayout(pProgramGrp);

    pGraph = new Graph(pProgramGrp);
    pProgramVerticalLayout->addWidget(pGraph, 1);

    pProgramTbl = new QTableView(pProgramGrp);
    pProgramVerticalLayout->addWidget(pProgramTbl, 1);
}
