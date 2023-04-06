#include <bits/stdc++.h>
#include "../1. Node for Singly Linked List/SinglyLinkedListNode.h"
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Method that merges 2 sorted Linked List. */
    // Time Complexity :- O(n), n is the number of nodes in a linked list.
    // Space Complexity :- O(1)
    ListNode<int> *mergeTwoSortedLists(ListNode<int> *&first, ListNode<int> *&second)
    {
        // Base Case
        if (first == NULL)
        {
            return second;
        }
        if (second == NULL)
        {
            return first;
        }

        // pointers.
        ListNode<int> *mergedListHead = new ListNode<int>(-1);
        ListNode<int> *mergedListTail = mergedListHead;

        // pointer to traverse list's.
        ListNode<int> *listOne = first;
        ListNode<int> *listTwo = second;


        // this loop will terminate if one of the lists is exhausted.
        while (listOne != NULL && listTwo != NULL)
        {
            if (listOne->data < listTwo->data)
            {
                mergedListTail->next = listOne;
                mergedListTail = mergedListTail -> next;

                // move pointer.
                listOne = listOne -> next;
            }
            else{
                mergedListTail->next = listTwo;
                mergedListTail = mergedListTail -> next;

                // move pointer.
                listTwo = listTwo ->next;

            }
        }

        // after the above loop end, it is obvious that one of the lists is non-empty.
        // So, connect the mergedListTail with that non-empty list.
        if(listOne != NULL)
        {
            mergedListTail -> next = listOne;
        }
        if(listTwo != NULL)
        {
            mergedListTail -> next = listTwo;
        }

        // return the head of mergerd list.
        return mergedListHead -> next;
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

    // List 1 Nodes.
    ListNode<int> *head1;
    ListNode<int> *ListNode2;
    ListNode<int> *ListNode3;
    ListNode<int> *ListNode4;
    ListNode<int> *ListNode5;
    ListNode<int> *ListNode6;

    // Initializing Nodes of List 1.
    ListNode6 = new ListNode<int>(10);
    ListNode5 = new ListNode<int>(9, ListNode6);
    ListNode4 = new ListNode<int>(6, ListNode5);
    ListNode3 = new ListNode<int>(5, ListNode4);
    ListNode2 = new ListNode<int>(3, ListNode3);
    head1 = new ListNode<int>(1, ListNode2);

    // List 2 Nodes.
    ListNode<int> *head2;
    ListNode<int> *node2;
    ListNode<int> *node3;
    ListNode<int> *node4;

    // Initializing Nodes of List 2.
    node4 = new ListNode<int>(4);
    node3 = new ListNode<int>(3, node4);
    node2 = new ListNode<int>(2, node3);
    head2 = new ListNode<int>(1, node2);

    // Solution.
    Solution S;
    cout<<"Both List Before Merging,\n";
    S.printList(head1);
    S.printList(head2);

    cout<<"After Merging,\n";
    ListNode<int> *ans = S.mergeTwoSortedLists(head1, head2);
    S.printList(head2);
}