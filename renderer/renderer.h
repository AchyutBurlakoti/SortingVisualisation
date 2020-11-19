#pragma once
#ifndef RENDERER_H
#define RENDERER_H

#include <QTimer>
#include "canvas.h"
#include "elements/widget.h"

class renderer : public QWidget
{
private:
    canvas *_canvas;
    QTimer *timer;
    widget *_widget;
public:
    renderer();
    void start();
    void drawrectangles();
};

#endif // RENDERER_H
