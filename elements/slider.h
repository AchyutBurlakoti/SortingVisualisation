#ifndef SLIDER_H
#define SLIDER_H

#include <QSlider>
#include <QPainter>

class slider : public QWidget
{
    Q_OBJECT
public:
    QSlider *s;
    slider(int value);
    void setRange(int to, int from);
    void connection();
    void setLocation(int xpos, int ypos);
    void setSize(int width, int height);
signals:
    void valueChanged(int value);

public slots:
    void setValue(int value);
};

#endif // SLIDER_H
