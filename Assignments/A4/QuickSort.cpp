#include <iostream>
#include "QuickSort.h"
using namespace std;


int partition(vector<int>& list, int low, int high)
{
    int pivot = list[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (list[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(list[i], list[j]);
        }
    }
    swap(list[i + 1], list[high]);
    return (i + 1);
}

void quickSort(vector<int>& list, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(list, low, high);
        quickSort(list, low, partitionIndex - 1);
        quickSort(list, partitionIndex + 1, high);
    }
}