#include <bits/stdc++.h>
#include "../../Binary Search Tree Implementation/BSTImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /*
    Time Complexity:- O(height of the Tree)
    Space Complexity:- O(1)
    */
    BSTNode *lca(BSTNode *root, BSTNode *p, BSTNode *q)
    {
        // Base CAse
        if (root == NULL)
        {
            return root;
        }

        while (root != NULL)
        {
            if (root->data < p->data && root->data < q->data)
            {
                // if root -> data is < p -> data and q -> data, it means p and q are present at right subtree.
                root = root->right;
            }

            else if (root->data > p->data && root->data > q->data)
            {
                // if root -> data is > p -> data and q -> data, it means p and q are present at left subtree.
                root = root->left;
            }

            else
            {
                // if ( (root -> data is > p -> data) && (root -> data < q -> data) ) ||
                //    ( (root -> data is < p -> data) && (root -> data > q -> data) );
                // in this case your root is the lca, return root.
                return root;
            }
        }
    }
};

int main(void)
{
    /*
    Sample Inputs:
    I/O 1 : 1 2 3 4 7 -1
    I/O 2 : 10 2 3 8 9 4 7 -1
    */

    // Creating root node of BST.
    BSTNode *root = NULL;

    // Building Binary Search Tree.
    BinarySearchTree bst;
    bst.takeInput(root);

    // Solution.
    Solution S;

    BSTNode* p = new BSTNode(4);
    BSTNode* q = new BSTNode(9);


    cout<<"LCA : "<<S.lca(root, p, q)->data<<".";

}