#include "elements/combobox.h"
#include "window/Window.h"
extern Window *w;

combobox::combobox()
{
    box = new QComboBox;
    box->setParent(w);
}

void combobox::setLocation(int xpos, int ypos)
{
    box->move(xpos, ypos);
}

void combobox::setSize(int width, int height)
{
    box->resize(width, height);
}

void combobox::addListItems(QStringList lst)
{
    box->addItems(lst);
}
