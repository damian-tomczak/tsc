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
    // TODO: void cleanup();

    QWidget* pCentralWidget;
    QHBoxLayout* pCentralHorizontalLayout;

    QGroupBox* pMenuGrp;
    QVBoxLayout* pMenuVerticalLayout;

    QGroupBox* pConnGrp;
    QVBoxLayout* pConnVerticalLayout;
    QFormLayout* pConnFormLayout;
    QLabel* pConnDecorationLabel;
    QLineEdit* pConnTxt;
    QHBoxLayout* pConnHorizontalLayout;
    QLabel* pConnPortLabel;
    QComboBox* pConnPortCbo;
    QToolButton* pConnButtonRefresh;
    QLabel* pConnBaudLabel;
    QComboBox* pConnBaudCbo;
    QToolButton* pConnButtonConnect;

    QGroupBox* pStateGrp;
    QVBoxLayout* pStateVerticalLayout;
    QLabel* pStateLabel;

    QHBoxLayout* pStateHorizontalLayout;
    QLineEdit* pPosXtxt;
    QLineEdit* pPosYtxt;
    QLineEdit* pPosZtxt;

    QGroupBox* pConsoleGrp;
    QVBoxLayout* pConsoleVerticalLayout;
    QPlainTextEdit* pConsoleOutputTxt;
    QHBoxLayout* pConsoleHorizontalLayout;
    QLineEdit* pConsoleCmdTxt;
    QPushButton* pConsoleButton;

    QGroupBox* pProgramGrp;
    QVBoxLayout* pProgramVerticalLayout;
    Graph* pGraph;
    QTableView* pProgramTbl;

private:
    void setupMenu();
    void setupProgram();
};