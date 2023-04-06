#include <bits/stdc++.h>
#include "../1. Node for Singly Linked List/SinglyLinkedListNode.h"
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    // Time Complexity :- O(n), n is the number of nodes in a linked list.
    // Space Complexity :- O(1)
    bool hasCycle(ListNode<int> *head)
    {
        // Using Floyd Cycle Detection Algorithm.

        // if fast pointer points to NULL, it means linked list does not contains any cycle..
        // but if the linked list contains cycle, then both the pointer will meet at a certain node.
        ListNode<int> *slow = head;
        ListNode<int> *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                // means, linked list contains cycle.
                return true;
            }
        }

        // if the above loop end, it means fast pointer points to null.
        // it means linked list does not contains any cycle.
        return false;
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

    node5 = new ListNode<int>(5);
    node4 = new ListNode<int>(4, node5);
    node3 = new ListNode<int>(3, node4);
    node2 = new ListNode<int>(2, node3);
    head = new ListNode<int>(1, node2);

    // cyclic connection.
    node5->next = node2;

    // Solution.
    Solution S;

    bool cyclePresent = S.hasCycle(head);

    if (cyclePresent == true)
    {
        cout << "Linked List has Cycle.\n";
    }
    else
    {
        cout << "Linked List does not contain any Cycle .\n";
    }
}