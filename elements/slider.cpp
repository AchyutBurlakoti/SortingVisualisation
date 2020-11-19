#include "elements/slider.h"
#include "window/Window.h"
#include "sorting.h"
extern Window *w;
extern uint16_t rectangle_width;

slider::slider(int value)
{
    s = new QSlider(Qt::Horizontal);
    s->setParent(w);
}

void slider::setLocation(int xpos, int ypos)
{
    s->move(xpos, ypos);
}

void slider::setSize(int width, int height)
{
    s->resize(width, height);
}

void slider::setRange(int to, int from)
{
    s->setRange(to, from);
}

void slider::connection()
{
    connect(s, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));
}

void slider::setValue(int value)
{
    rectangle_width = (value / 10) + 1;
    dimension_set();
}
