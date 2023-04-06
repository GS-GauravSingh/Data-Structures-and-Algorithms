#include <bits/stdc++.h>
#include "../1. Node for Singly Linked List/SinglyLinkedListNode.h"
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Method that removes duplicates from sorted linked list. */
    // Time Complexity :- O(n), n is the number of nodes in a linked list.
    // Space Complexity :- O(1)
    ListNode<int> *deleteDuplicates(ListNode<int> *head)
    {
        // Base Cases
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode<int> *currentNode = head;
        while (currentNode != NULL && currentNode->next != NULL)
        {
            // if currentNode -> data != currentNode -> next -> data, in this case simply move ahead.
            if (currentNode->data != currentNode->next->data)
            {
                // Unique elements, move ahead.
                currentNode = currentNode->next;
            }
            else
            {
                // Duplicate Element.
                // if currentNode -> data == currentNode -> next -> data, in this case,
                // delete the node (currentNode -> next).
                ListNode<int> *nodeToDelete = currentNode->next;

                // connections.
                currentNode->next = currentNode->next->next;
                nodeToDelete->next = NULL;
                delete nodeToDelete;
            }
        }

        return head;
    }

    /* Method to Print Linked List. */
    void printList(ListNode<int> *&head)
    {
        ListNode<int> *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    // creating nodes of linked list.
    ListNode<int> *head;
    ListNode<int> *node2;
    ListNode<int> *node3;
    ListNode<int> *node4;
    ListNode<int> *node5;
    ListNode<int> *node6;

    // Initializing Nodes.
    node6 = new ListNode<int>(6);
    node5 = new ListNode<int>(3, node6);
    node4 = new ListNode<int>(3, node5);
    node3 = new ListNode<int>(2, node4);
    node2 = new ListNode<int>(2, node3);
    head = new ListNode<int>(1, node2);

    // Solution.
    Solution S;
    cout << "Before Removing Duplicates : ";
    S.printList(head);
    head = S.deleteDuplicates(head);
    cout << "After Removing Duplicates : ";
    S.printList(head);
}