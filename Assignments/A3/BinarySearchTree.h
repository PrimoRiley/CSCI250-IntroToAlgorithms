#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <cassert>
#include "BinaryTree.h"

using namespace std;

template<class T>
class BinarySearchTree : public BinaryTree<T>
{
    public:
        bool search(const T& searchItem) const;
        void insert(const T& insertItem);
        void deleteNode(const T& deleteItem);

    private:
        void deleteFromTree(nodeType<T>*& p);
};

//determine if item to be deleted is in the tree
template<class T>
bool BinarySearchTree<T>::search(const T& searchItem) const
{
    nodeType<T>* p = this->root;
    bool result;
    while (p != nullptr)
    {
        if(searchItem == p->info)
        {
            result = true;
            p = nullptr;
        }
        else if(searchItem < p->info)
        {
            p = p->llink;
        }
        else if(searchItem > p->info)
        {
            p = p->rlink;
        }
        else
        {
            result = false;
            break;
        }
    }
    

    return result;
}

//Insert item in Binary search tree
//PostCondition: if there is no node in the BST that has the same value
//a node with this data is created and inserted in the BST at the appropriate loc
template<class T>
void BinarySearchTree<T>::insert(const T& insertItem)
{
    if(this->root == nullptr)
    {
        this->root = new nodeType<T>;
        this->root->info = insertItem;
        this->root->llink = nullptr;
        this->root->rlink = nullptr;
    }
    else
    {
        nodeType<T>* parent = nullptr;//parent item
        nodeType<T>* p = this->root;//location for the new item
        while (p!= nullptr)
        {
            if(insertItem < p->info)
            {
                parent = p;
                p = p->llink;
            }
            else if(insertItem > p->info)
            {
                parent = p;
                p = p->rlink;
            }
            else//equal item ignore
                return;
        }

        if(insertItem < parent->info)
        {
            parent->llink = new nodeType<T>;
            parent->llink->info = insertItem;
            parent->llink->llink = nullptr;
            parent->llink->rlink = nullptr;
        }
        else if(insertItem>parent->info)
        {
            parent->rlink = new nodeType<T>;
            parent->rlink->info = insertItem;
            parent->rlink->llink = nullptr;
            parent->rlink->rlink = nullptr;
        }
    }
}
//function to delete an item from the BST,
//post condition: if a node with the same data item value is found it is deleted
//if not present or tree is empty an error message is displayed
template<class T>
void BinarySearchTree<T>::deleteNode(const T& deleteItem)
{
    nodeType<T>* p = this->root;
    while (p != nullptr)
    {
        if(deleteItem < p->info)
            p = p->llink;
        else if(deleteItem > p->info)
            p = p->rlink;
        else break;//deleteItem == p->info
    }
    if(p==nullptr)
    {
        cerr<<"Item is not in found in this data structure. "<<endl;
        return;
    }
    else
        deleteFromTree(p);//farm off the actual work to private function
}




template<class T>
void BinarySearchTree<T>::deleteFromTree(nodeType<T>*& p)
{
     nodeType<T>* parent = this->root;//parent to the node we need to delete
     while (parent->llink!= p && parent->rlink != p)
     {
         if(p->info < parent->info)
            parent = parent->llink;
         else if (p->info > parent->info)
            parent = parent->rlink;
         else
        {
            //p-> info == parent -> info which is to say we should be deleting the root p
            parent = nullptr;
            break;
        }
     }

     if(p->llink == nullptr)
     {
         //case 1 no left subtree
         if (parent==nullptr)
        {
            this->root = p->rlink;
        }
        else
        {
            //case 1b delete non root node with left subtree
            if(p->info < parent->info)
                parent->llink=p->rlink;
            else
                parent->rlink=p->rlink;
        }
        delete p;
     }
     else
     {
         //case 2: there is a left subtree
        nodeType<T>* rightMost = p->llink;//largest element of the left subtree
        nodeType<T>* parentOfRightMost = p;//keeping track of node above

        while(rightMost->rlink !=nullptr)
        {
             parentOfRightMost = rightMost;//keep track of node above
             rightMost = rightMost->rlink;
        }
         //swap the largest element in left sub tree for the node we wish to delete
        p->info = rightMost->info;
         //delete the rightmostnode
         //(largest element in the subtree which is now where p was)
        if(parentOfRightMost->rlink == rightMost)
        {
             //case 2a: largest element is not directly attached to p
             //rightmost should not have an rlink
             parentOfRightMost->rlink = rightMost->llink;
        }
        else
        {
            //parentOfRightMost->llink == rightMost
            //case 2b: largest element is directly attached to p
            parentOfRightMost->llink=rightMost->llink;
        }
        delete rightMost;
     }
}
#endif // BINARYSEARCHTREE_H
