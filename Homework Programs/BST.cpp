// Search for "WRITE YOUR CODE" to complete this program
#include <iostream>
#include <string>
using namespace std;
;[=]
#ifndef BST_H
#define BST_H

#include <vector>
#include <stdexcept>
using namespace std;

template<typename T>
class TreeNode
{
public:
  T element; // Element contained in the node
  TreeNode<T>* left; // Pointer to the left child
  TreeNode<T>* right; // Pointer to the right child

  TreeNode(const T& e) // Constructor
  {
    this->element = e;
    left = nullptr;
    right = nullptr;
  }
};

template <typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
  Iterator(TreeNode<T>* p)
  {
    if (p == nullptr)
      current = -1; // The end
    else
    {
      // Get all the elements in inorder
      treeToVector(p);
      current = 0;
    }
  }

  Iterator operator++()
  {
    current++;
    if (current == v.size())
      current = -1; // The end
    return *this;
  }

  T& operator*()
  {
    return v[current];
  }

  bool operator==(const Iterator<T>& iterator) const
  {
    return current == iterator.current;
  }

  bool operator!=(const Iterator<T>& iterator) const
  {
    return current != iterator.current;
  }

private:
  int current;
  vector<T> v;
  void treeToVector(const TreeNode<T>* p)
  {
    if (p != nullptr)
    {
      treeToVector(p->left);
      v.push_back(p->element);
      treeToVector(p->right);
    }
  }
};

template <typename T>
class BST
{
public:
  BST();
  BST(const T elements[], int arraySize);
  BST(const BST<T>& tree);
  ~BST();
  bool search(const T& e) const;
  virtual bool insert(const T& e);
  virtual bool remove(const T& e);
  void inorder() const;
  void preorder() const;
  void postorder() const;
  int getSize() const;
  void clear();
  vector<TreeNode<T>*>* path(const T& e) const;
  int getNumberOfNonLeaves();

  Iterator<T> begin() const
  {
    return Iterator<T>(root);
  };

  Iterator<T> end() const
  {
    return Iterator<T>(nullptr);
  };

protected:
  TreeNode<T>* root;
  int size;
  virtual TreeNode<T>* createNewNode(const T& e);

private:
  void inorder(const TreeNode<T>* root) const;
  void postorder(const TreeNode<T>* root) const;
  void preorder(const TreeNode<T>* root) const;
  void copy(const TreeNode<T>* root);
  void clear(const TreeNode<T>* root);
  int getNumberOfNonLeaves(TreeNode<T>* root);
};

template <typename T>
BST<T>::BST()
{
  root = nullptr;
  size = 0;
}

template <typename T>
BST<T>::BST(const T elements[], int arraySize)
{
  root = nullptr;
  size = 0;

  for (int i = 0; i < arraySize; i++)
  {
    insert(elements[i]);
  }
}

/* Copy constructor */
template <typename T>
BST<T>::BST(const BST<T>& tree)
{
  root = nullptr;
  size = 0;
  copy(tree.root); // Recursively copy nodes to this tree
}

/* Copies the element from the specified tree to this tree */
template <typename T>
void BST<T>::copy(const TreeNode<T>* root)
{
  if (root != nullptr)
  {
    insert(root->element);
    copy(root->left);
    copy(root->right);
  }
}

/* Destructor */
template <typename T>
BST<T>::~BST()
{
  clear();
}

/* Return true if the element is in the tree */
template <typename T>
bool BST<T>::search(const T& e) const
{
  TreeNode<T>* current = root; // Start from the root

  while (current != nullptr)
    if (e < current->element)
    {
      current = current->left; // Go left
    }
    else if (e > current->element)
    {
      current = current->right; // Go right
    }
    else // Element e matches current.element
      return true; // Element e is found

  return false; // Element e is not in the tree
}

template <typename T>
TreeNode<T>* BST<T>::createNewNode(const T& e)
{
  return new TreeNode<T>(e);
}

// Insert element e into the binary tree
// Return true if the element is inserted successfully
// Return false if the element is already in the list
template <typename T>
bool BST<T>::insert(const T& e)
{
  if (root == nullptr)
    root = createNewNode(e); // Create a new root
  else
  {
    // Locate the parent node
    TreeNode<T>* parent = nullptr;
    TreeNode<T>* current = root;
    while (current != nullptr)
      if (e < current->element)
      {
        parent = current;
        current = current->left;
      }
      else if (e > current->element)
      {
        parent = current;
        current = current->right;
      }
      else
        return false; // Duplicate node not inserted

    // Create the new node and attach it to the parent node
    if (e < parent->element)
      parent->left = createNewNode(e);
    else
      parent->right = createNewNode(e);
  }

  size++;
  return true; // Element inserted
}

/* Inorder traversal */
template <typename T>
void BST<T>::inorder() const
{
  inorder(root);
}

