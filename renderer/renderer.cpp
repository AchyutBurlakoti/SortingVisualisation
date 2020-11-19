#include "renderer/renderer.h"
#include "window/Window.h"
#include "sorting.h"

extern Window *w;

extern uint16_t canvas_width;
extern uint16_t canvas_height;
extern uint16_t rectangle_width;
extern uint16_t rectangle_number;
extern std::vector<int> random_number;

renderer::renderer()
{
    _canvas = new canvas;
    _widget = new widget;

    timer = new  QTimer;
    connect(timer, &QTimer::timeout, this, &renderer::drawrectangles);
    timer->start(5);

    canvas_width = w->w_width - 200;
    canvas_height = w->w_height - 55;
}

void renderer::start()
{
    _canvas->disableScrollBar();
    _canvas->setSize(0, 0, w->w_width - 200, w->w_height - 55);
    _widget->connection();
    dimension_set();
    drawrectangles();
}

void renderer::drawrectangles()
{
    _canvas->clearScene();
    for(int i = 0; i < rectangle_number; i++)
    {
        rectangle *_rectangle = new rectangle;
        _rectangle->setLocation(i * rectangle_width, canvas_height - random_number[i] - 4);
        _rectangle->setSize(rectangle_width, random_number[i]);
        _canvas->addItem2scene(_rectangle);
    }
}
