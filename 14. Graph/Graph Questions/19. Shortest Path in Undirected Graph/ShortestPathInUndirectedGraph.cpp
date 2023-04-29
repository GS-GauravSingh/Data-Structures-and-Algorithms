#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Method to create an adjacency list of undirected graph. */
    void createAdjacencyList(vector<vector<int>> &edges, unordered_map<int, list<int>> &adjList)
    {
        // Traversing the edges vector.
        for (int i = 0; i < edges.size(); i++)
        {
            // Taking out the vertices and edge weight from the edges vector.
            int u = edges[i][0];
            int v = edges[i][1];

            // This graph is undirected graph.
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

public:
    /* Question: You are given an Undirected Graph having unit weight, Find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex. */

    // Time Complexity: O(V) + O(2E), where V is the number of vertices and E is the number of edges in the graph.
    // The while loop will run "V" times and the inner for loop will run total "2E" times.
    // In case of directed graph the Time Complexity is O(V) + O(E).
    // Space Complexity: O(V), where V is the number of vertices and E is the number of edges in the graph.
    vector<int> shortestPath(vector<vector<int>> &edges, int V, int E, int src)
    {
        // creating adjacency list.
        unordered_map<int, list<int>> adjList;
        createAdjacencyList(edges, adjList);

        // Distance Array.
        // Declaring distance array of size 'V', 'V' because we have total V number of vertices.
        // Initializing all the vertices with 'INT_MAX', because this INT_MAX is used for comparing and storing the shortest distance.
        vector<int> distance(V, INT_MAX);
        distance[src] = 0; // Because we are starting from 'src' and shortest distance to reach 'src' itself is 0.

        // Applying simple BFS and finding the shortest distance.

        // Queue.
        // First block of pair will store the vertex.
        // Second block of pair will store the distance to reach that vertex starting from src.
        queue<pair<int, int>> q;

        // Push the starting Node "src" into the queue with distance 0.
        // Because we are starting from 'src' and shortest distance to reach 'src' itself is 0.
        q.push({src, 0});

        // Traverse the queue.
        while (!q.empty())
        {
            // Take out the front node of the queue.
            pair<int, int> frontNode = q.front();

            // Pop the front element of the queue.
            q.pop();

            // Take out the vertex and distance to reach that vertex from the frontNode.
            int vertex = frontNode.first;
            int dist = frontNode.second;

            // Travering the neighbors of vertex.
            for (auto neighbor : adjList[vertex])
            {
                // BFS is a level order traversal, so if we reach a particular node, it's 100% sure that we have reached that node following the shortest path from the source node.
                if (distance[neighbor] == INT_MAX)
                {
                    // Update rthe distance of neighbor and push this neighbor into the queue.
                    distance[neighbor] = dist + 1;
                    q.push({neighbor, distance[neighbor]});
                }
            }
        }

        // If distance array contains INT_MAX for any vertex it means that node is unreachable. So store -1 for that vertex.
        for (int i = 0; i < V; i++)
        {
            if (distance[i] == INT_MAX)
            {
                distance[i] = -1;
            }
        }

        return distance;
    }

    /* Method to print vector. */
    void printVec(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(void)
{
    int V = 9;
    int E = 10;
    int src = 0;
    vector<vector<int>> edges = {
        {0, 1},
        {0, 3},
        {3, 4},
        {4, 5},
        {5, 6},
        {1, 2},
        {2, 6},
        {6, 7},
        {7, 8},
        {6, 8},
    };

    // Solution.
    Solution S;
    vector<int> ans = S.shortestPath(edges, V, E, src);
    S.printVec(ans);
}