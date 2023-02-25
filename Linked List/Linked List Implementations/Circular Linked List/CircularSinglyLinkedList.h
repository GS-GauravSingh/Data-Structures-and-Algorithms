#include <bits/stdc++.h>
using namespace std;

// Forward Decleration.
template <typename T>
class CircularSinglyLinkedList;

/* --------------------------------- Node for Circular Singly Linked List ------------------------------------- */
template <typename T>
class Node
{
private:
    // Because this is a templated class that's why the type of variable is T.
    T data;
    Node<T> *next;

public:
    // Default Constructor.
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    // Parameterized Constructor.
    Node(T data)
    {
        this->data = data;
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
            next = NULL;
        }
    }

    // using this, CircularSinglyLinkedList class can access
    // the private data member of Node class.
    friend class CircularSinglyLinkedList<T>;
};

/* --------------------------------- Singly Linked List ------------------------------------------ */
template <typename T>
class CircularSinglyLinkedList
{
private:
    // tail points to the last node of the linked list.
    Node<T> *tail;

    // There is no need for creating head node, because in circular linked list last node points to head node.
    // Head = tail -> next;

    // variable to store total number of element in the linked list.
    int totalElement;

public:
    // default Constructor.
    CircularSinglyLinkedList()
    {
        tail = NULL;

        // initially the linked list is empty.
        totalElement = 0;
    }

    /* Method to Print/Traverse Circular Singly Linked List. */
    void printCircularSinglyList()
    {
        // pointer to traverse Circular singly linked list.
        Node<T> *head = tail->next;
        Node<T> *ptr = head;

        do
        {
            cout << ptr->data << " -> ";
            ptr = ptr->next;
        } while (ptr != head);

        cout<<endl;
    }

    /* Method to count total number of nodes in a Singly Linked List. */
    int elementCount()
    {
        // pointer to traverse Circular singly linked list.
        Node<T> *head = tail->next;
        Node<T> *ptr = head;

        do
        {
            totalElement++;
            ptr = ptr->next;
        } while (ptr != head);

        return totalElement;
    }

    // Insert Node at the beginning of the Singly linked List.
    void push_front(T data)
    {
        // Here we have two cases,
        // 1. If tail points to NULL, it means the linked list is empty.
        // So, in this case, Create a new Node and point the head and tail to new node.
        if (tail == NULL)
        {
            // creating a new node.
            Node<T> *newNode = new Node<T>(data);

            // pointing head and tail to new node.
            tail = newNode;
            tail->next = newNode;
        }

        // 2. if tail is not NULL, it means there is an existing linked list,
        //  and you have to insert new node in the beinning.
        else
        {
            // creating a new node.
            Node<T> *newNode = new Node<T>(data);
            Node<T> *head = tail->next;

            newNode->next = head;
            tail->next = newNode;
        }
    }

    // Insert the Node at the end of the Singly Linked List.
    void push_back(T data)
    {
        // Here we have two cases,
        // 1. If tail points to NULL, it means the linked list is empty.
        // So, in this case, Create a new Node and point the head and tail to new node.
        if (tail == NULL)
        {
            // creating a new node.
            Node<T> *newNode = new Node<T>(data);

            // pointing head and tail to new node.
            tail = newNode;
            tail->next = newNode;
        }

        // 2. if tail is not NULL, it means there is an existing linked list,
        //  and you have to insert new node at the end.
        else
        {
            // creating a new node.
            Node<T> *newNode = new Node<T>(data);

            Node<T> *head = tail->next;

            // point tail to newNode.
            tail->next = newNode;

            // made this newNode the tail node.
            tail = newNode;

            // circular connection.
            tail->next = head;
        }
    }

    // Insert the Node at the given position.
    // In this, I'm taking 0-based indexing.
    void insertAt(T data, int pos)
    {

        if (pos == 0)
        {
            // Insert at begining.
            push_front(data);
        }
        else
        {
            Node<T> *head = tail->next;
            Node<T> *ptr = head;
            for (int jump = 1; jump < pos; jump++)
            {
                ptr = ptr->next;
            }

            // after the above loop end, Our ptr pointer will points to (pos - 1)th node.
            Node<T> *newNode = new Node<T>(data);
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
    }

    // Deletion entire linked list using destructor.
    ~CircularSinglyLinkedList()
    {
        Node<T> *head = tail->next;

        if (head != tail)
        {
            delete head;
            head = NULL;
        }
    }

    // Deleting the front node of the Circular Singly Linked List.
    void pop_front()
    {
        // if head points to NULL, it means linked list is empty.
        if (tail == NULL)
        {
            cout << "Circular Singly Linked List is already Empty.\n";
        }
        else if (tail->next == tail)
        {
            // it means, the linked list has only one element.
            delete tail;
            tail = NULL;
        }
        else
        {
            // for rest of the cases, simply deleted the front node.
            Node<T> *head = tail->next;
            Node<T> *nodeToDelete = head;

            head = head->next;
            tail -> next = head;

            nodeToDelete->next = NULL;

            delete nodeToDelete;
            nodeToDelete = NULL;
        }
    }

    // Deleting the last node of the Singly Linked List.
    void pop_back()
    {
        // if head points to NULL, it means linked list is empty.
        if (tail == NULL)
        {
            cout << "Circular Singly Linked List is already Empty.\n";
        }
        else if (tail->next == tail)
        {
            // it means, the linked list has only one element.
            delete tail;
            tail = NULL;
        }
        else
        {
            // for rest of the cases, simply deleted the last node.
            Node<T> *head = tail->next;
            Node<T> *ptr = head;

            while (ptr->next->next != head)
            {
                ptr = ptr->next;
            }

            // after the above loop end, Our ptr pointer will points to 2nd last node.
            Node<T> *nodeToDelete = tail;

            tail = ptr;
            tail->next = head;

            nodeToDelete -> next = NULL;

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
            Node<T> *head = tail->next;
            Node<T> *ptr = head;
            for (int jump = 1; jump < pos; jump++)
            {
                ptr = ptr->next;
            }

            // after the above loop end, Our ptr pointer will points to (pos - 1)th node.
            Node<T> *nodeToDelete = ptr->next;
            ptr->next = ptr->next->next;

            nodeToDelete->next = NULL;
            delete nodeToDelete;
            nodeToDelete = NULL;
        }
    }
};
