#pragma once
#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "rectangle.h"

class canvas
{
    QGraphicsView *view;
public:
    canvas();
    void disableScrollBar();
    void setSize(int xpos, int ypos, int width, int height);
    void addItem2scene(rectangle *rect);
    void clearScene();
public:
    QGraphicsScene *scene;
};

#endif // CANVAS_H
