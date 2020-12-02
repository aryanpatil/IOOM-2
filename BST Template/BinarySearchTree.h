/*-----------------------------------------------------------------------------------------

    ARYAN J. PATIL
    BT18CSE096

------------------------------------------------------------------------------------------*/



#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>

using namespace std;

template <class T>
class BinarySearchTree
{
public:
    // Structure for tree node
    struct TreeNode
    {
        T data;                    
        struct TreeNode *left;      // Left child pointer
        struct TreeNode *right;     // Right child pointer
    };

private:    
    struct TreeNode *root;          // Root pointer  
    
public: 
    struct TreeNode* getRoot();     // Return the root 
    void insert(struct TreeNode *&, struct TreeNode *&);    // Inserting a node in tree
    void destroySubTree(struct TreeNode *);     // Used for destructor
    void deleteNode(T, struct TreeNode *&);     // Delete the node from tree
    void makeDeletion(struct TreeNode *&);      // Aux function for deleteNode()
    void displayInOrder(struct TreeNode *);     //
    void displayPreOrder(struct TreeNode *);    //  Tree Display Functions
    void displayPostOrder(struct TreeNode *);   //

    BinarySearchTree(); // Constructor
    ~BinarySearchTree(); // Destructor
    void insertNode(T);             // Aux function for inserting node in tree
    bool searchNode(T);             // Search a node in the tree
    void remove(T);                 // Driver function for deleting a node from tree
    void displayInOrder();
    void displayPreOrder();
    void displayPostOrder();
};


// FUNCTION DEFINITIONS
template <class T>
BinarySearchTree<T>::BinarySearchTree(): root(NULL) {}// Constructor


template <class T>
BinarySearchTree<T>::~BinarySearchTree() // Destructor
{
    destroySubTree(root);       // Delete tree
    cout << "The tree has been deleted...\n";
}


template <class T>
struct BinarySearchTree<T>::TreeNode* BinarySearchTree<T>::getRoot()
{
    return root;
}


template <class T>
void BinarySearchTree<T>::insert(struct TreeNode *&nodePtr, struct TreeNode *&newNode)
{
    if (nodePtr == NULL)
    {
        // Insert the node.
        nodePtr = newNode;
    }
    else if (newNode->data < nodePtr->data)
    {
        // Search the left branch
        insert(nodePtr->left, newNode);
    }
    else
    {
        // Search the right branch
        insert(nodePtr->right, newNode);
    }
}


//**********************************************************
// insertNode creates a new node to hold num as its data, *
// and passes it to the insert function. *
//**********************************************************
template <class T>
void BinarySearchTree<T>::insertNode(T num)
{
    TreeNode *newNode = NULL; // Pointer to a new node.
    // Create a new node and store num in it.
    newNode = new TreeNode;
    newNode->data = num;
    newNode->left = newNode->right = NULL;
    // Insert the node.
    insert(root, newNode);
}
//***************************************************



// destroySubTree is called by the destructor. It *
// deletes all nodes in the tree. *
//***************************************************
template <class T>
void BinarySearchTree<T>::destroySubTree(struct TreeNode *nodePtr)
{
    if (nodePtr->left)
    {
        destroySubTree(nodePtr->left);
    }
    if (nodePtr->right)
    {
        destroySubTree(nodePtr->right);
    }
    delete nodePtr;
}
//***************************************************


// searchNode determines if a data is present in the tree. If so, *
// the function returns true. Otherwise, it returns false. *
//***************************************************
template <class T>
bool BinarySearchTree<T>::searchNode(T num)
{
    bool status = false;
    struct TreeNode *nodePtr = root;
    while(nodePtr)
    {
        if (nodePtr->data == num)
        {
            status = true;
            break;
        }
        else if (num < nodePtr->data)
        {
            nodePtr = nodePtr->left;
        }
        else
        {
            nodePtr = nodePtr->right;
        }
    }
    return status;
}
//**********************************************


// remove calls deleteNode to delete the *
// node whose data member is the same as num. *
//**********************************************
template <class T>
void BinarySearchTree<T>::remove(T num)
{
    deleteNode(num, root);
}
//********************************************


// deleteNode deletes the node whose data *
// member is the same as num. *
//********************************************
template <class T>
void BinarySearchTree<T>::deleteNode(T num, struct TreeNode *&nodePtr)
{
    if (nodePtr!=NULL && num < nodePtr->data)
    {
        deleteNode(num, nodePtr->left);
    }
    else if (nodePtr!=NULL && num > nodePtr->data)
    {
        deleteNode(num, nodePtr->right);
    }
    else
    {
        makeDeletion(nodePtr);
    }
}
//***********************************************************


// makeDeletion takes a reference to a pointer to the node that is to be deleted. *
// The node is removed and the branches of the tree below the node are reattached. *
//***********************************************************
template <class T>
void BinarySearchTree<T>::makeDeletion(struct TreeNode *&nodePtr)
{

    // Temporary pointer, used in reattaching the left subtree.
    struct TreeNode *tempNodePtr = NULL;
    if (nodePtr == NULL)
    {
        cout << "Cannot delete empty node.\n";
    }
    else if (nodePtr->right == NULL)
    {
        cout << "\n\nNow deleting " << nodePtr->data << " from the tree...." << endl;
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left; // Reattach the left child
        delete tempNodePtr;
    }
    else if (nodePtr->left == NULL)
    {
        cout << "\n\nNow deleting " << nodePtr->data << " from the tree...." << endl;
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right; // Reattach the right child
        delete tempNodePtr;
    }
    // If the node has two children.
    else
    {
        cout << "\n\nNow deleting " << nodePtr->data << " from the tree...." << endl;
        // Move one node the right.
        tempNodePtr = nodePtr->right;
        // Go to the end left node.
        while (tempNodePtr->left)
        {
            tempNodePtr = tempNodePtr->left;
        }
        // Reattach the left subtree.
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        // Reattach the right subtree.
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }

    
}
//****************************************************************


// The displayInOrder member function displays the datas *
// in the subtree pointed to by nodePtr, via inorder traversal. *
//****************************************************************
template <class T>
void BinarySearchTree<T>::displayInOrder()
{
    displayInOrder(getRoot());
}

template <class T>
void BinarySearchTree<T>::displayInOrder(struct TreeNode *nodePtr)
{
    if (nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->data << " ";
        displayInOrder(nodePtr->right);
    }
}
//****************************************************************


// The displayPreOrder member function displays the datas *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************
template <class T>
void BinarySearchTree<T>::displayPreOrder()
{
    displayPreOrder(getRoot());
}

template <class T>
void BinarySearchTree<T>::displayPreOrder(struct TreeNode *nodePtr)
{
    if (nodePtr)
    {
        cout << nodePtr->data << " ";
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}
//****************************************************************


// The displayPostOrder member function displays the datas *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************
template <class T>
void BinarySearchTree<T>::displayPostOrder()
{
    displayPostOrder(getRoot());
}

template <class T>
void BinarySearchTree<T>::displayPostOrder(struct TreeNode *nodePtr)
{
    if (nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->data << " ";
    }
}

#endif
