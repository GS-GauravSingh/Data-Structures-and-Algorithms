#include <bits/stdc++.h>
using namespace std;

// Forward Decleration.
template <typename T>
class DoublyLinkedList;

/* ----------------------- Node for Doubly Linked List ----------------------------------- */
template <typename T>
class Node
{
private:
    // Because this is a templated class that's why the type of variable is T.
    T data;
    Node<T> *previous;
    Node<T> *next;

public:
    // Default Constructor.
    Node()
    {
        this->data = 0;
        this->previous = NULL;
        this->next = NULL;
    }

    // Parameterized Constructor.
    Node(T data)
    {
        this->data = data;
        this->previous = NULL;
        this->next = NULL;
    }

    // Destructor.
    // Deleting entire linked list using destructor.
    ~Node()
    {
        // This if block is like a recursive call
        // This will make a recursive call till next != NULL
        // And when next == NULL, then it will return from there and delete the nodes in reverse order.
        if (next != NULL)
        {
            delete next;
        }
    }

    // using this, DoublyLinkedList class can access
    // the private data member of Node class.
    friend class DoublyLinkedList<T>;
};

/*----------------------------- Doubly Linked List Class ---------------------------- */
template <typename T>
class DoublyLinkedList
{
private:
    // head points to the starting node of the linked list.
    Node<T> *head;

    // tail points to the last node of the linked list.
    Node<T> *tail;

    // variable to store total number of element in the linked list.
    int totalElement;

public:
    // default Constructor.
    DoublyLinkedList()
    {
        head = tail = NULL;

        // initially the linked list is empty.
        totalElement = 0;
    }

    /* Method to Print/Traverse Doubly Linked List. */
    void printDoublyList()
    {
        // pointer to traverse Doubly linked list.
        Node<T> *ptr = head;

        while (ptr != NULL)
        {
            // print the data.
            cout << ptr->data << " -> ";

            // move the pointer.
            ptr = ptr->next;
        }
        cout << " NULL \n";
    }

    /* Method to count total number of nodes in a Singly Linked List. */
    int elementCount()
    {
        // pointer to traverse linked list.
        Node<T> *ptr = head;

        while (ptr != NULL)
        {
            totalElement++;

            // move the pointer.
            ptr = ptr->next;
        }
        return totalElement;
    }

    // Insert Node at the beginning of the Doubly linked List.
    void push_front(T data)
    {
        // As we are inserting at head. So, our perv pointer will points to NULL.

        // Here we have two cases,
        // 1. If both head and tail points to NULL, it means the linked list is empty.
        // So, in this case, Create a new Node and point the head and tail to new node.
        if (head == NULL)
        {
            // creating a new node.
            Node<T> *newNode = new Node<T>(data);

            // pointing head and tail to new node.
            head = tail = newNode;
        }

        // 2. if head and tail both are not NULL, it means there is an existing linked list,
        //  and you have to insert new node in the beinning.
        else
        {
            // creating a new node.
            Node<T> *newNode = new Node<T>(data);

            // make connections.
            newNode->next = head;
            newNode->previous = head;

            // made this newNode the head node.
            head = newNode;
        }
    }

    // Insert the Node at the end of the Doubly Linked List.
    void push_back(T data)
    {
        // Here we have two cases,
        // 1. If both head and tail points to NULL, it means the linked list is empty.
        // So, in this case, Create a new Node and point the head and tail to new node.
        if (head == NULL)
        {
            // creating a new node.
            Node<T> *newNode = new Node<T>(data);

            // pointing head and tail to new node.
            head = tail = newNode;
        }

        // 2. if head and tail both are not NULL, it means there is an existing linked list,
        //  and you have to insert new node at the end.
        else
        {
            // creating a new node.
            Node<T> *newNode = new Node<T>(data);

            // make connections.
            tail->next = newNode;
            newNode->previous = tail;

            // made this newNode the tail node.
            tail = newNode;
        }
    }

    // Insert the Node at the given position.
    // In this, I'm taking 0-based indexing.
    void insertAt(T data, int pos)
    {
        // Corner case
        if (pos > elementCount())
        {
            cout << "Invalid Index !!\n";
            return;
        }

        if (pos == 0)
        {
            // Insert at begining.
            push_front(data);
        }
        else
        {
            Node<T> *ptr = head;
            for (int jump = 1; jump <= pos; jump++)
            {
                ptr = ptr->next;
            }

            // after the above loop end, Our ptr pointer will points to index where we want to insert the node.
            Node<T> *newNode = new Node<T>(data); // new node.

            // making connections.
            ptr->previous->next = newNode;
            newNode->previous = ptr->previous;

            newNode->next = ptr;
            ptr->previous = newNode;
        }
    }

    // Deletion entire linked list using destructor.
    ~DoublyLinkedList()
    {
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }

    // Deleting the front node of the Doubly Linked List.
    void pop_front()
    {
        // if head points to NULL, it means linked list is empty.
        if (head == NULL)
        {
            cout << "Doubly Linked List is already Empty.\n";
        }
        else if (head->next == NULL)
        {
            // it means, the linked list has only one element.
            delete head;
            head = NULL;
        }
        else
        {
            // for rest of the cases, simply deleted the front node.
            Node<T> *nodeToDelete = head;
            head = head->next;
            head->previous = NULL;

            nodeToDelete->next = NULL;

            delete nodeToDelete;
            nodeToDelete = NULL;
        }
    }

    // Deleting the last node of the Doubly Linked List.
    void pop_back()
    {
        // if head points to NULL, it means linked list is empty.
        if (head == NULL)
        {
            cout << "Doubly Linked List is already Empty.\n";
        }
        else if (head->next == NULL)
        {
            // it means, the linked list has only one element.
            delete head;
            head = NULL;
        }
        else
        {
            // for rest of the cases, simply deleted the last node.
            Node<T> *nodeToDelete = tail;
            Node<T> *nodeBeforeTail = tail->previous;

            nodeBeforeTail->next = tail->next;

            tail->previous = NULL;
            tail = nodeBeforeTail;

            delete nodeToDelete;
            nodeToDelete = NULL;
        }
    }

    // Deleting node at the given position.
    // In this, I'm taking 0-based indexing.
    void deleteAt(int pos)
    {
        if (pos == 0)
        {
            // delete the front node.
            pop_front();
        }
        else
        {
            Node<T> *ptr = head;
            for (int jump = 1; jump <= pos; jump++)
            {
                ptr = ptr->next;
            }

            // after the above loop end, Our ptr pointer will points to the node which we have to delete.
            Node<T> *nodeToDelete = ptr;

            ptr->prevoius->next = ptr->next;
            ptr->next->previous = ptr->previous;

            nodeToDelete->next = NULL;
            nodeToDelete->previous = NULL;
            delete nodeToDelete;
            nodeToDelete = NULL;
        }
    }
};
