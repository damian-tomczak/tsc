#include "ui.h"

void Ui::setup(QMainWindow* pMainWindow)
{
    pMainWindow->resize(1280, 720);

    pCentralWidget = new QWidget(pMainWindow);
    pMainWindow->setCentralWidget(pCentralWidget);

    pCentralHorizontalLayout = new QHBoxLayout(pCentralWidget);

    setupMenu();
    pCentralHorizontalLayout->addWidget(pMenuGrp);

    setupProgram();
    pCentralHorizontalLayout->addWidget(pProgramGrp);

    QMetaObject::connectSlotsByName(pMainWindow);
}

void Ui::setupMenu()
{
    pMenuGrp = new QGroupBox(pCentralWidget);
    pMenuGrp->setTitle(QString::fromUtf8("Menu"));
    pMenuVerticalLayout = new QVBoxLayout(pMenuGrp);

    pConnGrp = new QGroupBox(pMenuGrp);
    pConnGrp->setTitle(QString::fromUtf8("Connection"));
    pConnVerticalLayout = new QVBoxLayout(pConnGrp);
    pConnFormLayout = new QFormLayout(pConnGrp);
    pConnDecorationLabel = new QLabel(pConnGrp);
    pConnDecorationLabel->setText(QString::fromUtf8("Status:"));
    pConnFormLayout->setWidget(0, QFormLayout::LabelRole, pConnDecorationLabel);
    pConnTxt = new QLineEdit(pConnGrp);
    pConnTxt->setEnabled(false);
    pConnTxt->setAlignment(Qt::AlignCenter);
    pConnTxt->setReadOnly(true);
    pConnFormLayout->setWidget(0, QFormLayout::FieldRole, pConnTxt);
    pConnTxt->setText(QString::fromUtf8("Not connected"));
    pConnVerticalLayout->addLayout(pConnFormLayout);

    pConnHorizontalLayout = new QHBoxLayout();
    pConnPortLabel = new QLabel(pConnGrp);
    pConnPortLabel->setText(QString::fromUtf8("Port: "));
    pConnHorizontalLayout->addWidget(pConnPortLabel);
    pConnPortCbo = new QComboBox(pConnGrp);
    pConnHorizontalLayout->addWidget(pConnPortCbo);
    pConnButtonRefresh = new QToolButton(pConnGrp);
    pConnButtonRefresh->setText(QString::fromUtf8("Refresh"));
    pConnHorizontalLayout->addWidget(pConnButtonRefresh);
    pConnBaudLabel = new QLabel(pConnGrp);
    pConnBaudLabel->setText(QString::fromUtf8("Boud: "));
    pConnHorizontalLayout->addWidget(pConnBaudLabel);
    pConnBaudCbo = new QComboBox(pConnGrp);
    pConnBaudCbo->addItem(QString::fromUtf8("9600"));
    pConnBaudCbo->addItem(QString::fromUtf8("14400"));
    pConnBaudCbo->addItem(QString::fromUtf8("19200"));
    pConnBaudCbo->addItem(QString::fromUtf8("38400"));
    pConnBaudCbo->addItem(QString::fromUtf8("57600"));
    pConnBaudCbo->addItem(QString::fromUtf8("115200"));
    pConnHorizontalLayout->addWidget(pConnBaudCbo);
    pConnButtonConnect = new QToolButton(pConnGrp);
    pConnButtonConnect->setText(QString::fromUtf8("Connect"));
    pConnHorizontalLayout->addWidget(pConnButtonConnect);
    pConnVerticalLayout->addLayout(pConnHorizontalLayout);
    pMenuVerticalLayout->addWidget(pConnGrp);


    pStateGrp = new QGroupBox(pMenuGrp);
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
    pMenuVerticalLayout->addWidget(pStateGrp);

    pConsoleGrp = new QGroupBox(pMenuGrp);
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
    pMenuVerticalLayout->addWidget(pConsoleGrp);
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
