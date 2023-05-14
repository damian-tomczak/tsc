#pragma once

#include "graph.h"

#include <QMainWindow>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QComboBox>

struct Ui final
{
    void setup(QMainWindow* pMainWindow);

    QWidget* pCentralWidget;
    QHBoxLayout* pCentralHorizontalLayout;

    QGroupBox* pSideGrp;
    QVBoxLayout* pSideVerticalLayout;

    QGroupBox* pConnGrp;
    QVBoxLayout* pConnVerticalLayout;
    QFormLayout* pConnFormLayout;
    QLabel* pConnStatusLabel;
    QLineEdit* pConnStatus;
    QHBoxLayout* pConnHorizontalLayoutParams;
    QLabel* pConnPortLabel;
    QComboBox* pConnPortCbo;
    QToolButton* pConnButtonRefresh;
    QLabel* pConnBaudLabel;
    QComboBox* pConnBaudCbo;
    QHBoxLayout* pConnHorizontalLayoutActions;
    QToolButton* pConnBtnConnect;
    QToolButton* pConnBtnStop;
    QHBoxLayout* pSendHLayoutActs;
    QToolButton* pConnBtnSend;

    QGroupBox* pStateGrp;
    QVBoxLayout* pStateVerticalLayout;
    QLabel* pStateLabel;

    QHBoxLayout* pStateHorizontalLayout;
    QLineEdit* pStatePosXtxt;
    QLineEdit* pStatePosYtxt;
    QLineEdit* pStatePosZtxt;

    QGroupBox* pConsoleGrp;
    QVBoxLayout* pConsoleVerticalLayout;
    QPlainTextEdit* pConsoleOutputTxt;
    QHBoxLayout* pConsoleHorizontalLayout;
    QLineEdit* pConsoleCmdTxt;
    QPushButton* pConBtn;

    QGroupBox* pProgramGrp;
    QVBoxLayout* pProgramVerticalLayout;
    Graph* pGraph;
    QTableView* pProgramTbl;

    QAction* pFileOpenAct;
    QAction* pAboutAct;
    QAction* pConstraintsAct;

    QMenuBar* pMenuBar;
    QMenu* pMenuFile;
    QMenu* pMenuHelp;

private:
    void setupBar(QMainWindow* pMainWindow);
    void setupSide();
    void setupProgram();
};