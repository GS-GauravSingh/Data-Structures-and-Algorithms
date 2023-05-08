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
    /* Method to find sum of weights of edges of the Minimum Spanning Tree. */
    /* Time Complexity: O(E logE) + O(E*4α*2)   where N = no. of nodes and E = no. of edges. O(E logE) for sorting the array consists of the edge tuples. Finally, we are using the disjoint set operations inside a loop. The loop will continue to E times. Inside that loop, there are two disjoint set operations like findUPar() and UnionBySize() each taking 4 and so it will result in 4*2. That is why the last term O(E*4*2) is added.

    Space Complexity: O(N) + O(N) + O(E) where E = no. of edges and N = no. of nodes. O(E) space is taken by the array that we are using to store the edge information. And in the disjoint set data structure, we are using two N-sized arrays i.e. a parent and a size array (as we are using unionBySize() function otherwise, a rank array of the same size if unionByRank() is used) which result in the first two terms O(N). */
    int spanningTree(int V, int E, vector<vector<int>> edgesVector)
    {
        /* ------ Performing Kruskal's Algorithmn. ------- */

        // Algorithm.
        // sort the edges vector in ascending order according to edge weights.  The edges must be sorted in the ascending order of the weights so that while iterating we can get the edges with the minimum weights first.

        // The gievn edges vector is in the form of {u, v, edge weight}. So, to sort the edges according to edge weights, we need to place the edge weight at the first position like this {edge weight, u, v} the edges vector must be in this form.

        // vector to store edges in the form of {edge weight, u, v}.
        vector<pair<int, pair<int, int>>> edges;

        for (int i = 0; i < edgesVector.size(); i++)
        {
            int u = edgesVector[i][0];
            int v = edgesVector[i][1];
            int edgeWeight = edgesVector[i][2];

            edges.push_back({edgeWeight, {u, v}});
        }

        // sort the edges vector.
        sort(edges.begin(), edges.end());

        // Variable to store sum of edges of Minimum Spanning Tree.
        int mstEdgesSum = 0;

        // Object of Disjoint set class.
        DisjointSet ds(V);

        // Traverse the edges vector.
        for (auto it : edges)
        {
            // Take out the edge weight and nodes from the edges vector.

            // u --------- edge weight ------------ v.
            int edgeWeight = it.first;

            // Node 'u'.
            int u = it.second.first;

            // Node 'v'.
            int v = it.second.second;

            // Now, if Node 'u' and Node 'v' belong to the same components of the graph, we need not do anything to that edge as there already exists a path between the nodes and we will continue to the next tuple.

            // But, if Node 'u' and Node 'v' does not belong to the same components of the graph, then we will add the weight of the edge to our final answer.

            // Using Disjoint set we can easily find out whether 2 arbitrary node belongs to the same component of the graph or not.
            

            if (ds.findUParent(u) != ds.findUParent(v))
            {
                mstEdgesSum += edgeWeight;
                ds.unionBySize(u, v);
            }
        }

        return mstEdgesSum;
    }
};

int main()
{
    // Vertices are labelled from 0 to V-1.
    int V = 3;

    // Edges of undirected weighted graph.
    // u = edges[i][0].
    // v = edges[i][1].
    // edge weight (u ---- edge weight ---- v) = edges[i][2].
    vector<vector<int>> edges = {
        {0, 1, 5},
        {0, 2, 1},
        {1, 2, 3},
    };
    int E = edges.size();

    // Solution.
    Solution S;
    cout << S.spanningTree(V, E, edges);
    return 0;
}