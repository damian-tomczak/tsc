#pragma once

#include "ui.h"

#include <QMainWindow>

#include <iostream>

class MainWindow final : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui mUi{};

private slots:
    void on_FileOpen_triggered();
    void on_About_triggered();
};