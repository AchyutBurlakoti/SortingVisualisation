#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "sorting.h"
extern std::vector<int> random_number;
extern bool start_sorting;

inline void bubbleSort()
{
    int i, j;
    for (i = 0; i < (int)random_number.size(); i++)
    {
        // Last i elements are already in place
        for (j = 0; j < (int)random_number.size() - i; j++)
        {
            if (random_number[j] > random_number[j+1])
            {
                int temp = random_number[j];
                random_number[j] = random_number[j+1];
                random_number[j+1] = temp;
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        }
    }
}

#endif // BUBBLESORT_H
