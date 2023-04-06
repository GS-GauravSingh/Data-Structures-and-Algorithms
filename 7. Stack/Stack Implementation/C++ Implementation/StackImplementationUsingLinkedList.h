// Since we are using Linked List, we can push as many elements in our Linked List without any problem related to size.
// Our top element in case of LL is head.
// We perform insertion and deletion from head we don't need tail pointer in this case.

#include <bits/stdc++.h>
using namespace std;

/* Forward decleration of Stack class. We have to declare Stack class, because we are using Stack class inside Node Class. */
template <typename T>
class Stack;

/* Node Structure for Stack. */
template <typename T>
class Node
{
private:
    /* Data Members. */
    T data;
    Node<T> *next;

public:
    // Default Constructor.
    Node()
    {
        data = NULL;
        next = NULL;
    }

    // Paramterized Constructor.
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor.
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }

    // using this, Stack class can access the private data members of Node class.
    friend class Stack<T>;
};

/* Stack Class. */
template <typename T>
class Stack
{
private:
    /* Data Members. */
    Node<T> *head;

public:
    // Default Constructor.
    Stack()
    {
        head = NULL;
    }

    /* Method to push element in stack. */
    void push(T data)
    {
        // In case of a Linked List, there is no need to bother about overflow.

        // Creating a new node.
        Node<T> *newNode = new Node<T>(data);

        // if head == NULL, means linked list is empty.
        // So, Insert first element in stack.
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            // When list is not empty, then insert newNode at head.
            newNode->next = head;
            head = newNode;
        }
    }

    /* Method to pop element from stack. */
    void pop()
    {
        // checking for underflow.
        if (isEmpty())
        {
            // means, stack is already empty.
            cerr << "Stack Underflow.\n";
        }
        else
        {
            // Perform deletion from head.
            // delete the head node.

            Node<T> *nodeToDelete = head; // storing the reference of head.
            head = head->next;            // moving the head pointer.

            nodeToDelete->next = NULL;
            delete nodeToDelete;
            nodeToDelete = NULL;
        }
    }

    /* Method to get the top element of stack. */
    T top()
    {
        // checking for underflow.
        if (isEmpty())
        {
            // means, stack is already empty.
            cerr << "Stack Underflow.\n";
            return -1;
        }
        else
        {
            return head->data;
        }
    }

    /* Method to check if stack is empty or not. */
    bool isEmpty()
    {
        if (head == NULL)
        {
            // means, linked list is empty.
            return true;
        }
        return false;
    }

    /* Destructor. */
    ~Stack()
    {
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }
};
