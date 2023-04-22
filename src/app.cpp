#include "app.h"

App::App(QWidget* pParent) : QMainWindow(pParent)
{
    mUi.setup(this);
}

App::~App()
{
    // TODO: mUi.cleanup();
}
