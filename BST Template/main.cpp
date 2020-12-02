/*-----------------------------------------------------------------------------------------

    ARYAN J. PATIL
    BT18CSE096

------------------------------------------------------------------------------------------*/


#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    int response; // Response of the user from terminal

    // Selecting data type from user
    cout << "Select the datatype for creating the BST :\n1. int\n2. float\n3. char\n";
    cin >> response;

    if (response == 1) // Creating int BST
    {
        BinarySearchTree<int> tree;

        int exit = 0; // Loop invariant to exit the loop
        int data;     // Required for response inside the loop

        while (!exit)
        {
            cout << "1. Insert a node\n2. Delete a node\n3. Print In-order\n4. Print Pre-order\n5. Print Post-order\n6. Search for a node\n7. Exit the program\n";

            cin >> response;

            if(response==1)     // Insert a node
            {
                cout << "Enter the value: ";
                cin >> data;
                tree.insertNode(data);
                cout << data << " has been inserted.\n";
            }
            else if(response==2)        // Delete a node
            {
                cout << "Enter the value to delete: ";
                cin >> data;
                tree.remove(data);
            }
            else if(response==3)        // Inorder traversal    
            {
                tree.displayInOrder();
                cout << endl;
            }
            else if(response==4)        // Preorder Traversal
            {
                tree.displayPreOrder();
                cout << endl;
            }
            else if(response==5)        // Postorder Traversal
            {
                tree.displayPostOrder();
                cout << endl;
            }
            else if(response==6)        // Search for a data value
            {
                cout << "Enter the value to search: ";
                cin >> data;
                if(tree.searchNode(data))
                {
                    cout << "The data " << data << " is present.\n";
                }
                else
                {
                    cout << "The data " << data << " is NOT present.\n";
                }
            }
            else if(response==7)        // Exit 
            {
                exit = 1;
            }
        }
    }
    else if (response == 2) // Creating float BST
    {
        BinarySearchTree<float> tree;

        int exit = 0; // Loop invariant to exit the loop
        float data;     // Required for response inside the loop

        while (!exit)
        {
            cout << "1. Insert a node\n2. Delete a node\n3. Print In-order\n4. Print Pre-order\n5. Print Post-order\n6. Search for a node\n7. Exit the program\n";

            cin >> response;

            if(response==1)         // Insert a node
            {
                cout << "Enter the value: ";
                cin >> data;
                tree.insertNode(data);
                cout << data << " has been inserted.\n";
            }
            else if(response==2)        // Delete a node
            {
                cout << "Enter the value to delete: ";
                cin >> data;
                tree.remove(data);
            }
            else if(response==3)        // Inorder traversal
            {
                tree.displayInOrder();
                cout << endl;
            }
            else if(response==4)        // Prorder traversal
            {
                tree.displayPreOrder();
                cout << endl;
            }
            else if(response==5)        // Postorder traversal
            {
                tree.displayPostOrder();
                cout << endl;
            }
            else if(response==6)        // Search for a node
            {
                cout << "Enter the value to search: ";
                cin >> data;
                if(tree.searchNode(data))
                {
                    cout << "The data " << data << " is present.\n";
                }
                else
                {
                    cout << "The data " << data << " is NOT present.\n";
                }
                
            }
            else if(response==7)        // Exit
            {
                exit = 1;
            }
        }
    }
    else if (response == 3) // Creating char BST
    {
        BinarySearchTree<char> tree;

        int exit = 0; // Loop invariant to exit the loop
        char data;     // Required for response inside the loop

        while (!exit)
        {
            cout << "1. Insert a node\n2. Delete a node\n3. Print In-order\n4. Print Pre-order\n5. Print Post-order\n6. Search for a node\n7. Exit the program\n";

            cin >> response;

            if(response==1)         // Insert a node
            {
                cout << "Enter the value: ";
                cin >> data;
                tree.insertNode(data);
                cout << data << " has been inserted.\n";
            }
            else if(response==2)        // Delete a node
            {
                cout << "Enter the value to delete: ";
                cin >> data;
                tree.remove(data);
            }
            else if(response==3)        // Inorder traversal
            {
                tree.displayInOrder();
                cout << endl;
            }
            else if(response==4)        // Preorder traversal
            {
                tree.displayPreOrder();
                cout << endl;
            }
            else if(response==5)        // Postorder traversal
            {
                tree.displayPostOrder();
                cout << endl;
            }
            else if(response==6)        // Search for a data value
            {
                cout << "Enter the value to search: ";
                cin >> data;
                if(tree.searchNode(data)==true)
                {
                    cout << "The data " << data << " is present.\n";
                }
                else
                {
                    cout << "The data " << data << " is NOT present.\n";
                }
            }
            else if(response==7)        // Exit
            {
                exit = 1;
            }
        }
    }
    else // Exit for invalid input
    {
        cout << "Invalid Input!\nExiting program...\n";
    }

    return 0;
}