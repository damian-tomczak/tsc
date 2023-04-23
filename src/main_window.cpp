#include "main_window.h"

MainWindow::MainWindow(QWidget* pParent) : QMainWindow(pParent)
{
    mUi.setup(this);
}

MainWindow::~MainWindow()
{
    // TODO: mUi.cleanup();
}

void MainWindow::on_FileOpen_triggered()
{
    std::cout << "Fileopen\n";
}

void MainWindow::on_About_triggered()
{
    std::cout << "About\n";
}
