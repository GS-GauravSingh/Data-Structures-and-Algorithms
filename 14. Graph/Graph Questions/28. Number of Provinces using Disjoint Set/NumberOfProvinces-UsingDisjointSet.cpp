#include <bits/stdc++.h>
using namespace std;

/* ---------------------------- Disjoint Set Class. ------------------------------------------- */
class DisjointSet
{
private:
public:
    // Parent array will store the ultimate parent of each node.
    // Rank array will store the rank of each node and Rank array is used in Union by Rank.
    // Size array will store the size (size of a node means number of nodes connected to it) of each node and Rank array is used in Union by Size.
    vector<int> parent, rank, size;

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

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
public:
    /* Question: Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces. */

    /* Approach: Basically we have to find the number of disconnected components. */

    // Time Complexity: O(V^2), where V is the number of node/vertices in the graph.
    // Space Complexity: O(2V), where V is the number of node/vertices in the graph.
    int numProvinces(vector<vector<int>> adjacencyMatrix, int V)
    {
        // variable to store the count total number of components in a graph.
        int cntProvinces = 0;

        // Object of Disjoint set class.
        DisjointSet ds(V);

        // Traverse the adjacency matrix.
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adjacencyMatrix[i][j] == 1)
                {
                    ds.unionBySize(i, j);
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            if(ds.parent[i] == i)
            {
                cntProvinces++;
            }
        }
        

        return cntProvinces;
    }
};

int main(void)
{
    int V = 3;
    vector<vector<int>> adjMatrix = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1},
    };

    // Solution.
    Solution S;
    cout << S.numProvinces(adjMatrix, V);
}