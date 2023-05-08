#include <bits/stdc++.h>
using namespace std;

/* ---------------------------- Disjoint Set Class. ------------------------------------------- */
class DisjointSet
{
private:
    // Parent array will store the ultimate parent of each node.
    // Rank array will store the rank of each node and Rank array is used in Union by Rank.
    // Size array will store the size (size of a node means number of nodes connected to it) of each node and Rank array is used in Union by Size.
    vector<int> parent, rank, size;

public:
    // Constructor of Disjoint set class.
    DisjointSet(int n /* In Disjoint Set, initially we have 'n' individual nodes. */)
    {
        // Declaring parent, rank, and size array with size 'n+1', because this size will work for both 0 and 1 based indexing graphs.
        parent.resize(n + 1);

        // Initializing parent array.
        for (int i = 0; i <= n; i++)
        {
            // Initially each node is a ultimate parent of itself.
            parent[i] = i;
        }

        // Initially size of all nodes is 1.
        size.resize(n + 1, 1);

        // Initially rank of all nodes is 0.
        rank.resize(n + 1, 0);
    }

    /* Method to find the Ultimate Parent of a particular node. */
    // This is the code with path compression.
    int findUParent(int node)
    {
        // Base Case
        if (node == parent[node] /* Because the ultimate parent of a ultimate parent is a ultimate parent itself. */)
        {
            // return ultimate parent.
            return node;
        }

        // else, move towards the base case and find the ultimate parent of the node in the path.
        int ultimateParent = findUParent(parent[node]);

        // Backtracking step (while comming back from the base case).
        // Connect all the nodes directly with the ultimate parents.
        parent[node] = ultimateParent;
    }

    /* Performing Union using Union by rank Method. */
    /* The time complexity of both Union by Size and Union by Rank is O(4 alpha), which is a constant time complexity and is considered to be O(1). */
    void unionByRank(int u, int v)
    {
        // Step 1: find the ultimate parent of node 'u' and node 'v'.
        int ulp_u = findUParent(u); // ultimate parent of U.
        int ulp_v = findUParent(v); // ultimate parent of V.

        // Additional Step.
        // If both the nodes already belongs to the same component, you can simply return from here.
        if (ulp_u == ulp_v)
        {
            return;
        }

        // Step 2: Find ranks of ultimate parents.
        int rankOf_ulp_u = rank[ulp_u]; // Rank of ultimate parent of U.
        int rankOf_ulp_v = rank[ulp_v]; // Rank of ultimate parent of V.

        /* Step 3: Check the ranks of the ultimate parents,
            3.1. Now, if the ranks of both the ultimate parents is equal, in this case you can connect any ultimate parent to other ultimate parent and we will increase the rank by one for the ultimate parent node to whom we have connected the other one.
            3.2. But, if the ranks of both the ultimate parents are not equal, in this case, we always connect the ultimate parent with a smaller rank to the other ultimate parent with a larger rank. (Smaller rank waale ultimate parent ko larger rank waale ultimate parent se connect karo).
        */
        if (rankOf_ulp_u < rankOf_ulp_v)
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rankOf_ulp_v < rankOf_ulp_u)
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            // rankOf_ulp_u == rankOf_ulp_v
            // I am connecting 'ulp_u' with 'ulp_v'.
            parent[ulp_u] = ulp_v;

            // And when you connect 2 nodes of the same rank then the height/rank will increase by one and when 2 nodes have different ranks in this case we will not do anything with the ranks.
            rank[ulp_v]++;
        }
    }

    /* Performing Union using Union by size Method. */
    /* The time complexity of both Union by Size and Union by Rank is O(4 alpha), which is a constant time complexity and is considered to be O(1). */
    void unionBySize(int u, int v)
    {
        // Step 1: find the ultimate parent of node 'u' and node 'v'.
        int ulp_u = findUParent(u); // ultimate parent of U.
        int ulp_v = findUParent(v); // ultimate parent of V.

        // Additional Step.
        // If both the nodes already belongs to the same component, you can simply return from here.
        if (ulp_u == ulp_v)
        {
            return;
        }

        // Step 2: Find size of ultimate parents.
        int sizeOf_ulp_u = size[ulp_u]; // Size of ultimate parent of U.
        int sizeOf_ulp_v = size[ulp_v]; // Size of ultimate parent of V.

        /* Step 3: Check the sizes of the ultimate parents,
            3.1. Now, if the ranks of both the ultimate parents is equal, in this case you can connect any ultimate parent to other ultimate parent.

            3.2 But, if the ranks of both the ultimate parents are not equal, in this case, we always connect the ultimate parent with a smaller rank to the other ultimate parent with a larger rank. (Smaller rank waale ultimate parent ko larger rank waale ultimate parent se connect karo).

            Note: Now, in case of Union by rank, we only increment the rank, when we connect 2 components of same sizes, but in case of Union by Size While connecting in both cases we will increase the size of the parent node to whom we have connected by the size of the other parent node which is actually connected.
        */

        if (sizeOf_ulp_u < sizeOf_ulp_v)
        {
            parent[ulp_u] = ulp_v;

            // Update the size of "ulp_v" with the size of "ulp_u".
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;

            // Update the size of "ulp_u" with the size of "ulp_v".
            size[ulp_u] += size[ulp_v];
        }
    }
};

/* ----------------------------------- Solution Class ----------------------------------------- */
class Solution
{
private:
public:
    /*
    Time Complexity: O(N+E) + O(E*4ɑ) + O(N*(ElogE + E)) where N = no. of indices or nodes and E = no. of emails. The first term is for visiting all the emails. The second term is for merging the accounts. And the third term is for sorting the emails and storing them in the answer array.

    Space Complexity: O(N)+ O(N) +O(2N) ~ O(N) where N = no. of nodes/indices. The first and second space is for the ‘mergedMail’ and the ‘ans’ array. The last term is for the parent and size array used inside the Disjoint set data structure.
    */
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();

        // Object of disjoint set class.
        DisjointSet ds(n);

        unordered_map<string, int> mailToNode;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if (mailToNode.find(mail) == mailToNode.end())
                {
                    mailToNode[mail] = i;
                }
                else
                {
                    ds.unionBySize(i, mailToNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        for (auto it : mailToNode)
        {
            string mail = it.first;
            int node = ds.findUParent(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (mergedMail[i].size() == 0)
            {
                continue;
            }
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for (auto it : mergedMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

int main(void)
{
    vector<vector<string>> accounts = {{"John", "j1@com", "j2@com", "j3@com"},
                                       {"John", "j4@com"},
                                       {"Raj", "r1@com", "r2@com"},
                                       {"John", "j1@com", "j5@com"},
                                       {"Raj", "r2@com", "r3@com"},
                                       {"Mary", "m1@com"}};

    Solution obj;
    vector<vector<string>> ans = obj.accountsMerge(accounts);
    for (auto acc : ans)
    {
        cout << acc[0] << ":";
        int size = acc.size();
        for (int i = 1; i < size; i++)
        {
            cout << acc[i] << " ";
        }
        cout << endl;
    }

    return 0;
}