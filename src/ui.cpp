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
}

void Ui::setupMenu()
{
    pMenuGrp = new QGroupBox(pCentralWidget);
    pMenuGrp->setTitle(QString::fromUtf8("Menu"));
    pMenuVerticalLayout = new QVBoxLayout(pMenuGrp);

    pConnectionGrp = new QGroupBox(pMenuGrp);
    pConnectionGrp->setTitle(QString::fromUtf8("Connection"));
    pConnectionFormLayout = new QFormLayout(pConnectionGrp);
    pConnectionLabel = new QLabel(pConnectionGrp);
    pConnectionFormLayout->setWidget(0, QFormLayout::LabelRole, pConnectionLabel);
    pConnectionTxt = new QLineEdit(pConnectionGrp);
    pConnectionTxt->setEnabled(false);
    pConnectionTxt->setAlignment(Qt::AlignCenter);
    pConnectionTxt->setReadOnly(true);
    pConnectionFormLayout->setWidget(0, QFormLayout::FieldRole, pConnectionTxt);
    pConnectionLabel->setText(QString::fromUtf8("Status:"));
    pConnectionTxt->setText(QString::fromUtf8("Not connected"));
    pMenuVerticalLayout->addWidget(pConnectionGrp);

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
