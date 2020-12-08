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
    if (str == "Quick3way Sort")
    {
        sortname = QUICK3WAY_SORT;
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
        case QUICK3WAY_SORT:
        {
            thread = std::async(std::launch::async, quick3Sort, 0, rectangle_number - 1);
            break;
        }
    }
}

void dimension_set()
{
    srand((unsigned) time(0));
    if(!random_number.empty()) random_number.clear();
    rectangle_number = canvas_width / rectangle_width;
    for (int i = 0; i < rectangle_number - 1; i++)
    {
        float n_random = (rand() % (canvas_height - 150)) + 1;
        if (i % 2 == 0) n_random = (rand() % (canvas_height / 2) + 1);
        random_number.push_back(n_random);
    }
}

template<typename T>
bool thread_is_finished(std::future<T> &t)
{
    return t.wait_for(std::chrono::seconds(0)) == std::future_status::ready;
}

void IsSortingCompleted()
{
    if(thread_is_finished(thread))
    {
        start_sorting = false;
    }
}
