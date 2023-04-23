#pragma once

#include "ui.h"
#include "grbl_ctrl.h"

#include <QMainWindow>
#include <QMessageBox>

#include <iostream>

class MainWindow final : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui mUi{};
    GrblCtrl mGrblCtrl;

private slots:
    void on_Connect_clicked();
    void on_FileOpen_triggered();
    void on_About_triggered();
    void on_BaudRefresh_clicked();
};