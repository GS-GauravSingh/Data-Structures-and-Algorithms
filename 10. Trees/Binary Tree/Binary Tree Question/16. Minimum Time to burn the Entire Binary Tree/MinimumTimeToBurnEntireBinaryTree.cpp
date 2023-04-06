/*
Question:-
Given a binary tree and a node called target. Find the minimum time required to burn the complete binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given node get burned. That is its left child, right child, and parent.


Example 1:

Input:
          1
        /   \
      2      3
    /  \      \
   4    5      6
       / \      \
      7   8      9
                   \
                   10
Target Node = 8
Output: 7

Explanation: If leaf with the value
8 is set on fire.
After 1 sec: 5 is set on fire.
After 2 sec: 2, 7 are set to fire.
After 3 sec: 4, 1 are set to fire.
After 4 sec: 3 is set to fire.
After 5 sec: 6 is set to fire.
After 6 sec: 9 is set to fire.
After 7 sec: 10 is set to fire.
It takes 7s to burn the complete tree.


Approach:-
For each node, we have to burn the left child node, right child node and parent node.
Now, we already have a pointer to left child and right child, but we don't have any pointer to parent node so, first we need to store the parent node for each node.

Alorithm:
Step 1: Create a mapping to store parent node of each node.

Step 2: Traverse the tree and find the target node (target node is the node from where we have to start burning the tree). While storing the mapping of parent node, find the traget node and store it somewhere.

Step 3: In step 3, start burning the tree from target node.

How to burn ?
First, To start burning you need 2 additional data structure:
1. map to track if a particular node is visited or not (if a node is visited it means we already burn that node).
2. queue to traverse with target node (because we are using level order traversal to burn the tree).

Now, first, push the target node into the queue and mark it as visited, because the target node is burned first and then start the level order traversal and start pushing the nodes into the queue and mark that pushed nodes as visited.

*/

#include <bits/stdc++.h>
#include "../../Binary Tree Implementation/BinaryTreeImplementation.h"
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
  /* Method to create node to parent mapping. */
  // Time Complexity :- O(n), n is the number of node in a Binary Tree.
  // Space Complexity :- O(n), space used by queue data structure.
  Node *createNodeToParentMappingAndFindTargetNode(Node *root, unordered_map<Node *, Node *> &nodeToParent, int target)
  {
    // declaring the queue of type node*.
    queue<Node *> q;

    // push root node into the queue.
    q.push(root);

    // parent of root is NULL, there is no parent of root node.
    nodeToParent[root] = NULL;

    // pointer to store the target node.
    Node *targetNode = NULL;

    // traversing the tree.
    while (!q.empty())
    {
      // take out the front node.
      Node *frontNode = q.front();

      // pop the front element of the queue.
      q.pop();

      // finding the target node.
      if (frontNode->data == target)
      {
        targetNode = frontNode;
      }

      // pushing the left child.
      if (frontNode->leftChild != NULL)
      {
        // before pushing the left Child node, store the parent node of left child node.
        // Parent of left child = frontNode.
        nodeToParent[frontNode->leftChild] = frontNode;
        q.push(frontNode->leftChild);
      }

      // pushing the right child.
      if (frontNode->rightChild != NULL)
      {
        // before pushing the right Child node, store the parent node of right child node.
        // Parent of right child = frontNode.
        nodeToParent[frontNode->rightChild] = frontNode;
        q.push(frontNode->rightChild);
      }
    }

    // return the target node.
    return targetNode;
  }

  /* Helper Method to return the minimum time taken to burn the entire binary tree. */
  // Time Complexity :- O(n), n is the number of node in a Binary Tree.
  // Space Complexity :- O(h), h is the height of the binary tree.
  int burnTree(Node *targetNode, unordered_map<Node *, Node *> &nodeToParent)
  {
    // to store the time taken to burn the entire binary tree.
    int minimumTime = 0;

    // map to track if a particular node is visited or not (if a node is visited it means we already burn that node).
    unordered_map<Node *, bool> visited;

    // declaring the queue of type node*.
    queue<Node *> q;

    // push the targetNode into the queue.
    q.push(targetNode);

    // burn the tragetNode first, mark as viited.
    visited[targetNode] = true;

    // traverse the tree.
    while (!q.empty())
    {
      // taking a flag variable to increment the minimum time,
      // increment the count after burning all the connected node i.e., left, right, and parent node.
      bool flag = false;

      // processing frontNode and its connected nodes.
      int sizeOfQueue = q.size();
      for (int i = 0; i < sizeOfQueue; i++)
      {
        // take out the front node.
        Node *frontNode = q.front();

        // pop the front element of the queue.
        q.pop();
        // pushing the left child only when if it is not visited.
        if (frontNode->leftChild != NULL && visited[frontNode->leftChild] != true)
        {
          // push it into the queue.
          q.push(frontNode->leftChild);

          // mark this node as visited.
          visited[frontNode->leftChild] = true;

          // we burned this node, so mark the flag as true.
          flag = true;
        }

        // pushing the right child only when if it is not visited.
        if (frontNode->rightChild != NULL && visited[frontNode->rightChild] != true)
        {
          // push it into the queue.
          q.push(frontNode->rightChild);

          // mark this node as visited.
          visited[frontNode->rightChild] = true;

          // we burned this node, so mark the flag as true.
          flag = true;
        }

        // pushing the parent node only when if it is not visited.

        // getting the parent node of frontNode.
        Node *parentOfFrontNode = nodeToParent[frontNode];
        if (parentOfFrontNode != NULL && visited[parentOfFrontNode] != true)
        {
          // push it into the queue.
          q.push(parentOfFrontNode);

          // mark this node as visited.
          visited[parentOfFrontNode] = true;

          // we burned this node, so mark the flag as true.
          flag = true;
        }
      }

      // if flag is true, it means we have burned all the connected nodes of frontNode so,
      // increment the minimumTime.
      if (flag == true)
      {
        minimumTime++;
      }
    }

    // return answer.
    return minimumTime;
  }

