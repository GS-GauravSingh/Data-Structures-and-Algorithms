#include <bits/stdc++.h>
using namespace std;

/*
What is a Articulation Point ?
In a graph, a Articulation point is a node on whose removal the graphs breaks down into multiple components.
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
    void trajansAlgorithm(int node, int parent, int &timer, vector<int> &visited, vector<int> &nodeDiscoveryTime, vector<int> &lowestDiscoveryTime, vector<int> &ap, unordered_map<int, list<int>> &adjList)
    {
        // Mark the current node as visited.
        visited[node] = true;

        // We discover this node in 'timer' time and initially the lowest discovery time for this node is also 'timer'.
        nodeDiscoveryTime[node] = timer;
        lowestDiscoveryTime[node] = timer;

        // Now, increment the timer for upcoming node.
        timer += 1;

        // Logic for starting vertex.
        // variable to count total number of neighbors of a particular node. this is used only when we encounter the starting node.
        int childCount = 0;

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
                trajansAlgorithm(neighbor, node, timer, visited, nodeDiscoveryTime, lowestDiscoveryTime, ap, adjList);

                // Backtracking Step (If all the neighbors of current node are visited, then you have to return from here).
                // But before returning from this current node, this current node will borrow the lowest possible discovery time from its neighbors.
                lowestDiscoveryTime[node] = min(lowestDiscoveryTime[node], lowestDiscoveryTime[neighbor]);

                // Now, we have to check whether this node is a articulation point or not.
                // node ------- neighbor.
                if ((lowestDiscoveryTime[neighbor] >= nodeDiscoveryTime[node]) && parent != -1)
                {
                    // this node is a articulation point.
                    ap[node] = true;
                }

                // increment the child count.
                childCount++;
            }

            // Now, if the neighbors is already visited and not a parent of current node, in this case current node will borrow the  discovery time from its neighbors.
            else
            {
                lowestDiscoveryTime[node] = min(lowestDiscoveryTime[node], nodeDiscoveryTime[neighbor]);
            }
        }

        // If the starting vertex has more than 1 child / neighbors, then we can say that the starting vertex is an articulation point because after removing the starting point the graph gets divided into multiple components.
        // But the starting vertex has onlt 1 chile/neighbor, then we can say that the starting vertex is not an articulation point because after removing the starting point the graph does not break into multiple components.
        if (childCount > 1 && parent == -1 /* starting vertex has no parent. */)
        {
            ap[node] = 1;
        }
    }

public:
    /*
    Time Complexity: O(V+2E), where V = no. of vertices, E = no. of edges. It is because the algorithm is just a simple DFS traversal.
    Space Complexity: O(3V), where V = no. of vertices. O(3V) is for the three arrays i.e. discovery time, lowest discovery time, and visited, each of size V.
    */
    vector<int> articulationPoints(int V, int E, vector<vector<int>> &edges)
    {
        // create an adjacency list for undirected graph.
        unordered_map<int, list<int>> adjList;
        createAdjacencyList(edges, adjList);

        // vector to store articulation points.
        vector<int> ap(V, 0);

        // Timer for discovery time of nodes.
        int timer = 1;

        // visited array.
        // Initially all node are unvisited.
        vector<int> visited(V, 0);

        // Vector to store discovery time of each node, initially all nodes are undiscovered.
        vector<int> nodeDiscoveryTime(V);

        // Vector to store lowest possible discovery time for each node.
        vector<int> lowestDiscoveryTime(V);

        // A graph may contains disconnected components so we need to traverse all the vertices.
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                trajansAlgorithm(i, -1, timer, visited, nodeDiscoveryTime, lowestDiscoveryTime, ap, adjList);
            }
        }

        // Extract the articulations points from 'ap' vector and store it in answer vector.
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (ap[i] == 1)
            {
                ans.push_back(i);
            }
        }

        // If answer vector is empty, it means there is no articulation points in the graph, so return -1.
        if (ans.empty())
        {
            return {-1};
        }

        return ans;
    }

    /* method to print vector. */
    void printVec(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << endl;
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
    vector<int> points = S.articulationPoints(V, E, edges);
    S.printVec(points);
    return 0;
}