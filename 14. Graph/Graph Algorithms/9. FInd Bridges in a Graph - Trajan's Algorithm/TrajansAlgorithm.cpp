#include <bits/stdc++.h>
using namespace std;

/*
What is a Bridge ?
In a graph, a bridge is an edge whose removal would disconnect the graph into two or more components. 
*/

/* ---------------------------------- Solution Class ------------------------------------- */
class Solution
{
private:
    /* Method to create an adjacency list for undirected graph. */
    void createAdjacencyList(vector<vector<int>> &edges, unordered_map<int, list<int>> &adjList)
    {
        // Traverse the edges vector.
        for (int i = 0; i < edges.size(); i++)
        {
            // vertex 'u'.
            int u = edges[i][0];

            // vertex 'v'.
            int v = edges[i][1];

            // Create edge from 'u' to 'v' and from 'v' to 'u', because the graph is undirected graph.
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }
    /* Modified DFS for finding bridges in a graph - Trajan's Algorithm. */
    void trajansAlgorithm(int node, int parent, int &timer, vector<int> &visited, vector<int> &nodeDiscoveryTime, vector<int> &lowestDiscoveryTime, vector<vector<int>> &bridges, unordered_map<int, list<int>> &adjList)
    {
        // Mark the current node as visited.
        visited[node] = true;

        // We discover this node in 'timer' time and initially the lowest discovery time for this node is also 'timer'.
        nodeDiscoveryTime[node] = timer;
        lowestDiscoveryTime[node] = timer;

        // Now, increment the timer for upcoming node.
        timer += 1;

        // Move towards the neighbors of current node.
        for (auto neighbor : adjList[node])
        {
            // Now, current node will borrow the lowest possible discovery time from its neighbors, but current node will not borrow the lowest discovery time from its parent node.

            // So, if this neighbor is a parent node of current node, in this case, ignore this node and move to next neighbor.
            if (neighbor == parent)
            {
                continue;
            }

            // Simple DFS, Calling DFS for unvisited neighbors.
            if (!visited[neighbor])
            {
                // Calling DFS for unvisited neighbors.
                trajansAlgorithm(neighbor, node, timer, visited, nodeDiscoveryTime, lowestDiscoveryTime, bridges, adjList);

                // Backtracking Step (If all the neighbors of current node are visited, then you have to return from here).
                // But before returning from this current node, this current node will borrow the lowest possible discovery time from its neighbors.
                lowestDiscoveryTime[node] = min(lowestDiscoveryTime[node], lowestDiscoveryTime[neighbor]);

                // Now, we have to check from a bridges.
                // node ------- neighbor.
                if (lowestDiscoveryTime[neighbor] > nodeDiscoveryTime[node])
                {
                    bridges.push_back({node, neighbor});
                }
            }

            // Now, if the neighbors is already visited and not a parent of current node, in this case current node will borrow the lowest possible discovery time from its neighbors
            else
            {
                lowestDiscoveryTime[node] = min(lowestDiscoveryTime[node], lowestDiscoveryTime[neighbor]);
            }
        }
    }

public:
    /*
    Time Complexity: O(V+2E), where V = no. of vertices, E = no. of edges. It is because the algorithm is just a simple DFS traversal.

    Space Complexity: O(V+2E) + O(3V), where V = no. of vertices, E = no. of edges. O(V+2E) to store the graph in an adjacency list and O(3V) for the three arrays i.e. tin, low, and vis, each of size V.
    */
    vector<vector<int>> criticalConnections(int V, int E, vector<vector<int>> &edges)
    {
        // create an adjacency list for undirected graph.
        unordered_map<int, list<int>> adjList;
        createAdjacencyList(edges, adjList);

        // vector to store bridges.
        vector<vector<int>> bridges;

        // Timer for discovery time of nodes.
        int timer = 1;

        // visited array.
        // Initially all node are unvisited.
        vector<int> visited(V, 0);

        // Vector to store discovery time of each node, initially all nodes are undiscovered.
        vector<int> nodeDiscoveryTime(V);

        // Vector to store lowest possible discovery time for each node.
        vector<int> lowestDiscoveryTime(V);

        trajansAlgorithm(0, -1, timer, visited, nodeDiscoveryTime, lowestDiscoveryTime, bridges, adjList);

        return bridges;
    }

    /* method to print 2d vector. */
    void print2dVec(vector<vector<int>> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << "[" << arr[i][0] << ", " << arr[i][1] << "]" << endl;
        }
    }
};

int main()
{
    // vertices are labelled from 0 to V-1.
    int V = 12;

    // Edges of undirected graph.
    vector<vector<int>> edges = {
        {0, 1},
        {0, 3},
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 6},
        {5, 8},
        {6, 7},
        {7, 8},
        {7, 9},
        {9, 10},
        {9, 11},
        {10, 11},
    };
    int E = edges.size();

    // Solution.
    Solution S;
    vector<vector<int>> bridges = S.criticalConnections(V, E, edges);
    S.print2dVec(bridges);
    return 0;
}