#ifndef MERGESORT_H
#define MERGESORT_H

#include "sorting.h"
#include "iostream"
extern std::vector<int> random_number;
extern uint16_t rectangle_number;

inline void swapping(int &a, int &b)
{    
   //swap the content of a and b
   int temporary;
   temporary = a;
   a = b;
   b = temporary;
}

inline void merge(int l, int m, int r) 
{
   int i, j, k, nl, nr;

   //size of left and right sub-arrays
   nl = m-l+1; nr = r-m;

   int larr[nl], rarr[nr];

   //fill left and right sub-arrays
   for(i = 0; i<nl; i++)
      larr[i] = random_number[l+i];

   for(j = 0; j<nr; j++)
      rarr[j] = random_number[m+1+j];

   i = 0; j = 0; k = l;

   //marge temp arrays to real array
   while(i < nl && j<nr)
   {
      if(larr[i] <= rarr[j]) 
      {
         random_number[k] = larr[i];
         i++;
      }
      else
      {
         random_number[k] = rarr[j];
         j++;
      }
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      k++;
   }
   while(i<nl) 
   {       //extra element in left array
      random_number[k] = larr[i];
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
      i++; k++;
   }
   while(j<nr) 
   {     //extra element in right array
      random_number[k] = rarr[j];
      std::this_thread::sleep_for(std::chrono::milliseconds(10));
      j++; k++;
   }
   start_sorting = true;
}
inline void mergeSort(int l, int r) 
{
   int m;
   if(l < r)
   {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      start_sorting = true;
      mergeSort(l, m);
      mergeSort(m+1, r);
      merge(l, m, r);
   }
}

#endif // MERGESORT_H
