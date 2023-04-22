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

struct Ui final
{
    void setup(QMainWindow* pMainWindow);
    // TODO: void cleanup();

    QWidget* pCentralWidget;
    QHBoxLayout* centralHorizontalLayout;

    QGroupBox* menuGrp;
    QVBoxLayout* menuVerticalLayout;

    QGroupBox* connectionGrp;
    QFormLayout* connectionFormLayout;
    QLabel* connectionLabel;
    QLineEdit* connectionTxt;

    QGroupBox* stateGrp;
    QVBoxLayout* stateVerticalLayout;
    QLabel* stateLabel;

    QHBoxLayout* stateHorizontalLayout;
    QLineEdit* posXtxt;
    QLineEdit* posYtxt;
    QLineEdit* posZtxt;

    QGroupBox* consoleGrp;
    QVBoxLayout* consoleVerticalLayout;
    QPlainTextEdit* consoleOutputTxt;
    QHBoxLayout* consoleHorizontalLayout;
    QLineEdit* consoleCmdTxt;
    QPushButton* consoleButton;

    QGroupBox* programGrp;
    QVBoxLayout* programVerticalLayout;
    Graph* graph;
    QTableView* programTbl;

private:
    void setupMenu();
    void setupProgram();
};