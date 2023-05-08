#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

/* ----------------------------------- Solution Class ----------------------------------------- */
class Solution
{
private:
    /* Method to create an adjacency list for undirected weighted graph. */
    void createAdjacencyList(vector<vector<int>> &edges, unordered_map<int, list<pair<int, int>>> &adjList)
    {
        // Traversing the edges vector.
        for (int i = 0; i < edges.size(); i++)
        {
            // Vertex 'u'.
            int u = edges[i][0];

            // Vertex 'V'.
            int v = edges[i][1];

            // Edge Weight  (u)---------- edge weight --------(v).
            int edgeWeight = edges[i][2];

            // Given graph is undirected, so we have to create 2 edges, first is from 'u' to 'v' and second is from 'v' to 'u'.
            adjList[u].push_back({v, edgeWeight});
            adjList[v].push_back({u, edgeWeight});
        }
    }

public:
    /* Method to find sum of weights of edges of the Minimum Spanning Tree. */
    /*
    Time Complexity: O(E*logE) + O(E*logE)~ O(E*logE), where E = no. of given edges.
    The maximum size of the priority queue can be E so after at most E iterations the priority queue will be empty and the loop will end. Inside the loop, there is a pop operation that will take logE time. This will result in the first O(E*logE) time complexity. Now, inside that loop, for every node, we need to traverse all its adjacent nodes where the number of nodes can be at most E. If we find any node unvisited, we will perform a push operation and for that, we need a logE time complexity. So this will result in the second O(E*logE).

    Space Complexity: O(E) + O(V), where E = no. of edges and V = no. of vertices. O(E) occurs due to the size of the priority queue and O(V) due to the visited array. If we wish to get the mst, we need an extra O(V-1) space to store the edges of the most.
    */
    int spanningTree(int V, int E, vector<vector<int>> edges)
    {
        // Step 1: Create a adjacency list for undirected weighted graph.
        unordered_map<int, list<pair<int, int>>> adjList;
        createAdjacencyList(edges, adjList);

        /* ------ Performing Prim's Algorithmn. ------- */
        // We need some additional data structures such as priority queue (MIN_HEAP) and visited array to perform prim's algorithm.

        // Priority Queue (MIN-HEAP).
        // Priority Queue is of type {edge weight, Node}.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Visited Array.
        // Initializing all nodes with '0', because initially all nodes are unvisited.
        vector<int> visited(V, 0);

        // Push the starting node into the queue, We can start from any given node. Here we are going to start from node '0'.
        // Priority Queue is of type {edge weight, Node}.
        // Starting node is not an edge and start with the edge weight 0.
        pq.push({0, 0});

        // Variable to store the sum of edge weights of Minimum Spanning Tree (MST).
        int mstEdgesSum = 0;

        // Traverse the priority queue.
        while (!pq.empty())
        {
            // Take out the top element of the priority queue.
            // As we are using Min Heap, the top-most element is the element having minimum edge weight.
            auto topElement = pq.top();

            // Pop the top element of the priority queue.
            pq.pop();

            // Take out the edge weight and node from the top element.
            int edgeWeight = topElement.first;
            int node = topElement.second;

            // Now, if the node is already visited it means this node is the part of the MST so there is no need to take this node again, we can simply move to next node.
            if (visited[node])
            {
                // moving to next node.
                continue;
            }

            // But, if the node is not visited, it means this node is not the part of our MST so we can include its edge weight in our mstSUM and mark this node as visited (it means now this node is the part of MST).
            visited[node] = true;
            mstEdgesSum += edgeWeight;

            // Move towards the neighbors.
            // adjList will return a pair of type {v, edge weight}.
            for (auto pair : adjList[node])
            {
                // vertex 'v'.
                int neighbor = pair.first;

                // edge weight.
                int edgeWeight = pair.second;

                // if the neighbor is not visited in the past, then push this neighbor into the queue.
                if (!visited[neighbor])
                {
                    pq.push({edgeWeight, neighbor});
                }
            }
        }

        // simply return the sum of edges of MST.
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