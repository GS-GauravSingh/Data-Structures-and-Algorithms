#include <bits/stdc++.h>
#include "../1. Node for Singly Linked List/SinglyLinkedListNode.h"
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    /* Method to find middle node of a linked list. */
    // Time Complexity :- O(n/2) => O(n), n is the numbers of nodes in a Linked List.
    // Space Complexity :- O(1)
    ListNode<int> *getMiddleNode(ListNode<int> *&head)
    {

        // Using, fast and slow pointer technique (also known as the tortoise and hare algorithm).
        // slow pointer move 1 node at a time.
        // fast pointer move 2 node at a time.
        ListNode<int> *slow = head;
        ListNode<int> *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    /* --------------------------------  Merge Sort Code ----------------------------------- */

    /* Method that merges 2 sorted Linked List. */
    // Time Complexity :- O(n), n is the number of nodes in a linked list.
    // Space Complexity :- O(1)
    ListNode<int> *merge(ListNode<int> *&first, ListNode<int> *&second)
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
                mergedListTail = mergedListTail->next;

                // move pointer.
                listOne = listOne->next;
            }
            else
            {
                mergedListTail->next = listTwo;
                mergedListTail = mergedListTail->next;

                // move pointer.
                listTwo = listTwo->next;
            }
        }

        // after the above loop end, it is obvious that one of the lists is non-empty.
        // So, connect the mergedListTail with that non-empty list.
        if (listOne != NULL)
        {
            mergedListTail->next = listOne;
        }
        if (listTwo != NULL)
        {
            mergedListTail->next = listTwo;
        }

        // return the head of mergerd list.
        return mergedListHead->next;
    }

    /* Merge Sort */
    // Time Complexity :- O(n log(n))
    // Space Complexity :- O(log(n))
    ListNode<int> *mergeSort(ListNode<int> *&head)
    {
        // Base Case
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        // Recursive Case.

        // Step 1 :- find the middle node of the linked list.
        ListNode<int> *middleNode = getMiddleNode(head);


        // Step 2 :- divide the linked list inot 2 halfs,
        // first half is from head to mid and,
        // second half is from mid -> next to end.

        // left half.
        ListNode<int> *leftHalfHead = head;

        // storing the starting node of right half.
        ListNode<int> *rightHalfHead = middleNode->next;

        // breaking the list from middle node.
        middleNode->next = NULL;

        // Step 3 :- make a recursive calls for both the half.
        // left half.
        leftHalfHead = mergeSort(leftHalfHead);

        // right half.
        rightHalfHead = mergeSort(rightHalfHead);


        // Step 4 :- merge both the halfs.
        ListNode<int> *result = merge(leftHalfHead, rightHalfHead);

        // Step 5 :- return ans;
        return result;
    }

public:
    /* Main method for calling merge sort. */
    ListNode<int> *sortList(ListNode<int> *&head)
    {
        ListNode<int> *ans = mergeSort(head);
        return ans;
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
    // ListNode<int> *node7;

    // Initializing Nodes.
    node5 = new ListNode<int>(1);
    node4 = new ListNode<int>(2, node5);
    node3 = new ListNode<int>(3, node4);
    node2 = new ListNode<int>(4, node3);
    head = new ListNode<int>(5, node2);

    // Solution.
    Solution S;

    ListNode<int> *ans = S.sortList(head);
    S.printList(ans);
}