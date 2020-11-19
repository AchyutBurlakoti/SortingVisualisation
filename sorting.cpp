#include "sorting.h"

sortType sortname = BUBBLE_SORT;

std::vector<int> random_number;
uint16_t rectangle_width;
uint16_t rectangle_number;
uint16_t canvas_width;
uint16_t canvas_height;

std::future<void> thread;

bool start_sorting = false;

void SelectSort(const QString str)
{
    if (str == "Bubble Sort")
    {
        sortname = BUBBLE_SORT;
    }
    if (str == "Merge Sort")
    {
        sortname = MERGE_SORT;
    }
    if (str == "Quick Sort")
    {
        sortname = QUICK_SORT;
    }
}

void StartSorting()
{
    switch (sortname)
    {
        case BUBBLE_SORT:
        {
            thread = std::async(std::launch::async, bubbleSort);
            break;
        }
        case QUICK_SORT:
        {
            thread = std::async(std::launch::async, quickSort, 0, rectangle_number - 1);
            break;
        }
        case MERGE_SORT:
        {
            thread = std::async(std::launch::async, mergeSort, 0, rectangle_number - 1);
            break;
        }

    }
}

void dimension_set()
{
    if(!random_number.empty()) random_number.clear();
    rectangle_number = canvas_width / rectangle_width;
    for (int i = 0; i < rectangle_number; i++)
    {
        float n_random = (qrand() % 10) * (qrand() % 10) * (qrand() % 10);
        if(n_random == 0) n_random = (qrand() % 10) * (qrand() % 10) * (qrand() % 10);
        if(n_random == 0) n_random = (qrand() % 10) * (qrand() % 10) * (qrand() % 10);
        if(n_random == 0) n_random = (qrand() % 10) * (qrand() % 10) * (qrand() % 10);
        if(n_random == 0) n_random = (qrand() % 10) * (qrand() % 10) * (qrand() % 10);
        if(n_random == 0) n_random = (qrand() % 10) * (qrand() % 10) * (qrand() % 10);
        if(n_random == 0) n_random = (qrand() % 10) * (qrand() % 10) * (qrand() % 10);
        if(n_random == 0) n_random = (qrand() % 10) * (qrand() % 10) * (qrand() % 10);
        if(n_random == 0) n_random = (qrand() % 10) * (qrand() % 10) * (qrand() % 10);
        random_number.push_back(n_random);
    }
}
