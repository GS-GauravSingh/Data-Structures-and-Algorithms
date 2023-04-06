#include <bits/stdc++.h>
#include "Trie.h"
using namespace std;

int main(void)
{
    // Trie
    Trie t;

    // Insertion in Trie.
    t.insert("Cat");
    t.insert("Car");
    t.insert("Cart");
    t.insert("Dog");
    t.insert("Apple");
    t.insert("App");
    t.insert("Sell");


    // Deletion From Trie.
    t.deleteWord("cat");

    // Searching in Trie.
    string word = "cat";
    if (t.search(word))
    {
        cout << word << " is present in Trie.\n";
    }
    else
    {
        cout << word << " is not present in Trie.\n";
    }
}