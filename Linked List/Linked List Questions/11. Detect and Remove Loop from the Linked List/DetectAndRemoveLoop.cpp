#include <bits/stdc++.h>
#include "../1. Node for Singly Linked List/SinglyLinkedListNode.h"
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    /* Method to check if the Linked List has cycle or not. */
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

    /* Method that returns the start node of cycle. */
    // Time Complexity :- O(n), n is the number of nodes in a linked list.
    // Space Complexity :- O(1)
    ListNode<int> *startNodeOfCycle(ListNode<int> *head)
    {
        // Base case.
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }

        // First check if the linked list contains cycle or not.
        // If there is not cycle in a linked list, there is no starting node of cycle. Simply return NULL.
        if (hasCycle(head) == false)
        {
            return NULL;
        }

        // If cycle is present in a linked list.
        // Return the starting node of the cycle.

        // Using Floyd Cycle Detection Algorithm.
        // Step 1:- Run a loop until slow is not equal to fast and when if slow == fast, then break the loop.
        ListNode<int> *slow = head;
        ListNode<int> *fast = head;
        while (true)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                // if slow == fast, then break the loop.
                break;
            }
        }

        // Step 2:- Initialize slow = head and take fast as it is and move both pointer one node at a time.
        // and the node at which both pointer's meet, that node is the starting node of the cycle.
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // or you can return fast also.
    }

    /* Method that returns the Node just before the Starting Node of the Linked List Cycle */
    // Time Complexity :- O(n), n is the number of nodes in a linked list.
    // Space Complexity :- O(1)
    ListNode<int> *nodeBeforeStartingNodeOfCycle(ListNode<int> *head)
    {
        // Base case.
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }

        // First check if the linked list contains cycle or not.
        // If there is not cycle in a linked list, there is no starting node of cycle. Simply return NULL.
        if (hasCycle(head) == false)
        {
            return NULL;
        }

        // If cycle is present in a linked list.

        // Step 1:- get the starting node of cycle.
        ListNode<int> *startNode = startNodeOfCycle(head);

        // Step 2:- traverse the list and find the node before startnode.
        ListNode<int> *ptr = startNode->next;
        while (ptr->next != startNode)
        {
            ptr = ptr->next;
        }

        return ptr;
    }

public:
    /* Method to Detect and Remove Loop. */
    // Time Complexity :- O(n), n is the number of nodes in a linked list.
    // Space Complexity :- O(1)
    void detectAndRemove(ListNode<int> *&head)
    {
        // Base case.
        if (head == NULL || head->next == NULL)
        {
            return;
        }

        // First check if the linked list contains cycle or not.
        // If there is no cycle in a linked list, then there is no loop.
        if (hasCycle(head) == false)
        {
            return;
        }

        // If cycle is present in a linked list.
        // get the node just before the starting node of cycle.
        ListNode<int> *nodeBeforeStartOfCycle = nodeBeforeStartingNodeOfCycle(head);

        // traverse the list and point the avobe node to null.
        ListNode<int> *ptr = head;
        while (ptr != nodeBeforeStartOfCycle)
        {
            ptr = ptr->next;
        }

        // remove the loop.
        ptr->next = NULL;
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

    node5 = new ListNode<int>(5);
    node4 = new ListNode<int>(4, node5);
    node3 = new ListNode<int>(3, node4);
    node2 = new ListNode<int>(2, node3);
    head = new ListNode<int>(1, node2);

    // cyclic connection.
    node5->next = node2;

    /*
    List = 1 -> 2 -> 3 -> 4 -> 5
                ^              |
                |              |
                - - - < - - - -

    cycle :  2 -> 3 -> 4 -> 5
             ^              |
             |              |
             - - - < - - - -

    Starting Node of Cycle = 2.
    Node just before the Starting Node of the Linked List Cycle = 5.

    Your task is to remove the cycle, after removing the cycle, the list would look like this,
    List = 1 -> 2 -> 3 -> 4 -> 5 -> NULL

    Approach :- Simple find the Node just before the Starting Node of the Linked List Cycle (5) and point that node to NULL.

    */

    // Solution.
    Solution S;
    S.detectAndRemove(head);
    S.printList(head);
}