#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class Cmp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:

    void preOrder(Node* root, vector<string> &ans, string temp)
    {
        // Base Case
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(temp);
            return;
        }

        // Recursive case

        // Left
        preOrder(root->left, ans, temp+'0');

        // Right
        preOrder(root->right, ans, temp+'1');
    }

public:
    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        priority_queue<Node *, vector<Node *>, Cmp> pq;

        for (int i = 0; i < N; i++)
        {
            Node *temp = new Node(f[i]);
            pq.push(temp);
        }

        while (pq.size() > 1)
        {
            Node *first = pq.top();
            pq.pop();

            Node *second = pq.top();
            pq.pop();

            Node *merge = new Node(first->data + second->data);

            merge->left = first;
            merge->right = second;

            pq.push(merge);
        }

        Node* root = pq.top();
        
        vector<string> ans;
        string temp = "";
        preOrder(root, ans, temp);

        return ans;
    }
};

int main(void)
{
    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    int n = S.length();

    // Solution.
    Solution obj;
    vector<string> ans = obj.huffmanCodes(S, f, n);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}