/* Inorder traversal from a subtree */
template <typename T>
void BST<T>::inorder(const TreeNode<T>* root) const
{
  if (root == nullptr) return;
  inorder(root->left);
  cout << root->element << " ";
  inorder(root->right);
}

/* Postorder traversal */
template <typename T>
void BST<T>::postorder() const
{
  postorder(root);
}

/** Inorder traversal from a subtree */
template <typename T>
void BST<T>::postorder(const TreeNode<T>* root) const
{
  if (root == nullptr) return;
  postorder(root->left);
  postorder(root->right);
  cout << root->element << " ";
}

/* Preorder traversal */
template <typename T>
void BST<T>::preorder() const
{
  preorder(root);
}

/* Preorder traversal from a subtree */
template <typename T>
void BST<T>::preorder(const TreeNode<T>* root) const
{
  if (root == nullptr) return;
  cout << root->element << " ";
  preorder(root->left);
  preorder(root->right);
}

/* Get the number of nodes in the tree */
template <typename T>
int BST<T>::getSize() const
{
  return size;
}

/* Remove all nodes from the tree */
template <typename T>
void BST<T>::clear()
{
  // Left as exercise
}

/* Return a path from the root leading to the specified element */
template <typename T>
vector<TreeNode<T>*>* BST<T>::path(const T& e) const
{
  vector<TreeNode<T>*>* v = new vector<TreeNode<T>*>();
  TreeNode<T>* current = root;

  while (current != nullptr)
  {
    v->push_back(current);
    if (e < current->element)
      current = current->left;
    else if (e > current->element)
      current = current->right;
    else
      break;
  }

  return v;
}

/* Delete an element e from the binary tree.
 * Return true if the element is deleted successfully
 * Return false if the element is not in the tree */
template <typename T>
bool BST<T>::remove(const T& e)
{
  // Locate the node to be deleted and also locate its parent node
  TreeNode<T>* parent = nullptr;
  TreeNode<T>* current = root;
  while (current != nullptr)
  {
    if (e < current->element)
    {
      parent = current;
      current = current->left;
    }
    else if (e > current->element)
    {
      parent = current;
      current = current->right;
    }
    else
      break; // Element e is in the tree pointed by current
  }

  if (current == nullptr)
    return false; // Element e is not in the tree

  // Case 1: current has no left children
  if (current->left == nullptr)
  {
    // Connect the parent with the right child of the current node
    if (parent == nullptr)
    {
      root = current->right;
    }
    else
    {
      if (e < parent->element)
        parent->left = current->right;
      else
        parent->right = current->right;
    }

    delete current; // Delete current
  }
  else
  {
    // Case 2: The current node has a left child
    // Locate the rightmost node in the left subtree of
    // the current node and also its parent
    TreeNode<T>* parentOfRightMost = current;
    TreeNode<T>* rightMost = current->left;

    while (rightMost->right != nullptr)
    {
      parentOfRightMost = rightMost;
      rightMost = rightMost->right; // Keep going to the right
    }

    // Replace the element in current by the element in rightMost
    current->element = rightMost->element;

    // Eliminate rightmost node
    if (parentOfRightMost->right == rightMost)
      parentOfRightMost->right = rightMost->left;
    else
      // Special case: parentOfRightMost->right == current
      parentOfRightMost->left = rightMost->left;

    delete rightMost; // Delete rightMost
  }

  size--;
  return true; // Element inserted
}

template < typename T >
int BST < T >::getNumberOfNonLeaves()
{
  return getNumberOfNonLeaves(root);
}

template < typename T >
int BST < T >::getNumberOfNonLeaves(TreeNode<T>* root)
{
  if (root == NULL || (root->left == NULL &&
                         root->right == NULL))
        return 0;
    return 1 + getNumberOfNonLeaves(root->left) +
               getNumberOfNonLeaves(root->right);
}
#endif

int main()
{
  BST<string> tree1;

  cout << "Enter six strings: ";
  for (int i = 0; i < 6; i++) {
    string s;
    cin >> s;
    tree1.insert(s);
  }

  tree1.insert("Michael");
  tree1.insert("George");
  tree1.insert("Tom");

  cout << "Inorder (sorted): ";
  tree1.inorder();

  cout << "\nPostorder: ";
  tree1.postorder();

  cout << "\nPreorder: ";
  tree1.preorder();

  cout << "\nThe number of nodes is " << tree1.getSize();

  int numbers[] =
  {
    -8, -9, 2, 4, 3, 1, 8, 5, 6, 7
  };
  BST < int > tree2(numbers, 10);
  cout << "\nPreorder (sorted): ";
  tree2.preorder();

  cout << "\nNumber of non-leaves nodes in tree1: " << tree1.getNumberOfNonLeaves() << endl;
  cout << "Number of non-leaves nodes in tree2: " << tree2.getNumberOfNonLeaves() << endl;

  return 0;
}