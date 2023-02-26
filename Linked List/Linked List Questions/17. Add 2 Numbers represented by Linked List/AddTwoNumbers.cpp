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

    /* Method that add's numbers represented by 2 linked list. */
    // Time Complexity :- O(n), n is the number of nodes in a linked list.
    // Space Complexity :- O(1)
    ListNode<int> *add(ListNode<int> *&first, ListNode<int> *&second)
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
        ListNode<int> *firstList = first;
        ListNode<int> *secondList = second;

        // variable to store carry.
        int carry = 0;

        // this loop will terminate if one of the list's is exhausted.
        while (firstList != NULL && secondList != NULL)
        {
            // first take the summation.
            int sum = firstList->data + secondList->data + carry;

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
            firstList = firstList->next;
            secondList = secondList->next;
        }

        // if first list in not empty.
        while (firstList != NULL)
        {
            // first take the summation.
            int sum = firstList->data + carry;

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
            firstList = firstList->next;
        }

        // if second list in not empty.
        while (secondList != NULL)
        {
            // first take the summation.
            int sum = secondList->data + carry;

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
            secondList = secondList->next;
        }

        // if carry is remaining.
        while (carry)
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
    /* Method that adds 2 numbers represented by linked list. */
    // Time Complexity :- O(n), n is the number of nodes in a linked list.
    // Space Complexity :- O(1)
    ListNode<int> *addTwoNumbers(ListNode<int> *&first, ListNode<int> *&second)
    {
        // Step 1:- Reverse both list's, because we perform addition from left.
        ListNode<int> *firstReverse = reverseList(first);
        ListNode<int> *secondReverse = reverseList(second);

        // Step 2 :- preform addition.
        ListNode<int> *ans = add(firstReverse, secondReverse);

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
    ListNode<int> *head1;
    ListNode<int> *ListNode2;

    // Initializing Nodes of List 1.
    ListNode2 = new ListNode<int>(9);
    head1 = new ListNode<int>(9, ListNode2);

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
    ListNode<int> *ans = S.addTwoNumbers(head1, head2);
    S.printList(ans);
}