#include <bits/stdc++.h>
using namespace std;

/*
Your task is to implement a stack which will support the following operations in O(1) time complexity.
1) push() which adds an element to the top of stack (standard stack operations).
2) pop() which removes an element from top of stack (standard stack operations).
3) findMiddle() which will return middle element of the stack.
4) deleteMiddle() which will delete the middle element of the stack.

3rd and 4th are the method which you need to implement using only constant i.e., O(1) time complexity.

*/

/*
------------------------- Intution to Solve the Problem -----------------------------------------
Intution :- As we know that we cam implement the stack using Array and Linked List.

Array :- In case of array, we can easily find the middle element (using indexes), but deletion in constant time is not possible in array. So, we cannot use array to implement the stack.

Singly Linked List :- In case of Singly Linked List, we can keep track of the middle element and in this way we can get the middle element in O(1) time, but deletion of middle element is not possible in O(1) time because to delete a node in a linked list we need a pointer to previous node and previous node pointer will point to the node just behind the node which we have to delete and to get this previous pointer we need to traverse the entire linked list because node in a singly linked list will have only pointer to next node.

So, The Idea is to use the Double Linked List.

Double Linked List :- In case of Doubly Linked List, we can keep track of the middle element and in this way we can get the middle element in O(1) time and deletion is also possible in O(1) time because node in a Doubly linked list will have the pointer to its next and prevoius node. That's why it is easy to delete a node and making connections in O(1) time.
*/

/* Forward decleration of the Stack class.*/
class Stack;

/* ----------------------------- Doubly Linked List Node------------------------------- */
class Node
{
private:
    /* Data Members / Properties of the Node class. */
    int data;
    Node *next;
    Node *previous;

public:
    /* Methods / Behavior of the Node class. */

    // Parameterized Constructor.
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }

    // Destructor.
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }

    // Declaring Stack class as a friend of Node Class.
    // Suing this the Stack class can access the private data members of the Node class.
    friend class Stack;
};

/* ----------------------------- Stack Class ------------------------------------------ */
class Stack
{
private:
    /* Data Members / Properties of the Stack class. */
    Node *head;   // all insertions and deletion take palce at head.
    Node *mid;    // pointer to track the middle element.
    int size = 0; // to store the size of the stack.
public:
    /* Methods / Behavior of the Stack class. */
    // Constructor.
    Stack()
    {
        head = NULL;
    }

    /* Method to push data into the stack. */
    void push(int data)
    {
        // creating new node.
        Node *newNode = new Node(data);

        // Inserting node at head.
        if (head == NULL)
        {
            // It means, we are going to insert the first node.
            head = newNode;

            // Update mid.
            mid = newNode;

            // update size.
            size++;
        }
        else
        {
            // making connections.
            newNode->next = head;
            head->previous = newNode;

            // make newNode as Head node.
            head = newNode;

            // update size.
            size++;

            // Now, according to the size of the stack, update the mid pointer.
            // Move mid pointer one node back (because we are inserting node at the head of the list) only when the size of the list/stack is even.
            if (size % 2 == 0)
            {
                mid = mid->previous;
            }
        }
    }

    /* Method to pop data from the stack. */
    void pop()
    {
        // Perform deletion from head.
        if (head == NULL)
        {
            cout << "Stack is Empty.\n";
        }
        else if (head->next == NULL)
        {
            // Only One node is present in the Doubly Linked List.
            delete head;
            head = NULL;
        }
        else
        {
            // for rest of the case, simply delete the head node.

            Node *nodeToDelete = head; // storing the reference of head node.
            head = head->next;         // move head one node ahead.

            // seperating the node which we to delete from the rest of the list.
            nodeToDelete->next = NULL;
            head->previous = NULL;

            // delete node.
            delete nodeToDelete;
            nodeToDelete = NULL;
        }

        // decrement the size.
        size--;

        // Updating mid pointer.
        // Now, according to the size of the stack, update the mid pointer.
        // Move mid pointer one node ahead (because we are inserting node at the head of the list) only when the size of the list/stack is odd.
        if (size % 2 == 1)
        {
            mid = mid->next;
        }

        // corner case.
        if (size == 1)
        {
            mid = head;
        }
    }

