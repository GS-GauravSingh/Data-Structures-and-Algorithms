#include <bits/stdc++.h>
#include "../1. Node for Singly Linked List/SinglyLinkedListNode.h"
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    /* method to reverse linked list. */
    ListNode<int> *reverseList(ListNode<int> *head)
    {
        // pointers.
        ListNode<int> *currentNode = head;
        ListNode<int> *previousNode = NULL;
        ListNode<int> *nextNode = NULL;

        while (currentNode != NULL)
        {
            // store the reference/address of next node.
            nextNode = currentNode->next;

            // make a connection, that current node points to previous node.
            currentNode->next = previousNode;

            // move pointers.
            previousNode = currentNode;
            currentNode = nextNode;
        }

        // after the above loop ends, previousNode is the head of reverse linked list.
        return previousNode;
    }

public:
    /* Method to check if a linked list is palindrome or not. */
    // Time Complexity :- O(n), n is the number of nodes in a linked list.
    // Space Complexity :- O(1)
    bool checkPalindrome(ListNode<int> *head)
    {
        // Base Case
        if (head == NULL || head->next == NULL)
        {
            return true;
        }

        // Step 1 :- Reverse the linked list.
        ListNode<int> *reverseHead = reverseList(head);

        // Step 2 :- compare the original list with reversed list and check if the list is palindrome or not.
        // pointer to traverse both the lists.
        ListNode<int> *originalList = head;
        ListNode<int> *reverseList = reverseHead;
        while (originalList != NULL && reverseList != NULL)
        {
            if (originalList->data != reverseList->data)
            {
                return false;
            }

            // move pointers.
            originalList = originalList -> next;
            reverseList = reverseList -> next;
        }

        return true;
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
    node6 = new ListNode<int>(1);
    node5 = new ListNode<int>(2, node6);
    node4 = new ListNode<int>(3, node5);
    node3 = new ListNode<int>(3, node4);
    node2 = new ListNode<int>(2, node3);
    head = new ListNode<int>(1, node2);

    // Solution.
    Solution S;
    S.printList(head);
    bool isPalindrome = S.checkPalindrome(head);
    if (isPalindrome == true)
    {
        cout << "Linked List is Palindrome.";
    }
    else
    {
        cout << "Linked List is not a Palindrome.";
    }
}