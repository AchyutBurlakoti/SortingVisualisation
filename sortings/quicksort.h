#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "sorting.h"
extern std::vector<int> random_number;

#include <iostream>

inline void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

inline bool less(int a, int b)
{
    return a < b;
}

inline int partition(int l, int r)
{
    int i = l - 1;
    int j = r;
    int v = random_number[r];

    for(;;)
    {
        while (less(random_number[++i], v));
        while (less(v, random_number[--j])) if (j == l) break;
        if (i >= j) break;
        swap(&random_number[i], &random_number[j]);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    swap(&random_number[i], &random_number[r]);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    return i;
}

inline void quickSort(int l, int r)
{
    if (l < r)
    {
        int i;
        i = partition(l, r);
        quickSort(l, i - 1);
        quickSort(i + 1, r);
    }
}

#endif // QUICKSORT_H
