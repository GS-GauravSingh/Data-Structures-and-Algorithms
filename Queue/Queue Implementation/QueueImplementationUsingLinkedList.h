#include <bits/stdc++.h>
using namespace std;

/* Forward decleration of Queue class. */
template <typename T>
class Queue;

/* Node Structure for Linked List. */
template <typename T>
class Node
{
private:
    /* Properties / Data Members. */
    T data;        // to store data.
    Node<T> *next; // pointer to next node.

public:
    /* Behavior / Methods. */
    // Constructor.
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

    // Declaring Queue class as a frient of Node class.
    // using this, Queue class can access the private data member of Node class.
    friend class Queue<T>;
};

/* Queue Class. */
template <typename T>
class Queue
{
private:
    /* Properties / Data Members. */
    Node<T> *head; // head points to the front element of the queue and we perform deletion/popping of element from head.

    Node<T> *tail; // tail points to the rear element (last element) of the queue and inserting of elements takes place from tail.

public:
    /* Behavior / Methods. */

    // Constructor.
    Queue()
    {
        // Initially when there is no element in the queue, both head and tail will point to NULL.
        // So, When head == NULL, it means linked list is empty (Queue is empty).
        // as we are using linked list. So, there is no overflow condition.
        head = tail = NULL;
    }

    /* Method to check if the queue is empty or not. */
    bool isEmpty()
    {
        // If head == NULL, it means the queue is empty.
        if (head == NULL)
        {
            // means queue is empty.
            return true;
        }
        else
        {
            // else head != tail, it means the queue is not empty.
            return false;
        }
    }

    /* Method to push element into the queue. */
    // Whenever we are pushing something into the queue it is know as enqueue.
    void enqueue(T data)
    {
        // As we are using linked list. So, there is no overflow condition.
        // Simply insert element into queue and insertion of elements takes place from rear/tail.

        // creating a new node.
        Node<T> *newNode = new Node<T>(data);

        // If head == NULL, it is obvoius that tail will also points to NULL.
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    /* Method to pop element form the queue. */
    // Whenever we are popping something from the queue it is know as dequeue.
    void dequeue()
    {
        // Checking for underflow condition.
        if (isEmpty())
        {
            // means, the Queue is empty.
            cerr << "Queue is empty.\n";
        }
        else
        {
            // If the queue is not empty, simply pop the front element (head).
            Node<T> *nodeToDelete = head; // storing the refernece of head.
            head = head->next;            // moving the head pointer one node ahead.

            nodeToDelete->next = NULL; // separating this node from the rest of the list.
            delete nodeToDelete;       // delete this node.
            nodeToDelete = NULL;
        }
    }

    /* Method to get the front element of the queue. */
    T front()
    {
        // Checking for underflow condition.
        if (isEmpty())
        {
            // means the queue is empty.
            cerr << "Queue is empty, Inserts some elements to get the front element.\n";
            return NULL;
        }
        else
        {
            return head->data;
        }
    }

    /* Method to get the rear element of the queue. */
    T rear()
    {
        // Checking for underflow condition.
        if (isEmpty())
        {
            // means the queue is empty.
            cerr << "Queue is empty, Inserts some elements to get the rear element.\n";
            return NULL;
        }
        else
        {
            return tail->data;
        }
    }

    /* Method to get the size of the queue. */
    int size()
    {
        // pointer to traverse the list.
        Node<T> *ptr = head;

        // to store the total number of element of the queue.
        int s = 0;

        while (ptr != NULL)
        {
            s++;
            ptr = ptr->next;
        }

        return s;
    }

    /* Destructor. */
    // Deleting the entire linked list using destructor.
    ~Queue()
    {
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }
};