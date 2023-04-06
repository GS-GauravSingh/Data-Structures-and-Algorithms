#include <bits/stdc++.h>
#include "../1. Node for Singly Linked List/SinglyLinkedListNode.h"
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
    /* Method to reverse linked list. */
    // Time Complexity :- O(n), n is the numbers of nodes in a Linked List.
    // Space Complexity :- O(1)
    ListNode<int> *reverseList(ListNode<int> *head)
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

            // move pointers.
            previousNode = currentNode;
            currentNode = nextNode;
        }

        // at this point your [previousNode] is the head of reversed linked list.
        return previousNode;
    }

    /* Method to insert node at the end. */
    // Time Complexity :- O(1)
    // Space Complexity :- O(1)
    void insertAtTail(ListNode<int> *&head, ListNode<int> *&tail, int digit)
    {

        // create a new node with given data.
        ListNode<int> *newNode = new ListNode<int>(digit);

        // if head == NULL, means list is empty.
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            // if head != NULL, means list is not empty.
            tail->next = newNode;
            tail = newNode;
        }
    }

    /* Method that add 1 in a number represented by linked list. */
    // Time Complexity :- O(n), n is the number of nodes in a linked list.
    // Space Complexity :- O(1)
    ListNode<int> *add(ListNode<int> *head)
    {
        /*

        When we perform addition of any 2 number, we get 2 this,
        1. first is carry.
        1. Second is digit to place in the summation.

        Example :-  9 + 9 = 18, 1 carray, 8 digit.

        // digit = sum%10; and carry = sum/10;
        */

        // answer list.
        ListNode<int> *ansHead = NULL;
        ListNode<int> *ansTail = NULL;

        // pointer to traverse the list's.
        ListNode<int> *ptr = head;

        // adding 1.
        ptr->data++;
        // cout<<ptr->data;

        // variable to store carry.
        int carry = 0;

        // this loop will terminate if one of the list's is exhausted.
        while (ptr != NULL)
        {
            // first take the summation.
            int sum = ptr->data + carry;

            // get the digit, digit = sum % 10.
            // example :- 9 + 9 = 18, digit = 18 % 10 = 8;
            int digit = sum % 10;

            // create a node for last digit and insert that node at the end in our answer list.
            insertAtTail(ansHead, ansTail, digit);

            // update carry, carry = sum/10.
            // example :- 9 + 9 = 18, digit = 18 % 10 = 8, carry = 18 / 10 = 1.8;
            // and we are storing carry in integer type variable. So, carry = 1.
            carry = sum / 10;

            // move pointers.
            ptr = ptr->next;
        }

        // if carry is remaining.
        while (carry > 0)
        {
            // first take the summation.
            int sum = carry;

            // get the digit, digit = sum % 10.
            // example :- 9 + 9 = 18, digit = 18 % 10 = 8;
            int digit = sum % 10;

            // create a node for last digit and insert that node at the end in our answer list.
            insertAtTail(ansHead, ansTail, digit);

            // update carry, carry = sum/10.
            // example :- 9 + 9 = 18, digit = 18 % 10 = 8, carry = 18 / 10 = 1.8;
            // and we are storing carry in integer type variable. So, carry = 1.
            carry = sum / 10;
        }


        return ansHead;
    }

public:
    /* Method that adds 1 in a number represented by linked list. */
    // Time Complexity :- O(n), n is the number of nodes in a linked list.
    // Space Complexity :- O(1)
    ListNode<int> *addOne(ListNode<int> *&first)
    {
        // Step 1:- Reverse the list, because we perform addition from left.
        ListNode<int> *firstReverse = reverseList(first);

        // Step 2 :- preform addition.
        ListNode<int> *ans = add(firstReverse);

        // Step 3 :- reverse answer list.
        ans = reverseList(ans);

        // Step 4:- return answer.
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

    // List 1 Nodes.
    ListNode<int> *head;
    ListNode<int> *ListNode2;

    // Initializing Nodes of List 1.
    ListNode2 = new ListNode<int>(9);
    head = new ListNode<int>(9, ListNode2);

    // Solution.
    Solution S;
    ListNode<int>* ans = S.addOne(head);
    S.printList(ans);
    
}