#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "sorting.h"
extern std::vector<int> random_number;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int low, int high)
{
    int pivot = random_number[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (random_number[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&random_number[i], &random_number[j]);
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
    swap(&random_number[i + 1], &random_number[high]);
    return (i + 1);
}

void quickSort(int low, int high)
{
    if (low < high)
    {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

#endif // QUICKSORT_H
