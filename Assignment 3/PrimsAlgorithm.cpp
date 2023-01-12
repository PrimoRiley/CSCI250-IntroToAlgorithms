/*
Code by Kelly Jo Law
*/

#include <iostream>
#include <chrono>
using namespace std;

// given that our graph has 10 vertices
#define Vertices 10
 
// print MST edge list
void printMST(int root[], int matrix[Vertices][Vertices])
{
    cout << "The edge list for this minimum spanning tree is: " << endl;
    cout << "Edge    Weight" << endl;
    for (int i = 1; i < Vertices; i++) {
        cout << root[i] << " - " << i << " \t" << matrix[i][root[i]] << " \n"; 
    }
} 
// find vertex with minimum key 
int minimumKey(int key[], bool mstEdgeSet[])
{
    int min = 100000;
    int minIndex;
 
    for (int i = 0; i < Vertices; i++) {
        if (mstEdgeSet[i] == false && key[i] < min) {
            min = key[i], minIndex = i;
        }
    } 
    return minIndex;
}
// construct MST using adjacency matrix
void mstMake(int matrix[Vertices][Vertices])
{
    bool mstSet[Vertices];
    int key[Vertices];
    int root[Vertices];

    for (int i = 0; i < Vertices; i++) {
        key[i] = 100000, mstSet[i] = false;
    }
    
    key[0] = 0;
    root[0] = -1;

    int counter;
    for (counter = 0; counter < Vertices - 1; counter++) {
        int u = minimumKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < Vertices; v++)
            if (matrix[u][v] && mstSet[v] == false && matrix[u][v] < key[v]) {
                root[v] = u, key[v] = matrix[u][v];
            }
    }
    printMST(root, matrix);
    cout << "Number of comparisons: " << counter << endl;
}
// Driver code 
int main()
{
    chrono::time_point<chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    int adMatrix[Vertices][Vertices] = { { 0, 6, 10, 0, 0, 0, 0, 0, 0, 0 },
                                        { 6, 0, 12, 11, 14, 0, 0, 0, 0, 0 },
                                        { 10, 12, 0, 12, 0, 0, 8, 16, 0, 0 },
                                        { 0, 11, 12, 0, 0, 6, 3, 0, 0, 0 },
                                        { 0, 14, 0, 0, 0, 4, 0, 0, 6, 0 }, 
                                        { 0, 0, 0, 6, 4, 0, 0, 0, 12, 0 },
                                        { 0, 0, 8, 3, 0, 0, 0, 0, 16, 6 },
                                        { 0, 0, 16, 0, 0, 0, 0, 0, 0, 8 },
                                        { 0, 0, 0, 0, 6, 12, 16, 0, 0, 13 },
                                        { 0, 0, 0, 0, 0, 0, 6, 8, 13, 0 }
                                        };
    mstMake(adMatrix);
 
    end = chrono::system_clock::now();
    chrono::duration<double> elapsed_seconds = end - start;

    cout <<"Runtime: "<< elapsed_seconds.count() << endl;

    return 0;
}