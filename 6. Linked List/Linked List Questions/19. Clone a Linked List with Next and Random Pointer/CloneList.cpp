#include <bits/stdc++.h>
using namespace std;

/* --------------------- Definition of a node with next and random pointer. ---------------------------*/
template <typename T>
class Node
{
private:
public:
    // data members.
    T val;
    Node<T> *next;
    Node<T> *random;

    // Default Constructor.
    Node()
    {
        this->val = 0;
        this->next = NULL;
        this->random = NULL;
    }

    // Parameterized Constructor.
    Node(T val)
    {
        this->val = val;
        this->next = NULL;
        this->random = NULL;
    }
};

/* ------------------------------- Solution Class --------------------------------------- */
class Solution
{
private:
    /* Method to insert node at the end. */
    // Time Complexity :- O(1)
    // Space Complexity :- O(1)
    void insertAtTail(Node<int> *&head, Node<int> *&tail, int data)
    {

        // create a new node with given data.
        Node<int> *newNode = new Node<int>(data);

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

    /* Method to clone list with next pointer. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    Node<int> *cloneWithNextPointer(Node<int> *head)
    {
        // clone list.
        Node<int> *ansHead = NULL;
        Node<int> *ansTail = NULL;

        // pointer to traverse list.
        Node<int> *ptr = head;
        while (ptr != NULL)
        {
            // create and insert node.
            insertAtTail(ansHead, ansTail, ptr->val);

            // move pointer.
            ptr = ptr->next;
        }

        return ansHead;
    }

public:
    // Approach 1:- using hashing.
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    Node<int> *copyRandomList_Approach_1(Node<int> *head)
    {

        // Step 1:- for now, forget about the random pointer and clone the list with the next pointer.
        Node<int> *cloneListHead = cloneWithNextPointer(head);

        // Step 2 :- in map, store the mapping of [original list Node -> clone list Node].
        unordered_map<Node<int> *, Node<int> *> mapping;

        // pointer to traverse original and clone list.
        Node<int> *originalList = head;
        Node<int> *cloneList = cloneListHead;

        while (originalList != NULL)
        {
            mapping[originalList] = cloneList;

            // move pointers.
            originalList = originalList->next;
            cloneList = cloneList->next;
        }

        // Step 3 :- now, clone random pointers.
        // cloneList -> random = mapping[originalList -> random].

        // pointer to traverse original and clone list.
        originalList = head;
        cloneList = cloneListHead;
        while (originalList != NULL)
        {
            cloneList->random = mapping[originalList->random];

            // move pointers.
            originalList = originalList->next;
            cloneList = cloneList->next;
        }

        // return clone list.
        return cloneListHead;
    }

    // Approach 2
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    Node<int> *copyRandomList_Approach_2(Node<int> *head)
    {

        // Step 1:- for now, forget about the random pointer and clone the list with the next pointer.
        Node<int> *cloneListHead = cloneWithNextPointer(head);

        /*
        Step 2:- insert node of clone list in between the original list.
        Example :-
        Original List : 1 -> 2 -> 3 -> 4 -> 5 -> NULL (for now, don't think about random pointer).

        and we can clone the original list with next pointer easily,
        clone List : 1 -> 2 -> 3 -> 4 -> 5 -> NULL (now only random pointer left).

        # Now, we have to create a mapping like this, So that we can set random pointers,

        Original List : 1 2 3 4 5 NULL
                        |/|/|/|/|/
        clone List :    1 2 3 4 5

        like this :- ol means original list node and cl means clone list node.
        ol -> cl -> ol -> cl -> ol -> cl -> ol -> cl -> ol -> cl -> NULL
        1  ->  1 ->  2 -> 2  -> 3  -> 3  -> 4  -> 4  -> 5  -> 5  -> NULL

        Now, we can simply set the random pointer.
        Like this,
        ptr
        1  ->  1 ->  2 -> 2  -> 3  -> 3  -> 4  -> 4  -> 5  -> 5  -> NULL

        ptr is use to traverse  the list.

        Random Pointer :- ptr -> next -> random = ptr -> random -> next.

        */

        // pointer to traverse original and clone list.
        Node<int> *originalList = head;
        Node<int> *cloneList = cloneListHead;

        while (originalList != NULL && cloneList != NULL)
        {
            // store the next node of original list.
            Node<int> *originalListNextNode = originalList->next;

            // make a connection, that original list node points to clone list node.
            originalList->next = cloneList;

            // move original node to next node.
            originalList = originalListNextNode;

            // store the next node of clone list.
            Node<int> *cloneListNextNode = cloneList->next;

            // make a connection, that clone list node points to original list node.
            cloneList->next = originalList;

            // move clone node to next node.
            cloneList = cloneListNextNode;
        }

        // Step 3 :- now, copy random pointers.
        // ptr -> next -> random = ptr -> random -> next;

        // pointer to traverse list.
        Node<int> *ptr = head;
        while (ptr != NULL)
        {
            // first check for NULL poiners.

            // if next pointer points to null, in this case random pointer doesn't exist.
            if (ptr->next != NULL)
            {
                if (ptr->random != NULL)
                {
                    ptr->next->random = ptr->random->next;
                }
                else
                {
                    // if ptr -> random  == NULL, in this case, ptr->next->random = NULL;
                    ptr->next->random = NULL;
                }
            }

            // move pointer 2 node at a time, beacuse we need to traverse in original list.
            ptr = ptr->next->next;
        }

        // Now, at this point, our list is ready.

        // Step 4 :- detach our list means reverse the cahges done in step 2.
        originalList = head;
        cloneList = cloneListHead;

        while (originalList != NULL && cloneList != NULL)
        {
            originalList -> next = cloneList -> next;
            originalList = originalList -> next;

            if(originalList != NULL)
            {
                cloneList -> next = originalList -> next;
            }
            cloneList = cloneList -> next;
        }

        // finally return answer;
        return cloneListHead;
    }
};

int main()
{
    // creating nodes of linked list.
    Node<int> *head;
    Node<int> *node1;
    Node<int> *node2;
    Node<int> *node3;
    Node<int> *node4;

    // Initializing nodes.
    head = new Node<int>(7);
    node1 = new Node<int>(13);
    node2 = new Node<int>(11);
    node3 = new Node<int>(10);
    node4 = new Node<int>(1);

    // setting next pointers.
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // setting random pointers.
    node1->random = head;
    node2->random = node4;
    node3->random = node2;
    node4->random = head;
}