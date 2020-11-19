#include "elements/widget.h"
#include "window/Window.h"
#include "sorting.h"

extern Window *w;
extern bool start_sorting;
extern bool terminate_thread;

widget::widget()
{
    start_button = new button("start");
    quit_button = new button("quit");
    reset_button = new button("reset");
    s_slider = new slider(1);
    box = new combobox;

    start_button->setLocation(w->w_width - 150, 150);
    start_button->setSize(100, 30);
    reset_button->setLocation(w->w_width - 150, 350);
    reset_button->setSize(100, 30);
    quit_button->setLocation(w->w_width - 150, 550);
    quit_button->setSize(100, 30);

    s_slider->setLocation(w->w_width - 170, 30);
    s_slider->setRange(1, 110);
    s_slider->setSize(150, 20);
    s_slider->setValue(1);

    box->setSize(150, 25);
    box->addListItems({ "Bubble Sort", "Quick Sort", "Merge Sort", "Insertion Sort" , "Selection Sort", "Radix Sort", "Shell Sort"});
    box->setLocation(w->w_width - 170, 60);
}

void widget::w_reset()
{
    //if(!start_sorting)
    //{
        dimension_set();
    //}
}

void widget::w_sort()
{
    start_sorting = true;
    StartSorting();
}

void widget::text(const QString &t)
{
    SelectSort(t);
}

void widget::connection()
{
    s_slider->connection();
    connect(start_button->b, &QPushButton::clicked, this, &widget::w_sort);
    connect(reset_button->b, &QPushButton::clicked, this, &widget::w_reset);
    connect(quit_button->b, &QPushButton::clicked, w, &QWidget::close);
    connect(box->box, &QComboBox::currentTextChanged, this, &widget::text);
}
