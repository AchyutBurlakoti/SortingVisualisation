#ifndef SORTING_H
#define SORTING_H
#include <future>
#include <vector>
#include <QString>
#include "sortings/bubblesort.h"
#include "sortings/mergesort.h"
#include "sortings/quicksort.h"
#include "sortings/quick3sort.h"

enum sortType
{
    BUBBLE_SORT,
    MERGE_SORT,
    QUICK_SORT,
    QUICK3WAY_SORT
};

extern sortType sortname;

extern std::vector<int> random_number;

extern uint16_t rectangle_width;
extern uint16_t rectangle_number;
extern uint16_t canvas_width;
extern uint16_t canvas_height;

extern bool start_sorting;

extern std::future<void> thread;

void SelectSort(const QString str);
void StartSorting();
void dimension_set();

template<typename T>
bool thread_is_finished(std::future<T> &t);
void IsSortingCompleted();
#endif // SORTING_H
