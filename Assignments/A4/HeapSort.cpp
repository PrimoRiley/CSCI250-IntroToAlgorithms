//
//  HeapSort.cpp
//  HeapSort
//
//  Created by Antoun, Sherine on 4/21/22.
//  Copyright © 2022 Antoun, Sherine. All rights reserved.
//
#include <iostream>
#include "HeapSort.h"
using namespace std;

void heapify(vector<int>& list, int n, int i) {
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && list[left] > list[largest])
        largest = left;
    
    if (right < n && list[right] > list[largest])
        largest = right;
    
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(list[i], list[largest]);
        heapify(list, n, largest);
    }
}

// main function to do heap sort
void heapSort(vector<int>& list, int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(list, n, i);
    
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        swap(list[0], list[i]);
        
        // Heapify root element to get highest element at root again
        heapify(list, i, 0);
    }
}

// Print an array
void printArray(vector<int>& list, int n) {
    for (int i = 0; i < n; ++i)
        cout << list[i] << " ";
    cout << "\n";
}
