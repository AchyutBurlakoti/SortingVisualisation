#ifndef QUICK3SORT_H
#define QUICK3SORT_H
#include "sorting.h"
extern std::vector<int> random_number;

#include <iostream>

inline void swap3(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

inline bool less3(int a, int b)
{
    return a < b;
}

inline std::pair<int, int> partition3(int l, int r)
{
    int i = l - 1;
    int j = r;
    int v = random_number[r];
    int p = l - 1;
    int q = r;
    int k;

    for(;;)
    {
        while (less3(random_number[++i], v));
        while (less3(v, random_number[--j]))
        {
            if (j == l) break;
        }

        if (i >= j) break;

        swap3(&random_number[i], &random_number[j]);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        if (random_number[i] == v)
        {
            p++;
            swap3(&random_number[p], &random_number[i]);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }

        if (v == random_number[j])
        {
            q--;
            swap3(&random_number[q], &random_number[j]);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }

    swap3(&random_number[i], &random_number[r]);
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    j = i - 1;
    i = i + 1;
    for (k = l; k < p; k++, j--)
    {
        swap3(&random_number[k], &random_number[j]);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    for (k = r - 1; k > q; k--, i++)
    {
        swap3(&random_number[k], &random_number[i]);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    return std::pair<int, int>(i, j);
}

inline void quick3Sort(int l, int r)
{
    if (l < r)
    {
        std::pair<int, int> i;
        i = partition3(l, r);
        quick3Sort(l, i.second);
        quick3Sort(i.first, r);
    }
}
#endif // QUICK3SORT_H
