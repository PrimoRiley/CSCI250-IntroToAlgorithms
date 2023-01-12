#include <iostream>
#include <cassert>

using namespace std;

template<class T>
struct Node
{
    T info;
    Node* link;
}

template<class T>
class LinkedStack : public stackADT<T>
{
    public:
        LinkedStack<T>& operator=(const LinkedStack<T>&);
        bool isEmptyStack() const;
        bool isFullStack() const;
        void initializeStack();
        void push(const T& newItem);

        T top() const;

        void pop();

        LinkedStack() {}
        ~LinkedStack() {}
    
    private:
    
}