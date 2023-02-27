#include <bits/stdc++.h>
using namespace std;

/* --------------------- Definition of a node with child and child pointer. ---------------------------*/

class Node
{
private:
public:
    // data members.
    int data;
    Node *next;
    Node *child;

    // Default Constructor.
    Node()
    {
        this->data = 0;
        this->child = NULL;
        this->child = NULL;
    }

    // Parameterized Constructor.
    Node(int data)
    {
        this->data = data;
        this->child = NULL;
        this->child = NULL;
    }
};

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    /* Method that merges 2 sorted Linked List. */
    // Time Complexity :- O(n), n is the number of nodes in a linked list.
    // Space Complexity :- O(1)
    Node *mergeTwoSortedLists(Node *first, Node *second)
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
        Node *mergedListHead = new Node(-1);
        Node *mergedListTail = mergedListHead;

        // pointer to traverse list's.
        Node *listOne = first;
        Node *listTwo = second;

        // this loop will terminate if one of the lists is exhausted.
        while (listOne != NULL && listTwo != NULL)
        {
            if (listOne->data < listTwo->data)
            {
                mergedListTail->child = listOne;
                mergedListTail = mergedListTail->child;

                // move pointer.
                listOne = listOne->child;
            }
            else
            {
                mergedListTail->child = listTwo;
                mergedListTail = mergedListTail->child;

                // move pointer.
                listTwo = listTwo->child;
            }
        }

        // after the above loop end, it is obvious that one of the lists is non-empty.
        // So, connect the mergedListTail with that non-empty list.
        if (listOne != NULL)
        {
            mergedListTail->child = listOne;
        }
        if (listTwo != NULL)
        {
            mergedListTail->child = listTwo;
        }

        // return the head of mergerd list.
        return mergedListHead->child;
    }

public:
    Node *flattenLinkedList(Node *&head)
    {
        // Base Case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Recursive Case.

        // First we go to the base case and while returning back from the base case,
        // we merge the list.

        Node *rightList = flattenLinkedList(head->next);

        // detach the current list from the child list.
        head->next = NULL;

        // merge both list into a sorted list.
        Node *mergeList = mergeTwoSortedLists(head, rightList);

        return mergeList;
    }

    /* Method to print List. */
    void printList(Node *head)
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->child;
        }
        cout << "NULL\n";
    }
};

int main()
{
    // creating nodes for linked list.

    /*
    List :-    1 -> 4 -> 7 -> 9 -> 20 -> NULL
               |    |    |    |
               2    5    8    12
               |    |    |    |
               3    6   Null Null
               |    |
             Null  Null
    */

    Node *head = new Node(1);
    Node *node2 = new Node(4);
    Node *node3 = new Node(7);
    Node *node4 = new Node(9);
    Node *node5 = new Node(20);

    // setting next pointers.
    head -> next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5 -> next = NULL;

    // setting child pointers for head.
    Node *headChild1 = new Node(2);
    Node *headChild2 = new Node(3);

    head->child = headChild1;
    headChild1->child = headChild2;

    // setting child pointers for node2.
    Node *node2Child1 = new Node(5);
    Node *node2Child2 = new Node(6);

    node2->child = node2Child1;
    node2Child1->child = node2Child2;

    // setting child pointers for node3.
    Node *node3Child = new Node(8);

    node3->child = node3Child;

    // setting child pointers for node4.
    Node *node4Child = new Node(12);

    node4->child = node4Child;

    // Solution.
    Solution S;
    Node *ans = S.flattenLinkedList(head);
    S.printList(ans);
}