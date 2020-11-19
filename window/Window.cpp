#include "window/Window.h"

Window *Window::sp_Window = nullptr;

Window::Window()
{
    w_width = QApplication::desktop()->screenGeometry().width();
    w_height = QApplication::desktop()->screenGeometry().height();
}

Window *Window::GetWindow()
{
    if (sp_Window == nullptr)
    {
        sp_Window = new Window();
    }
    return sp_Window;
}

void Window::start()
{
    _renderer = new renderer;
    _renderer->start();

    Window *w = Window::GetWindow();
    w->autoFillBackground();
    w->setWindowFlags(w->windowFlags() | Qt::CustomizeWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    w->setWindowState(w->windowState() | Qt::WindowMaximized);
    show();
}

void Window::stop()
{
    close();
}
