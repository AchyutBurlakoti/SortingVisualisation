#pragma once
#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QComboBox>
#include <QStringList>

class combobox
{
public:
    QComboBox *box;
    combobox();
    void setLocation(int xpos, int ypos);
    void setSize(int width, int height);
    void addListItems(QStringList lst);
};
#endif // COMBOBOX_H
