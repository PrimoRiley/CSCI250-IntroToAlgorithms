#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <iostream>

using namespace std;

//T: datatype of the element of the nodes in the tree
template<class T>
struct nodeType
{
    T info;    //data
    nodeType<T>* llink;  //left subtree
    nodeType<T>* rlink;  //right subtree
};
template<class T>
class BinaryTree
{
    public:
        //assignment
        const BinaryTree<T>& operator =(const BinaryTree<T>& otherTree);

        //height - node and leaf counters
        bool isEmpty() const;
        int treeHeight() const;
        int treeNodeCount() const;
        int treeLeafCount() const;

        //traversals
        void inOrderTraversal() const;
        void inOrderToFile(ofstream*) const;
        void postOrderTraversal() const;
        void preOrderTraversal() const;

        //parameterized traversals will actually do the work
        //parameter visit specifies the actual action taken at each node
        void inOrderTraversal(void(*visit)(T& item)) const;
        void preOrderTraversal(void(*visit)(T& item)) const;
        void postOrderTraversal(void(*visit)(T& item)) const;


        void destroyTree();  //deallocate space for each node


        BinaryTree();
        BinaryTree(const BinaryTree<T>& otherTree);
        ~BinaryTree();

    protected:
        nodeType<T>* root;

    private:
        //comparisons
        int height(nodeType<T>* p) const;
        int nodeCount(nodeType<T>* p) const;
        void nodeCount(nodeType<T>* p, int& count) const;
        int leafCount(nodeType<T>* p)const;
        void leafCount(nodeType<T>* p, int& count)const;

        //copy & destroy
        void copyTree(nodeType<T>*& copiedTreeRoot, nodeType<T>* otherTreeRoot);
        void destroy(nodeType<T>*& p);

        //traversals
        void inOrder(nodeType<T>* p) const;
        void inOrderFile(nodeType<T>*, ofstream*) const;
        void postOrder(nodeType<T>* p) const;
        void preOrder(nodeType<T>* p) const;

        //paramaterized traversals will actually do the work
        //paraamater visit specifies the actual action taken at each node
        void inOrder(nodeType<T>* p, void(*visit)(T& item)) const;
        void postOrder(nodeType<T>* p, void(*visit)(T& item)) const;
        void preOrder(nodeType<T>* p, void(*visit)(T& item)) const;

        
};

//PUBLIC//
//assignment
template<class T>
const BinaryTree<T>& BinaryTree<T>::operator =(const BinaryTree<T>& otherTree)
{
    if(this != &otherTree)
    {
        if(root != nullptr)
            destroy(root);
        if(otherTree.root == nullptr)
            root = nullptr;
        else
            copyTree(root, otherTree.root);
    }
    return *this;
}

//height and node & leaf counters
template<class T>
bool BinaryTree<T>::isEmpty() const
{
    return (root == nullptr);
}

template<class T>
int BinaryTree<T>::treeHeight() const
{
    return height(root);
}

template<class T>
int BinaryTree<T>::treeNodeCount() const
{
    return nodeCount(root);
}
template<class T>
int BinaryTree<T>::treeLeafCount() const
{
    return leafCount(root);
}

//traversals
template<class T>
void BinaryTree<T>::inOrderTraversal() const
{
    inOrder(root);
}


template<class T>
void BinaryTree<T>::inOrderToFile(ofstream* file) const
{
    inOrderFile(root, file);
}


template<class T>
void BinaryTree<T>::postOrderTraversal() const
{
    postOrder(root);
}

template<class T>
void BinaryTree<T>::preOrderTraversal() const
{
    preOrder(root);
}


//parameterized traversals
template<class T>
void BinaryTree<T>::inOrderTraversal(void(*visit)(T& item)) const
{
    inOrder(root, *visit);
}

template<class T>
void BinaryTree<T>::preOrderTraversal(void(*visit)(T& item)) const
{
    preOrder(root, *visit);
}

template<class T>
void BinaryTree<T>::postOrderTraversal(void(*visit)(T& item)) const
{
    postOrder(root, *visit);
}

