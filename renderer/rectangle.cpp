#include "renderer/rectangle.h"

rectangle::rectangle()
{

}

void rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = return_dimension();
    Brush = QBrush(Qt::green);
    painter->fillRect(rec,Brush);
    painter->drawRect(rec);
}

QRectF rectangle::boundingRect() const
{
    return return_dimension();
}

QRectF rectangle::return_dimension() const
{
    return QRect(position_x, position_y, r_width, r_height);
}

void rectangle::setLocation(int xpos, int ypos)
{
    position_x = xpos;
    position_y = ypos;
}

void rectangle::setSize(int width, int height)
{
    r_width = width;
    r_height = height;
}

void rectangle::advance(int phase)
{
    if(!phase) return;
}