    /* Method to check if stack is empty or not. */
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    /* Method to get the top element of the Stack. */
    int top()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return head->data;
        }
    }

    /* Method to print Stack. */
    void printStack()
    {
        Node *ptr = head;
        if (size == 0)
        {
            cout << "Stack is empty.\n";
            return;
        }
        while (ptr != NULL)
        {
            cout << ptr->data << endl;
            ptr = ptr->next;
        }
        cout << endl;
    }

    /* Method to find the Middle element of the stack. */
    int findMiddle()
    {
        if (isEmpty())
        {
            return -1;
        }
        return mid->data;
    }

    /* Method to delete the Middle element of the stack. */
    void deleteMiddle()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }

        if (size == 1)
        {
            // means stack only has one element.
            delete head; // mid == head
            head = NULL;
            mid = NULL;

            size--;
        }
        else if (size == 2)
        {
            Node *nodeToDelete = head;

            head = head->next;
            mid = mid->next;

            head->previous = NULL;
            mid->previous = NULL;
            nodeToDelete -> next = NULL;

            delete nodeToDelete;
            nodeToDelete = NULL;

            size--;
        }
        else
        {
            Node *nodeToDelete = mid;
            mid->next->previous = mid->previous;
            mid->previous->next = mid->next;

            size--;

            // update mid.
            if (size % 2 == 0)
            {
                mid = mid->previous;
            }
            else
            {
                mid = mid->next;
            }

            nodeToDelete->next = NULL;
            nodeToDelete->previous = NULL;
            delete nodeToDelete;
            nodeToDelete = NULL;
        }
    }
};
int main(void)
{
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    // s.printStack();

    // cout << s.top() << endl;
    // s.pop();
    // cout << s.top() << endl;
    // s.pop();
    // cout << s.top() << endl;
    // s.pop();
    // cout << s.top() << endl;
    // s.pop();
    // cout << s.top() << endl;

    // mid element.
    // s.printStack();
    // cout << "Middle Element is : " << s.findMiddle() << endl;

    // s.pop();
    // s.printStack();
    // cout << "Middle Element is : " << s.findMiddle() << endl;

    // s.pop();
    // s.printStack();
    // cout << "Middle Element is : " << s.findMiddle() << endl;

    // s.pop();
    // s.printStack();
    // cout << "Middle Element is : " << s.findMiddle() << endl;

    // s.pop();
    // s.printStack();
    // cout << "Middle Element is : " << s.findMiddle() << endl;

    // deleting middle element.
    cout << "Printing stack.\n";
    s.printStack();
    cout << "Middle Element is : " << s.findMiddle() << endl;
    cout << "Deleting middle element ...\n";
    s.deleteMiddle();

    cout << "Printing stack.\n";
    s.printStack();

    cout << "Middle Element is : " << s.findMiddle() << endl;
    cout << "Deleting middle element ...\n";
    s.deleteMiddle();


    cout << "Printing stack.\n";
    s.printStack();

    cout << "Middle Element is : " << s.findMiddle() << endl;
    cout << "Deleting middle element ...\n";
    s.deleteMiddle();


    cout << "Printing stack.\n";
    s.printStack();

    cout << "Middle Element is : " << s.findMiddle() << endl;
    cout << "Deleting middle element ...\n";
    s.deleteMiddle();

    cout << "Printing stack.\n";
    s.printStack();


    cout << "Middle Element is : " << s.findMiddle() << endl;
    cout << "Deleting middle element ...\n";
    s.deleteMiddle();


    cout << "Printing stack.\n";
    s.printStack();


    cout << "Middle Element is : " << s.findMiddle() << endl;
    cout << "Deleting middle element ...\n";
    s.deleteMiddle();

    cout << "Printing stack.\n";
    s.printStack();
}