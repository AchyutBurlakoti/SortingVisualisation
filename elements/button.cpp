#include "elements/button.h"
#include "window/Window.h"
extern Window *w;

button::button(QString str)
{
    b = new QPushButton(str);
    b->setStyleSheet("background-color: rgb(240,240,240)");
    b->setParent(w);
}

void button::setLocation(int xpos, int ypos)
{
    b->move(xpos, ypos);
}

void button::setSize(int width, int height)
{
    b->resize(width, height);
}
