#include <bits/stdc++.h>
using namespace std;

/* Node Structure for Trie. */
class TrieNode
{
private:
public:
    /*
    A trie is a tree-like data structure where each node represents a character in a string. Each node in a trie consists of several components:

    1. A character value: This is the character that the node represents.

    2. A boolean flag to indicate whether the node is a terminal node: A terminal node represents the end of a string, so this flag is set to true for any node that represents the last character of a string.

    3. A set of child nodes: Each child node represents the next character in a string. The child nodes are typically stored in an array or a hash table, with the index or key corresponding to the character that the child node represents.

    We are using array to store child nodes, because in trie, each node can have 26 childrens. Why 26 children ? because trie is used for storing string and string containg alphabets and we have 26 alphabets that is from a to z or A to Z (26 alphabets).
    */

    char value;           // This is the character that the node represents
    bool isTerminalNode;  // Flag to check if a node is a terminal node or not.
    TrieNode **childrens; // Pointer to child nodes array.

    // Constructor of TrieNode class.
    TrieNode(char value)
    {
        this->value = value;            // storing character data in a node.
        isTerminalNode = false;         // setting up terminal node.
        childrens = new TrieNode *[26]; // declaring dynamic array of size 26.

        // Initializing childrens array with Null Pointer.
        for (int i = 0; i < 26; i++)
        {
            childrens[i] = NULL;
        }
    }
};

/* Trie Class */
class Trie
{
private:
    /* Creating root node. */
    TrieNode *root;

    /* Actual Method to perform deletion in Trie. */
    // Time Complexity of Deletion in Trie is O(k), k is the length of the word.
    bool deleteWordFromTrie(TrieNode *&root, string word, int &i /* "i" is used to traverse the string word. */)
    {
        // Base Case
        if (i >= word.size())
        {
            // It means we are at the last character of the string.
            // So mark this node as non-terminal node.
            root->isTerminalNode = false;

            // Check if this terminal node has childrens or not.
            for (int i = 0; i < 26; i++)
            {
                if (root->childrens[i] != NULL)
                {
                    // It means this termnal node has other childrens, in this case we don't delete this node, because this string is a part of some other word.

                    // So we have to keep this string, but we can the terminal node of this string as non-terminal, in this way, the string gets deleted.

                    // Returning false, where flase represent that we cannot delete the nodes.
                    return false;
                }
            }

            // If the avobe loop does not return false, it means this terminal node has no other childrens and in this case we can delete the nodes.

            // Returning true, where true represent that we can delete the nodes.
            return true;
        }

        // Recursive Case
        // Finding Index of character in childrens array.
        char ch = word[i];
        int idx = (ch >= 'A' && ch <= 'Z') ? (ch - 'A') : (ch - 'a');

        // First we have to go the the base case, to check if the given string is a seperate string or it is a part of some other string.
        if (deleteWordFromTrie(root->childrens[idx], word, ++i) == true)
        {
            // IF the return value from base case is true, it means the terminal node of this string has no other childrens and in this case we can delete the nodes.

            // Deleting nodes.
            delete root->childrens[idx]; // memory free.
            root->childrens[idx] = NULL; // set children to NULL.

            // After deleting the node, we have to move back toward the root node.
            // But while returning back, delete the rest of the nodes only when the nods has no other childrens.

            // Check if the non-terminal nodes has childrens or not.
            for (int i = 0; i < 26; i++)
            {
                if (root->childrens[i] != NULL)
                {
                    // Childrens Present.
                    return false;
                }
            }

            // Childrens not Present.
            return true;
        }

        // If the return value from base case is false, it means the terminal node of this string has other childrens and in this case we cannot delete the nodes so return false.
        return false;
    }

public:
    /* Constructor of Trie Class. */
    Trie()
    {
        /* Initializing root node, root node would always be NULL. */
        root = new TrieNode('\0');
    }

    /* Method to perform insertion in Trie. */
    // Time Complexity of Insertion in Trie is O(k), k is the length of the word.
    void insert(string word)
    {
        // Pointer to traverse the Trie.
        TrieNode *ptr = root;

        // Traversing the string "word".
        for (char ch : word)
        {
            // Finding Index of character in childrens array.
            int idx = (ch >= 'A' && ch <= 'Z') ? (ch - 'A') : (ch - 'a');

            // If character "ch" is not present in childrens array.
            if (ptr->childrens[idx] == NULL)
            {
                // It means charater is not present. So, create a new child node for that character and move to the next character in the string.
                TrieNode *newNode = new TrieNode(ch);
                ptr->childrens[idx] = newNode;
            }

            // For each character in the string, check if a child node with that character already exists. If it does, move to the next character in the string.
            // Moving to next character.
            ptr = ptr->childrens[idx];
        }

        // After the bove loop ends, our ptr pointer is pointing to the last character of the string word.
        // So, Mark this node as Terminal node.
        ptr->isTerminalNode = true;
    }

    /* Method to perform searching in Trie. */
    // Time Complexity of Searching in Trie is O(k), k is the length of the word.
    bool search(string word)
    {
        // Pointer to traverse the Trie.
        TrieNode *ptr = root;

        // Traversing the string "word".
        for (char ch : word)
        {
            // Finding Index of character in childrens array.
            int idx = (ch >= 'A' && ch <= 'Z') ? (ch - 'A') : (ch - 'a');

            // If character "ch" is not present in childrens array.
            if (ptr->childrens[idx] == NULL)
            {
                // It means charater is not present.
                // It means the string is not present in the Trie, so we can return false.
                return false;
            }

            // For each character in the search string, check if there is a child node with that character. If there is, follow the link to the child node and continue to the next character.

            // Moving to next character.
            ptr = ptr->childrens[idx];
        }

        // After the bove loop ends, our ptr pointer is pointing to the last character of the string word.

        // Once we have processed all characters in the search string, check if the last node we reached is a terminal node. If it is, the search string is in the trie, and we can return true. If it isn't, the search string is not in the trie, and we can return false.
        if (ptr->isTerminalNode == true)
        {
            // string is present.
            return true;
        }

        // string is not present.
        return false;
    }

    /* Method to perform deletion in Trie. */
    // Time Complexity of Deletion in Trie is O(k), k is the length of the word.
    void deleteWord(string word)
    {
        // Checking if the word exists in the trie or not.
        if (search(word) == true)
        {
            // if word is present in the trie only then we perform deletion.
            int i = 0; /* "i" is used to traverse the string. */
            deleteWordFromTrie(root, word, i);
        }
        else
        {
            cout << word << " is not present in the Trie so how can we delete it ?\n";
        }
    }
};