#include <bits/stdc++.h>
using namespace std;

/*
Question: Why we are using Linked List ?
Answer: Because in this implementation of hashtable, i'm using separate chaining for collision handeling and in separate chaining we have array of linked list.
*/

/* Node Structure for Linked List. */
/* This is a templated class, where both key and value can be of any type so basically its a generic class. */
template <typename keyType, typename valType>
class Node
{
private:
public:
    // Each node in a Linked list will store the key, value pair and a pointer to next node.
    keyType key;
    valType value;
    Node<keyType, valType> *next; // pointer to next node.

    // Paramterized Constructor of Node class.
    Node(keyType key, valType value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

    // Destructor of Node Class.
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

/* Hash Table Class. */
/* This is also a templated class, where both key and value can be of any type so basically its a generic class. */
template <typename keyType, typename valType>
class HashTable
{
private:
    // Pointer variable to store the address of our array, this is used when we have to perform rehashing.
    Node<keyType, valType> **table;

    // varaible to store the total enterise in HashTable.
    int currentSize;

    // variable to store the total capacity of HashTable.
    int totalSize;

    // Hash Function: Hash function is used to covert a given key into an integer value and this integer value is know as Hash Value.
    // After converting a key into hash value, it returns that hash value.

    // This Hash Function generates hash value only for string.
    int hashFunction(keyType key)
    {
        // variable to store the hash value.
        int hashValue = 0;

        for (char c : key)
        {
            hashValue = (hashValue * 31 + c) % totalSize;
        }

        // Taking the mod of hash value with table size, This ensures that the hash value is within the range of the hash table indices.
        return (hashValue % totalSize);
    }

    /* Rehashing: Rehashing is the process of resizing a hashtable by creating a new, larger array and then re-inserting all the items from the old array into the new one. */
    void reHash()
    {
        // Save the pointer of old table (current table).
        Node<keyType, valType> **oldTable = table;

        // storing the size of old hashtable.
        int oldTableSize = totalSize;

        // creating a new hashtable, which is twice the size of old hashtable.
        Node<keyType, valType> **newTable = new Node<keyType, valType> *[2 * oldTableSize];

        // storing the size of new hashtable.
        totalSize = 2 * oldTableSize;

        // store the reference of new hastable.
        table = newTable;

        // Inserting all key value pairs into our new hash table.
        // First initialize all value of new hash table with null.
        for (int i = 0; i < totalSize; i++)
        {
            newTable[i] = NULL;
        }

        // Copying data from old hashtable to new hashtable.

        // befor copying the data, set the current size to 0.
        currentSize = 0;
        for (int i = 0; i < oldTableSize; i++)
        {
            // temporary variable to traverse a particular linked list at ith index.
            Node<keyType, valType> *temp = oldTable[i];

            while (temp != NULL)
            {
                // getting the key, value pair.
                keyType key = temp->key;
                valType value = temp->value;

                // insert key, value pair into the new hash table.
                insert(key, value);

                // move the pointer.
                temp = temp->next;
            }

            // Destroying the linked list present at ith index.
            if (oldTable[i] != NULL)
            {
                delete oldTable[i];
                oldTable[i] = NULL;
            }
        }

        // destroying the entire old array.
        delete[] oldTable;
    }

    /* Method to erase a key from linked list. */
    // Time Complexity: O(1) on average case, worst case O(n).
    void deleteKeyFromLinkedList(Node<keyType, valType> *&head, keyType key)
    {
        Node<keyType, valType> *curr = head;
        Node<keyType, valType> *prev = NULL;

        // Searching and deleting key from linked list.
        while (curr != NULL && curr->key != key)
        {
            prev = curr;
            curr = curr->next;
        }

        // After the above loop ends, our curr pointer points to the key.
        // And if the key is not present, the curr points to NULL.
        if (curr == NULL)
        {
            // it means key is not present.
            cout << "Key not present.\n";
            return;
        }

        // If the node which we have to delete is head node.
        if (curr == head)
        {
            head = head->next;
        }
        else
        {
            prev->next = curr->next;
        }

        // Free memory occupied by current node
        delete curr;
    }

public:
    // Paramterized Constructor of HashTable class.
    HashTable(int defaultSize = 7 /* setting a default size of HashTable. */)
    {
        // setting the total enterise inserted in hashtable.
        currentSize = 0; // initially, hashtabale is empty.

        // setting the total capacity of hashtable.
        totalSize = defaultSize;

        // Initializing dynamic array of totalSize.
        // Each element of the array will be a pointer to a Node object. So, we declare the array as an array of pointers to Node objects using the syntax Node<keyType, valType>*[totalSize].
        Node<keyType, valType> **arr = new Node<keyType, valType> *[totalSize];

        // Storing the address of array into our pointer variable (table).
        table = arr;

        // Initializing each element of the array with a null pointer (which represents an empty linked list).
        for (int i = 0; i < totalSize; i++)
        {
            arr[i] = NULL;
        }
    }

    /* Method to insert "key" -> "value" pair into our hashtable. */
    // Time Complexity: O(1) on an average case, but when rehassing is happen then the time complexity of insert function is O(n).
    void insert(keyType key, valType value)
    {
        /*
        Whenever we get a "key" -> "value" pair to insert into our hashtable, what we have to do is,
        1. First we give our key to the hash fuction and hash function generates an integer value (hash value) and returns that hash value and we need to store it somewhere.

        2. Now, we have to take the mod of hash value with tableSize, so that hash value will lie in the range of table size.

        3. Now, we can insert the key, value pair into our hashtable using the hash value.
        */

        // got the index, where we can insert our key, value pair into the hash table.
        int idx = hashFunction(key);

        // creating a new node for key, value pair.
        Node<keyType, valType> *newNode = new Node<keyType, valType>(key, value);

        // Insert the node.
        // If at index "idx" in hash table, if no enterise where there, it the linked list at that index is empty, in this case simply insert the new node,

        // But If at index "idx" in hash table, if some node is already there, it the linked list at that index is not empty, in this case simply insert the new node at the head of the linked list.

        // Inserting at head.
        Node<keyType, valType> *&head = table[idx];
        newNode->next = head;
        head = newNode;

        // count this entry.
        currentSize++;

        // Computing the Load Factor.
        // Load factor tells us how full our hash table is. This is used when we have to perform rehashing.
        float loadFactor = currentSize / float(totalSize);

        // IF loadFactor > 0.7, it means our hashtable is 75% full.
        // Now we need to expand the size of our hash table this expansion of hashtable is known as rehashing.
        if (loadFactor > 0.7)
        {
            reHash();
        }
    }

    /* Method to search for a key into our hash table and this method will return the value corresponds to the key. */
    // Time Complexity: O(1) on average case, worst case O(n).
    valType *search(keyType key)
    {
        // When searching for a particular key-value pair, the hash function is again used to
        // compute the index of the array where the key - value pair should be stored.
        int idx = hashFunction(key); // got the index of key.

        // At index "idx" a linked list is present, and if the linked list is empty, it means the key-value pair is not exist, but if the linked list is not empty, in this case you have to traverse the linked list and search for your key.
        Node<keyType, valType> *temp = table[idx];

        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return &temp->value;
            }

            temp = temp->next;
        }

        // key not found.
        return NULL;
    }

    /* Method to erase a key from our hash table. */
    // Time Complexity: O(1) on average case, worst case O(n).
    void erase(keyType key)
    {
        // Getting the bucked id, using hash function.
        int idx = hashFunction(key);

        // At index "idx" a linked list is present, and if the linked list is empty, it means the key-value pair is not exist, but if the linked list is not empty, in this case you have to traverse the linked list and search for your key and then delete the key.
        Node<keyType, valType> *&head = table[idx];

        // deleting key from linked list.
        deleteKeyFromLinkedList(head, key);

        // after deleting the key, decrement the current size.
        currentSize--;
    }

    /* Method to print our Hashtable. */
    void printHashTable()
    {
        for (int i = 0; i < totalSize; i++)
        {
            cout << "Bucket " << i << " => ";

            // temporary variable to traverse a particular linked list at ith index.
            Node<keyType, valType> *temp = table[i];
            while (temp != NULL)
            {
                cout << temp->key << " -> " << temp->value << ", ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    /* Operator Overloading. */
    valType& operator[](keyType key)
    {
        int* valueFound = search(key);
        if(valueFound == NULL)
        {
            valType object;
            insert(key, object);
            valueFound = search(key);
        }

        return *valueFound;
    }
};
