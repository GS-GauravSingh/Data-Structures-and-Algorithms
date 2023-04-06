#include <bits/stdc++.h>
#include "../1. Node for Singly Linked List/SinglyLinkedListNode.h"
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /* Method that sort the list of 0's, 1's and 2's. */

    // Approach 1 :- Count the number of 0's, 1's and 2's and update the answer.
    // Time Complexity :- O(n), n is the number of nodes in a linked list.
    // Space Complexity :- O(1)
    void sortList_Approach_1(ListNode<int> *&head)
    {
        // Base Cases
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        // pointer to traverse list.
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;

        // pointer to traverse linked list.
        ListNode<int> *ptr = head;

        while (ptr != NULL)
        {
            if (ptr->data == 0)
            {
                zeroCount++;
            }
            else if (ptr->data == 1)
            {
                oneCount++;
            }
            else
            {
                twoCount++;
            }

            // move pointer.
            ptr = ptr->next;
        }

        // update the list.
        ptr = head;
        while (ptr != NULL)
        {
            if (zeroCount != 0)
            {
                ptr->data = 0;
                zeroCount--;
            }
            else if (oneCount != 0)
            {
                ptr->data = 1;
                oneCount--;
            }
            else
            {
                ptr->data = 2;
                twoCount--;
            }

            // move pointer.
            ptr = ptr->next;
        }
    }

    // Approach 2 :- In Above approach, we replace the data, but if the data replacement is not allowed, then you need to change the links.
    // Create 3 seperate linked list, one for 0, one for 1 and one for 2, and in last merge all 3 linked lists.
    // Time Complexity :- O(n), n is the number of nodes in a linked list.
    // Space Complexity :- O(1)
    void sortList_Approach_2(ListNode<int> *&head)
    {
        // Base Cases
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        // 3 seperate linked list, one for 0, one for 1 and one for 2.
        ListNode<int> *zeroHead = new ListNode<int>(-1);
        ListNode<int> *zeroTail = zeroHead;

        ListNode<int> *oneHead = new ListNode<int>(-1);
        ListNode<int> *oneTail = oneHead;

        ListNode<int> *twoHead = new ListNode<int>(-1);
        ListNode<int> *twoTail = twoHead;

        // pointer to traverse linked list.
        ListNode<int> *currentNode = head;

        while (currentNode != NULL)
        {
            if (currentNode->data == 0)
            {
                zeroTail->next = currentNode;
                zeroTail = currentNode;
            }
            else if (currentNode->data == 1)
            {
                oneTail->next = currentNode;
                oneTail = currentNode;
            }
            else if (currentNode->data == 2)
            {
                twoTail->next = currentNode;
                twoTail = currentNode;
            }

            // move pointer.
            currentNode = currentNode->next;
        }

        // merge all 3 lists.
        // connections.

        // checking if 1's list is empty or not.
        if (oneHead->next != NULL)
        {
            // means, 1's list is not empty.
            zeroTail->next = oneHead->next;
        }
        else
        {
            // means, 1's list is mepty.
            zeroTail->next = twoHead->next;
        }

        oneTail->next = twoHead->next;
        twoTail->next = NULL;

        // update head.
        head = zeroHead -> next;
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
    node6 = new ListNode<int>(2);
    node5 = new ListNode<int>(0, node6);
    node4 = new ListNode<int>(2, node5);
    node3 = new ListNode<int>(0, node4);
    node2 = new ListNode<int>(1, node3);
    head = new ListNode<int>(1, node2);

    // Solution.
    Solution S;
    cout << "Before Sorting : ";
    S.printList(head);
    cout << "After Sorting : ";
    S.sortList_Approach_2(head);
    S.printList(head);
}