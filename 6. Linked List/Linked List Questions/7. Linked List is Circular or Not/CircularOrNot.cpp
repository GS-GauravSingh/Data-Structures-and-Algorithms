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
    bool isCircular_Approach_1(ListNode<int> *head)
    {
        // Base Case
        if (head == NULL || head->next == NULL)
        {
            return false;
        }

        ListNode<int> *ptr = head->next;

        // if ptr point to head, it means linked list is circular.
        // if ptr point to NULL, it means linked list is not circular.
        while (ptr != head && ptr != NULL)
        {
            ptr = ptr->next;
        }

        // if ptr == head, it means Linked List is circular (last not points to head).
        if (ptr == head)
        {
            return true;
        }
        // else, ptr points to NULL means it is not circular (last Node points to NULL).
        return false;
    }


    // Time Complexity :- O(n), n is the number of nodes in a linked list.
    // Space Complexity :- O(1)
    bool isCircular_Approach_2(ListNode<int> *head)
    {
        // Using, fast and slow pointer technique (also known as the tortoise and hare algorithm).
        // slow pointer move 1 node at a time.
        // fast pointer move 2 node at a time.

        // if fast pointer points to NULL, it means linked list is not circular.
        // but if the linked list is circular, then both the pointer will meet at a certain node.
        ListNode<int> *slow = head;
        ListNode<int> *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                // means, linked list is circular.
                return true;
            }
        }

        // if the above loop end, it means fast pointer points to null.
        // it means linked list is not circular.
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

    // circular connection.
    node5->next = head;

    // Solution.
    Solution S;

    bool checkCircular = S.isCircular_Approach_1(head);
    // bool checkCircular = S.isCircular_Approach_2(head);
    if (checkCircular == true)
    {
        cout << "Linked List is Circular.\n";
    }
    else
    {
        cout << "Linked List is not Circular.\n";
    }
}