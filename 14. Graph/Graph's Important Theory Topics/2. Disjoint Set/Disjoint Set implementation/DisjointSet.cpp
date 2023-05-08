#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Disjoint Set Class. -------------------------------------- */
class DisjointSet
{
private:
    /* Data Members of DisjointSet Class. */
    /* In order to implement Disjoint, we basically need two arrays of size N (where N is the number of nodes).
    1. One is the rank array:
        1. The rank array basically stores the rank of each node.
    2. The other one is the parent array:
        1. The parent array stores the ultimate parent for each node. */

    // The rank array basically stores the rank of each node.
    // Used in Union by Rank.
    vector<int> rank;

    // The parent array stores the ultimate parent for each node.
    vector<int> parent;

    // Size array will store the size of each node.
    // Used in Union by Size.
    vector<int> size;

public:
    /* Member Functions / Methods of DisjointSet Class. */
    /* Constructor of DisjointSet Class. */
    DisjointSet(int n /* Initially we have total 'n' nodes. */)
    {
        // Declaring rank array with size 'n+1', because this size will work for both 0 and 1 based indexing graphs.
        // Initially rank of all nodes is 0.
        rank.resize(n + 1, 0);

        // Declaring rank array with size 'n+1', because this size will work for both 0 and 1 based indexing graphs.
        // Initially size of all nodes is 1.
        size.resize(n + 1, 1);

        // Declaring parent array with size 'n+1', because this size will work for both 0 and 1 based indexing graphs.
        parent.resize(n + 1);

        // Initially each node is a ultimate parent of itself.
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    /* Method to find the Ultimate Parent of a particular node. */
    // This is the code without path compression.
    int findUltimateParent_WithoutPathCompression(int node)
    {
        // Base Case
        if (node == parent[node] /* Because the ultimate parent of a ultimate parent is a ultimate parent itself. */)
        {
            // return ultimate parent.
            return node;
        }

        // else, move towards the base case and find the ultimate parent of the node in the path.
        return findUltimateParent_WithoutPathCompression(parent[node]);
    }
    /* Method to find the Ultimate Parent of a particular node. */
    // This is the code with path compression.
    int findUltimateParent(int node)
    {
        // Base Case
        if (node == parent[node] /* Because the ultimate parent of a ultimate parent is a ultimate parent itself. */)
        {
            // return ultimate parent.
            return node;
        }

        // else, move towards the base case and find the ultimate parent of the node in the path.
        int ultimateParent = findUltimateParent(parent[node]);

        // Backtracking step (while comming back from the base case).
        // Connect all the nodes directly with the ultimate parents.
        parent[node] = ultimateParent;
    }

    /* Performing Union using Union by rank Method. */
    /* The time complexity of both Union by Size and Union by Rank is O(4 alpha), which is a constant time complexity and is considered to be O(1). Here, alpha is the inverse Ackermann function, which grows very slowly and can be considered as a constant for practical purposes. */
    void unionByRank(int u, int v)
    {
        // Step 1: Find the ultimate parent of node ‘u’ and node ‘v’ and store the ultimate parents of both the node in a separate variable.
        int ultimateParentOfNodeU = findUltimateParent(u);
        int ultimateParentOfNodeV = findUltimateParent(v);

        // Additional Step.
        // If both the nodes already belongs to the same component, you can simply return from here.
        if (ultimateParentOfNodeU == ultimateParentOfNodeV)
        {
            return;
        }

        // Step 2: Find ranks of ultimate parents.
        int rankOfultimateParentOfNodeU = rank[ultimateParentOfNodeU];
        int rankOfultimateParentOfNodeV = rank[ultimateParentOfNodeV];

        /* Step 3: Check the ranks of the ultimate parents,
            3.1. Now, if the ranks of both the ultimate parents is equal, in this case you can connect any ultimate parent to other ultimate parent and we will increase the rank by one for the ultimate parent node to whom we have connected the other one.
            3.2. But, if the ranks of both the ultimate parents are not equal, in this case, we always connect the ultimate parent with a smaller rank to the other ultimate parent with a larger rank. (Smaller rank waale ultimate parent ko larger rank waale ultimate parent se connect karo).
        */

        if (rankOfultimateParentOfNodeU < rankOfultimateParentOfNodeV)
        {
            // If the ranks of both the ultimate parents are not equal, in this case, we always connect the ultimate parent with a smaller rank to the other ultimate parent with a larger rank. (Smaller rank waale ultimate parent ko larger rank waale ultimate parent se connect karo).
            parent[ultimateParentOfNodeU] = ultimateParentOfNodeV;

            // when 2 nodes have different ranks in this case we will not do anything with the ranks.
        }
        else if (rankOfultimateParentOfNodeV < rankOfultimateParentOfNodeU)
        {
            // connect smaller rank with larger rank.
            parent[ultimateParentOfNodeV] = ultimateParentOfNodeU;
            // when 2 nodes have different ranks in this case we will not do anything with the ranks.
        }
        else
        {
            // I am connecting node 'u' with 'v'.
            // Now, the ultimate parent of node 'u' is node 'v'.
            parent[ultimateParentOfNodeU] = ultimateParentOfNodeV;

            // And when you connect 2 nodes of the same rank then the height/rank will increase by one and when 2 nodes have different ranks in this case we will not do anything with the ranks.

            // increment the rank of 'ultimateParentOfNodeV'.
            rank[ultimateParentOfNodeV]++;
        }
    }

    /* Performing Union using Union by size Method. */
    /* The time complexity of both Union by Size and Union by Rank is O(4 alpha), which is a constant time complexity and is considered to be O(1). Here, alpha is the inverse Ackermann function, which grows very slowly and can be considered as a constant for practical purposes. */
    void unionBySize(int u, int v)
    {
        // Step 1: Find the ultimate parent of node ‘u’ and node ‘v’ and store the ultimate parents of both the node in a separate variable.
        int ultimateParentOfNodeU = findUltimateParent(u);
        int ultimateParentOfNodeV = findUltimateParent(v);

        // Additional Step.
        // If both the nodes already belongs to the same component, you can simply return from here.
        if (ultimateParentOfNodeU == ultimateParentOfNodeV)
        {
            return;
        }

        // Step 2: Find size of ultimate parents.
        int sizeOfultimateParentOfNodeU = size[ultimateParentOfNodeU];
        int sizeOfultimateParentOfNodeV = size[ultimateParentOfNodeV];

        /* Step 3: Check the sizes of the ultimate parents,
            3.1. Now, if the ranks of both the ultimate parents is equal, in this case you can connect any ultimate parent to other ultimate parent.

            3.2 But, if the ranks of both the ultimate parents are not equal, in this case, we always connect the ultimate parent with a smaller rank to the other ultimate parent with a larger rank. (Smaller rank waale ultimate parent ko larger rank waale ultimate parent se connect karo).

            Note: Now, in case of Union by rank, we only increment the rank, when we connect 2 components of same sizes, but in case of Union by Size While connecting in both cases we will increase the size of the parent node to whom we have connected by the size of the other parent node which is actually connected.
        */

        if (sizeOfultimateParentOfNodeU < sizeOfultimateParentOfNodeV)
        {
            // If the ranks of both the ultimate parents are not equal, in this case, we always connect the ultimate parent with a smaller rank to the other ultimate parent with a larger rank. (Smaller rank waale ultimate parent ko larger rank waale ultimate parent se connect karo).
            parent[ultimateParentOfNodeU] = ultimateParentOfNodeV;

            // Update the size of "ultimateParentOfNodeV" with the size of "ultimateParentOfNodeU".
            size[ultimateParentOfNodeV] += size[ultimateParentOfNodeU];
        }
        else
        {
            // Ther is no need for writing the separate case for equal, because in we have to increment the size in all the cases.
            // connect smaller rank with larger rank.
            parent[ultimateParentOfNodeV] = ultimateParentOfNodeU;

            // Update the size of "ultimateParentOfNodeU" with the size of "ultimateParentOfNodeV".
            size[ultimateParentOfNodeU] += size[ultimateParentOfNodeV];
        }
    }
};

int main(void)
{
    DisjointSet ds(7);
    // ds.unionByRank(1, 2);
    // ds.unionByRank(2, 3);
    // ds.unionByRank(4, 5);
    // ds.unionByRank(6, 7);
    // ds.unionByRank(5, 6);
    // ds.unionByRank(3, 7);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    ds.unionBySize(3, 7);

    // Let's check if 3, 7 belongs to the same component or not.
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Belongs to the same component.\n";
    }
    else
    {

        cout << "Does not Belongs to the same component.\n";
    }
    return 0;
}