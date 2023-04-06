#include <bits/stdc++.h>
using namespace std;

/* Node Structure for Trie. */
class TrieNode
{
private:
public:
    char value;           // This is the character that the node represents
    bool isTerminalNode;  // Flag to check if a node is a terminal node or not.
    int childCount;       // variable to store the number of child a particular node has.
    TrieNode **childrens; // Pointer to child nodes array.

    // Constructor of TrieNode class.
    TrieNode(char value)
    {
        this->value = value;            // storing character data in a node.
        isTerminalNode = false;         // setting up terminal node.
        childCount = 0;                 // initially there is no children.
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
public:
    /* Method to perform insertion in Trie. */
    // Time Complexity of Insertion in Trie is O(k), k is the length of the word.
    void insert(TrieNode *&root, string word)
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
                ptr->childCount++; // increment the childCount.
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
};

/* Approach: First insert all the string into the Trie and Then, we traverse the trie from the root, always taking the child that has only one child until we reach a node that has more than one child, or is marked as a word end. At this point, we know that all the previous nodes have a common prefix, so we can return the prefix built so far. */
string longestCommonPrefix(vector<string> &strs)
{
    // Base Case
    if (strs.empty())
    {
        return "";
    }

    // Creating root node of trie.
    TrieNode *root = new TrieNode('\0');

    // Creating Object of Trie class.
    Trie t;

    // Inserting all string into the trie.
    for (auto word : strs)
    {
        // inserting all strings.
        if (!word.empty())
        {
            t.insert(root, word);
        }
    }

    // Now, Traverse the trie from root.
    // At each level of the trie, check how many child nodes exist. If there is only one child, continue to the child node and add the character to the prefix string.
    // If there are more than one child nodes or if the current node is marked as a word end, return the prefix string built so far.

    // string to store answer.
    string prefix = "";

    // pointer to traverse the trie.
    TrieNode *ptr = root;

    // traversing the trie.
    for (int i = 0; i < strs[0].length(); i++)
    {
        char ch = strs[0][i];

        if (ptr->childCount == 1)
        {
            prefix.push_back(ch);

            int idx = (ch >= 'A' && ch <= 'Z') ? (ch - 'A') : (ch - 'a');
            ptr = ptr->childrens[idx];
        }
        else
        {
            break;
        }

        if (ptr->isTerminalNode)
        {
            break;
        }
    }

    return prefix;
}

int main(void)
{
    vector<string> strs = {"apple", "application", "applet", "applied", "approximate"};

    cout << longestCommonPrefix(strs);
}