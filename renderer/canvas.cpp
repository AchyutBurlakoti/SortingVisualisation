#include "renderer/canvas.h"
#include "window/Window.h"
#define reduce 55

extern Window *w;

canvas::canvas()
{
    // create scene
    scene = new QGraphicsScene;

    // view
    view = new QGraphicsView(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setParent(w);
}

void canvas::disableScrollBar()
{
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void canvas::setSize(int xpos, int ypos, int width, int height)
{
    view->setFixedSize(width, height);
    scene->setSceneRect(xpos, ypos, width, height);
}

void canvas::addItem2scene(rectangle *rect)
{
    scene->addItem(rect);
}

void canvas::clearScene()
{
    scene->clear();
}