//constructors & destructors
template<class T>
void BinaryTree<T>::destroyTree()
{
    destroy(root);
}

template<class T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
    destroy(root);
}

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& otherTree)
{
    if(otherTree.root == nullptr)
        root = nullptr;
    else
        copyTree(root, otherTree.root);
}

//PRIVATE
//comparisons
template<class T>
int BinaryTree<T>::height(nodeType<T>* p) const
{
    if(p == nullptr)
    {
        return 0;
    }
    else
    {
        int lheight = height(p->llink);
        int rheight = height(p->rlink);
        if(lheight >= rheight)
            return lheight + 1;
        else
            return rheight + 1;
    }
    
}

template<class T>
int BinaryTree<T>::nodeCount(nodeType<T>* p) const
{
    /*
    if(p == nullptr)
        return 0;
    return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
    */
   int count = 0;
   nodeCount(p, count);
   return count;
}

template<class T>
void BinaryTree<T>::nodeCount(nodeType<T>* p, int& count) const
{
    if(p != nullptr)
    {
        count++;
        nodeCount(p->llink, count);
        nodeCount(p->rlink, count);
    }
}

template<class T>
int BinaryTree<T>::leafCount(nodeType<T>* p) const
{
    int count = 0;
    leafCount(p, count);
    return count;
}

template<class T>
void BinaryTree<T>::leafCount(nodeType<T>* p, int& count)const
{
    if(p!= nullptr)
    {
        leafCount(p->llink, count);
        leafCount(p->rlink, count);
        if(p->llink==nullptr && p->rlink==nullptr)
            count++;
    }
}

//traversals 
template<class T>
void BinaryTree<T>::inOrder(nodeType<T>* p) const
{
    if(p !=nullptr)
    {
        inOrder(p->llink);
        cout<<p->info<<" ";
        inOrder(p->rlink);
    }
}

template<class T>
void BinaryTree<T>::inOrderFile(nodeType<T>* p, ofstream* file) const
{
    if(p !=nullptr)
    {  
        inOrderFile(p->llink, file);
        (*file)<<p->info<<'\t';
        inOrderFile(p->rlink, file);
        if(p->info > 1)
            (*file)<<endl;
    }
    
}

template<class T>
void BinaryTree<T>::postOrder(nodeType<T>* p) const
{
    if(p != nullptr)
    {
        postOrder(p->llink);
        postOrder(p->rlink);
        cout<<p->info<<" ";
    }
}
template<class T>
void BinaryTree<T>::preOrder(nodeType<T>* p) const
{
    if(p != nullptr)
    {
        cout<<p->info<<" ";
        preOrder(p->llink);
        preOrder(p->rlink);
    }
}

//parameterized taversals
template<class T>
void BinaryTree<T>::inOrder(nodeType<T>* p, void(*visit)(T& item)) const
{
    if(p != nullptr)
    {
        inOrder(p->llink, *visit);
        (*visit)(p->info);
        inOrder(p->rlink, *visit);
    }
}

template<class T>
void BinaryTree<T>::postOrder(nodeType<T>* p, void(*visit)(T& item)) const
{
    if(p != nullptr)
    {
        inOrder(p->llink, *visit);
        inOrder(p->rlink, *visit);
        (*visit)(p->info);
    }
}

template<class T>
void BinaryTree<T>::preOrder(nodeType<T>* p, void(*visit)(T& item)) const
{
    if(p != nullptr)
    {
        (*visit)(p->info);
        inOrder(p->llink, *visit);
        inOrder(p->rlink, *visit);
    }
}

//copy and destroy
template<class T>
void BinaryTree<T>::destroy(nodeType<T>*& p)
{
    if(p!=nullptr)
    {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = nullptr;
    }
}

template<class T>
void BinaryTree<T>::copyTree(nodeType<T>*& copiedTreeRoot, nodeType<T>* otherTreeRoot)
{
    if(otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new nodeType<T>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copiedTreeRoot->llink = otherTreeRoot->llink;
        copiedTreeRoot->rlink = otherTreeRoot->rlink;
    }
}
#endif // BINARYTREE_H



