#ifndef QuickSort_h
#define QuickSort_h

#include <vector>
#include <stdio.h>

int partition(std::vector<int>& list, int low, int high);

void quickSort(std::vector<int>& list, int low, int high);

#endif 