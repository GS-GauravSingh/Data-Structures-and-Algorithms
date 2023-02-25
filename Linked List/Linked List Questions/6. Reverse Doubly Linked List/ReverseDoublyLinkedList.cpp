#include <bits/stdc++.h>
#include "../2. Node for Doubly Linked List/DoublyLinkedListNode.h"
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    // Time Complexity :- O(n), n is the numbers of nodes in a Linked List.
    // Space Complexity :- O(1)
    void reverseDoublyList(ListNode<int> *&head)
    {
        ListNode<int> *currentNode = head;
        ListNode<int> *previousNode = NULL;
        ListNode<int> *nextNode = NULL;

        while (currentNode != NULL)
        {
            // store the reference of next node.
            nextNode = currentNode->next;

            // make a connection, that the current Node points to the previous Node.
            currentNode->next = previousNode;

            // In case of DLL we have to handle the previous pointer also.
            currentNode->previous = nextNode;

            // move pointers.
            previousNode = currentNode;
            currentNode = nextNode;
        }

        // at this point your [previousNode] is the head of reversed linked list.
        head = previousNode;
    }

    /* Method to Print Linked List. */
    void printList(ListNode<int> *head)
    {
        ListNode<int> *ptr = head;
        cout << "NULL <--> ";
        while (ptr != NULL)
        {
            cout << ptr->data << " <--> ";
            ptr = ptr->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    ListNode<int> *head = new ListNode<int>(1);
    ListNode<int> *node1 = new ListNode<int>(2);
    ListNode<int> *node2 = new ListNode<int>(3);
    ListNode<int> *node3 = new ListNode<int>(4);
    ListNode<int> *node4 = new ListNode<int>(5);
    ListNode<int> *node5 = new ListNode<int>(6);

    // making connections.
    head->next = node1;

    node1->previous = head;
    node1->next = node2;

    node2->previous = node1;
    node2->next = node3;

    node3->previous = node2;
    node3->next = node4;

    node4->previous = node3;
    node4->next = node5;

    node5->previous = node4;

    // printing.
    Solution S;
    S.printList(head);

    // Reverse.
    S.reverseDoublyList(head);
    S.printList(head);
}