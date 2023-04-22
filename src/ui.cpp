#include "ui.h"

void Ui::setup(QMainWindow* pMainWindow)
{
    pMainWindow->resize(1280, 720);

    pCentralWidget = new QWidget(pMainWindow);
    pMainWindow->setCentralWidget(pCentralWidget);

    centralHorizontalLayout = new QHBoxLayout(pCentralWidget);

    setupMenu();
    centralHorizontalLayout->addWidget(menuGrp);

    setupProgram();
    centralHorizontalLayout->addWidget(programGrp);
}

void Ui::setupMenu()
{
    menuGrp = new QGroupBox(pCentralWidget);
    menuGrp->setTitle(QString::fromUtf8("Menu"));
    menuVerticalLayout = new QVBoxLayout(menuGrp);

    connectionGrp = new QGroupBox(menuGrp);
    connectionGrp->setTitle(QString::fromUtf8("Connection"));
    connectionFormLayout = new QFormLayout(connectionGrp);
    connectionLabel = new QLabel(connectionGrp);
    connectionFormLayout->setWidget(0, QFormLayout::LabelRole, connectionLabel);
    connectionTxt = new QLineEdit(connectionGrp);
    connectionTxt->setEnabled(false);
    connectionTxt->setAlignment(Qt::AlignCenter);
    connectionTxt->setReadOnly(true);
    connectionFormLayout->setWidget(0, QFormLayout::FieldRole, connectionTxt);
    connectionLabel->setText(QString::fromUtf8("Status:"));
    connectionTxt->setText(QString::fromUtf8("Not connected"));
    menuVerticalLayout->addWidget(connectionGrp);

    stateGrp = new QGroupBox(menuGrp);
    stateGrp->setTitle(QString::fromUtf8("State"));
    stateVerticalLayout = new QVBoxLayout(stateGrp);
    stateLabel = new QLabel(stateGrp);
    stateLabel->setText(QString::fromUtf8("Coordinates:"));
    stateVerticalLayout->addWidget(stateLabel);
    stateHorizontalLayout = new QHBoxLayout();
    posXtxt = new QLineEdit(stateGrp);
    posXtxt->setText(QString::fromUtf8("0"));
    posXtxt->setAlignment(Qt::AlignCenter);
    posXtxt->setReadOnly(true);
    stateHorizontalLayout->addWidget(posXtxt);
    posYtxt = new QLineEdit(stateGrp);
    posYtxt->setText(QString::fromUtf8("0"));
    posYtxt->setAlignment(Qt::AlignCenter);
    posYtxt->setReadOnly(true);
    stateHorizontalLayout->addWidget(posYtxt);
    posZtxt = new QLineEdit(stateGrp);
    posZtxt->setAlignment(Qt::AlignCenter);
    posZtxt->setReadOnly(true);
    posZtxt->setText(QString::fromUtf8("0"));
    stateHorizontalLayout->addWidget(posZtxt);
    stateVerticalLayout->addLayout(stateHorizontalLayout);
    menuVerticalLayout->addWidget(stateGrp);

    consoleGrp = new QGroupBox(menuGrp);
    consoleGrp->setTitle(QString::fromUtf8("Console"));
    consoleVerticalLayout = new QVBoxLayout(consoleGrp);
    consoleOutputTxt = new QPlainTextEdit(consoleGrp);
    consoleVerticalLayout->addWidget(consoleOutputTxt);
    consoleHorizontalLayout = new QHBoxLayout();
    consoleCmdTxt = new QLineEdit(consoleGrp);
    consoleHorizontalLayout->addWidget(consoleCmdTxt);
    consoleButton = new QPushButton(consoleGrp);
    consoleButton->setText(QString::fromUtf8(">"));
    consoleHorizontalLayout->addWidget(consoleButton);
    consoleVerticalLayout->addLayout(consoleHorizontalLayout);
    menuVerticalLayout->addWidget(consoleGrp);
}

void Ui::setupProgram()
{
    programGrp = new QGroupBox(pCentralWidget);
    programGrp->setTitle(QString::fromUtf8("Program"));
    programVerticalLayout = new QVBoxLayout(programGrp);

    graph = new Graph(programGrp);
    programVerticalLayout->addWidget(graph);

    programTbl = new QTableView(programGrp);
    programVerticalLayout->addWidget(programTbl);
}
