#pragma once
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>


class rectangle : public QGraphicsItem
{
public:
    rectangle();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setLocation(int xpos, int ypos);
    void setSize(int width, int height);
    QRectF boundingRect() const;
    QRectF return_dimension() const;
protected:
    void advance(int phase);
private:
    QRect rect;
    QBrush Brush;
    uint16_t position_x;
    uint16_t position_y;
    uint16_t r_width;
    uint16_t r_height;
};

#endif // RECTANGLE_H
