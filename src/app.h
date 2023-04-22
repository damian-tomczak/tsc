#pragma once

#include <QMainWindow>

class App final : public QMainWindow
{
    Q_OBJECT

public:
    explicit App(QWidget* parent = nullptr);
    ~App();
};