public:
  /* Method to return the minimum time taken to burn the entire binary tree. */
  int minTime(Node *root, int target)
  {
    // Step 1: Create a mapping to store parent node of each node.
    // Step 2: Traverse the tree and find the target node (target node is the node from where we have to start burning the tree). While storing the mapping of parent node, find the traget node and store it somewhere.
    unordered_map<Node *, Node *> nodeToParent;
    Node *targetNode = createNodeToParentMappingAndFindTargetNode(root, nodeToParent, target);

    // Step 3: In stem 3, start burning the tree from target node.
    int minimumTime = burnTree(targetNode, nodeToParent);

    // Step 4: return answer.
    return minimumTime;
  }
};

int main(void)
{
  // Building the tree.
  // Creating a root node of the Binary tree.
  Node *root = NULL;

  // Building Tree (PreOrder Build).
  BinaryTree BT;
  BT.buildTreePreOrder(root);

  /*
  Example Build :-
  Input for Pre-Order Build :- 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  Input for Level Order Build :- 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

  Tree preview :-
                                          1           ---- Level 1, Height 1, Depth 1
                                       /     \
                                      3        5      ---- Level 2, Height 2, Depth 2
                                    /  \      /
                                   7    11   17       ---- Level 3, Height 3, Depth 3

  Example: target node = 17.
  Output: 4

  Explanation: If leaf with the value 17 is set on fire.
  After 1 sec: the nodes which are connected to 17 starts burning, means 5 is set on fire.
  After 2 sec: the nodes which are connected to 5 starts burning, means 1 is set on fire.
  After 3 sec: the nodes which are connected to 5 starts burning, means 3 is set on fire.
  After 4 sec: the nodes which are connected to 3 starts burning, means 7, 11 is set on fire.

  It takes 4 seconds to burn the complete tree.
  */

  // Solution.
  Solution S;
  int targetNode = 17;
  cout << "Minimum Time : " << S.minTime(root, targetNode) << ".\n";
}