#include <bits/stdc++.h>
#include "../1. Node for Singly Linked List/SinglyLinkedListNode.h"
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    // Time Complexity :- O(n/2) => O(n), n is the numbers of nodes in a Linked List.
    // Space Complexity :- O(1)
    ListNode<int> *middleNode(ListNode<int> *&head)
    {

        // Using, fast and slow pointer technique (also known as the tortoise and hare algorithm).
        // slow pointer move 1 node at a time.
        // fast pointer move 2 node at a time.
        ListNode<int> *slow = head;
        ListNode<int> *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
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

    // Odd Number of Nodes.
    node5 = new ListNode<int>(5);
    node4 = new ListNode<int>(4, node5);
    node3 = new ListNode<int>(3, node4);
    node2 = new ListNode<int>(2, node3);
    head = new ListNode<int>(1, node2);

    // even Number of Nodes.
    // node6 = new ListNode<int>(6);
    // node5 = new ListNode<int>(5, node6);
    // node4 = new ListNode<int>(4, node5);
    // node3 = new ListNode<int>(3, node4);
    // node2 = new ListNode<int>(2, node3);
    // head = new ListNode<int>(1, node2);

    // Solution.
    Solution S;
    S.printList(head);
    ListNode<int> *mid = S.middleNode(head);
    cout << "Middle Node : " << mid->data;
}