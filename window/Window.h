#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QDesktopWidget>
#include <QApplication>
#include "renderer/renderer.h"

class Window : public QWidget
{
private:
    Window();
    static Window *sp_Window;
    renderer *_renderer;
public:
    static Window* GetWindow();
    void start();
    void stop();
public:
    int w_width;
    int w_height;
};

#endif // WINDOW_H
