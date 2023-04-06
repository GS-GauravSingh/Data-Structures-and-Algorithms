#include <bits/stdc++.h>
#include "HashTable.h"
using namespace std;

int main(void)
{
    // Hashtable.
    // Tis Hashtable is implement only fro string type of key.
    HashTable<string, int> hashtable;

    // Insertion in HashTable.
    // hashtable.insert("Mango", 100);
    // hashtable.insert("Apple", 120);
    // hashtable.insert("Banana", 140);
    // hashtable.insert("Orange", 180);
    // hashtable.insert("Kiwi", 200);
    // hashtable.insert("Papaya", 220);
    // hashtable.insert("Litchi", 240);



    // // printing entire Hashtable.
    // hashtable.printHashTable();


    // // Searching in HashTable.
    // string fruit;
    // cout << "Enter key to search: ";
    // cin >> fruit;

    // int* price = hashtable.search(fruit);
    // if (price != NULL)
    // {
    //     cout << "Price of " << fruit << " is " << *price << ".\n";
    // }
    // else
    // {
    //     cout << fruit << " not found.\n";
    // }

    // // Deletion in Hash Table.
    // string key;
    // cout << "Enter key to Delete: ";
    // cin >> key;
    // hashtable.erase(key);

    // hashtable.printHashTable();

    hashtable["Mango"] = 100;
    hashtable["Apple"] = 120;
    hashtable["Orange"] = 140;
    hashtable["Papaya"] = 180;
    hashtable.printHashTable();

}