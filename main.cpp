#include <QApplication>
#include <QDesktopWidget>

#include "window/Window.h"

Window *w;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    w = Window::GetWindow();

    w->start();

    return app.exec();
}
