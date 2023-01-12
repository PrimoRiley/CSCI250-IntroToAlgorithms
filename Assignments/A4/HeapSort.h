//
//  HeapSort.h
//  HeapSort
//
//  Created by Antoun, Sherine on 4/21/22.
//  Copyright © 2022 Antoun, Sherine. All rights reserved.
//

#ifndef HeapSort_h
#define HeapSort_h

#include <vector>
#include <stdio.h>
//make/remake heap
void heapify(std::vector<int>& list, int, int);

//heap sort
void heapSort(std::vector<int>& list, int);

// Print an array
void printArray(std::vector<int>& list, int );

#endif /* HeapSort_hpp */
