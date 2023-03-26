#include <bits/stdc++.h>
#include "../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* --------------------------- Solution Class ----------------------------------- */
class Solution
{
private:
public:
    /*
    What is Morris Traversal ?
    Morris Traversal is an iterative tree traversal algorithm, Morris traversal is an iterative algorithm that's why its space complexity is constant so basically Morris traversal is a space optimize tree tarversal algorithm.

    Morris traversal is valid for Inorder, PreOrder and Postorder traversal means you can implement morris traversal to traverse the tree same as we traverse the tree using Inorder, preorder and postorder traversals.

    In Morris traversal, we hae to create temporary links


    Algorithm for Morris Inorder Traversal,
    1. Initialize the root as the current node curr.
    2. Run a While loop till currentNode is not null.
        2.1. check if curr has a left child.
            2.1.1. If curr does not have a left child, print curr and move right (curr->right).
            2.1.2. Else If curr has a left child, then find the inorder predecessor.

                   if(predecessor ->right == NULL)
                   {
                    // if yes, then make a temporary connection of predecessor -> right = current;
                   }
                   else{
                    // remove temporary connetion.
                    // if prdecessor -> right != NULL, the make  predecessor -> right = NULL;
                    // print current;
                    // move right.
                   }


    Pseudocode:
    Node* current = root;
    while(current != NULL){

        if( current -> left does not exist){
            print (current);
            move right (current = current -> right);
        }
        else{
            // if current -> left exist's.
            -----------------------------------------------------------------------------------
            ## What is Onorder Predecessor ? ##
            Lets take an example to understand this,
            Example Tree:-
                                            1
                                         /     \
                                        3        5
                                      /  \      /
                                     7    11   17

            Inorder Traversal of above tree is: 7, 3, 11, 1, 17, 5

            Predecessor of 7 is nothing (because there is no value before 7).
            Predecessor of 3 is 7.
            Predecessor of 11 is 3.
            Predecessor of 1 is 11.
            Predecessor of 17 is 1.
            Predecessor of 5 is 17.

            ## How to find inorder predecessor ?
            Lets say you have to find the predessor of 1.

            Lets take currentNode = 1;
            Now, to find predessor of 1 move one node towards left i.e., currentNode -> left, currentNode -> left = 3, now currentNode = 3.

            Now, from here the rightmost child node is our inorder predecessor.
            The right most childnode is 3 is 11.

            So, the predecessor of 1 is 11.

            ------------------------------------------------------------------------------------------

            prdecessor = find(current);

            // temporary link making.
            if(predecessor -> right == NULL){
                // if yes, then make a temporary connection of predecessor -> right = current;
                predecessor -> right = current;

                current = current -> left; // move left;

            }
            // temporary link removing.
            else{
                // if prdecessor -> right != NULL, the make  predecessor -> right = NULL;
                // print current;
                // move right.

                predecessor -> right = NULL;
                print(current);
                current = current -> right;

            }
        }

    */
    // Time Complexity of Morris Traversal: O(n), n is the number of nodes in a Binary Tree.
    // Space Complexity of Morris Traversal: O(1), because Morris traversal is an iterative algorithm.
    void MorrisTraversal(Node *root)
    {
        // Initialize the root as the current node.
        Node *currentNode = root;

        // Run a While loop till currentNode is not null.
        while (currentNode != NULL)
        {
            // check if curr has a left child.
            if (currentNode->leftChild == NULL)
            {
                // If curr does not have a left child, print curr and move right (curr->right).
                cout << currentNode->data << " ";
                currentNode = currentNode->rightChild;
            }
            else
            {
                // Else If curr has a left child, then find the inorder predecessor.
                Node *predecessor = currentNode->leftChild;
                while (predecessor->rightChild != NULL && predecessor->rightChild != currentNode)
                {
                    predecessor = predecessor->rightChild;
                }

                // make temporary connection with currentNode.
                if (predecessor->rightChild == NULL)
                {
                    // if predecessor -> right == NULL,
                    // then make temporary link with currentNode.
                    // predecessor -> right = currentNode and then move left (currentNode->left).
                    predecessor->rightChild = currentNode;
                    currentNode = currentNode->leftChild;
                }

                // remove temporary connection.
                else
                {
                    // if predecessor -> right != NULL, then remove temporary link with current.
                    // predecessor -> right = NULL, print current -> data and move right.
                    predecessor->rightChild = NULL;
                    cout << currentNode->data << " ";
                    currentNode = currentNode->rightChild;
                }
            }
        }
    }
};
int main(void)
{
    // Creating a root node of the Binary tree.
    Node *root = NULL;

    // Building Tree (PreOrder Build).
    BinaryTree BT;
    BT.buildTreePreOrder(root);

    cout<<"Inorder Traversal: ";
    BT.InOrderTraversalRecursive(root);


    /*
    Example Build :-
    Input for Pre-Order Build :- 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    Input for Level Order Build :- 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    Tree preview :-
                                            1
                                         /     \
                                        3        5
                                      /  \      /
                                     7    11   17



    */

    Solution S;
    cout<<"\nMorris Traversal: ";
    S.MorrisTraversal(root);
}