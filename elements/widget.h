#pragma once
#ifndef WIDGET_H
#define WIDGET_H

#include "elements/button.h"
#include "slider.h"
#include "combobox.h"
#include <QWidget>
#include <QString>

class widget : public QWidget
{
private:
    button *start_button;
    button *quit_button;
    button *reset_button;
    slider *s_slider;
    combobox *box;
public:
    widget();
    void connection();
    void w_reset();
    void w_sort();
    void text(const QString &t);
};

#endif // WIDGET_H
