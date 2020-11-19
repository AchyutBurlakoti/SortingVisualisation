#pragma once
#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton.h>
#include <QStyleFactory>
#include <QString>

class button
{
public:
    QPushButton *b;
    QPalette newPalette;
    button(QString str);
    void setLocation(int xpos, int ypos);
    void setSize(int width, int height);
};

#endif // BUTTON_H
