
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char** argv)
{
    BinarySearchTree<long> tree;

    //make sure file name is recieved 
    if(argv[1] == NULL)
        cout<<"Re-run program and enter a file name to output data to..."<<endl;
    ofstream file;
    file.open(argv[1]); //open file and let user know
    cout<<argv[1]<<endl;
    
    srand(time(NULL)); //inialize random seed

    clock_t start, end; //initialize clock
    start = clock();
    long searchval;
    for(int i = 1; i<=100000; i++)
    {
        long rando = rand() % 100000000 + 99;
        tree.insert(rando);
        searchval = rando;
    }
    end = clock();
    
    file<<"-----BINARY SEARCH TREE-----"<<endl<<endl;
    double duration = double(end - start) / double(CLOCKS_PER_SEC);
    file<<"Time taken to create BST: "<<fixed<<duration<<setprecision(5);
    file<<" sec "<<endl;

    file<<"Is the tree empty? "; 
    if(tree.isEmpty() == 1)
        file<<"Yes"<<endl;
    else
        file<<"No"<<endl;

    file<<"Node Count: "<<tree.treeNodeCount()<<endl;
    file<<"Leaf Count: "<<tree.treeLeafCount()<<endl;
    file<<"Tree Height: "<<tree.treeHeight()<<endl;
   

    //search for element test
    long value = 2000000000;
    file<<"Search: Is element "<<searchval<<" in the BST?";
    if(tree.search(searchval) == 1)
        file<<" TRUE"<<endl;
    else
        file<<" FALSE"<<endl;

    file<<"Search: Is element "<<value<<" in the BST?";
    if(tree.search(value) == 1)
        file<<" TRUE"<<endl;
    else
        file<<" FALSE"<<endl;

    file<<"(tree is destroyed towards EOF)"<<endl;
    file<<endl<<endl<<"----TREE IN ORDER----"<<endl;
    tree.inOrderToFile(&file); 

    tree.destroyTree();
    file<<"Is the tree empty? "; 
    if(tree.isEmpty() == 1)
        file<<"Yes"<<endl;
    else
        file<<"No"<<endl;
    
}