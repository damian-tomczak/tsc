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
    QMessageBox::information(this, "About",
        "Simple GRBL Controller made for Michelin Olsztyn\n"
        "as the part of the University of Warmia and Mazury assingment project\n\n"
        "Authors: Damian Tomczak, Dominik Slodkowski, Szymon Chura");
}
