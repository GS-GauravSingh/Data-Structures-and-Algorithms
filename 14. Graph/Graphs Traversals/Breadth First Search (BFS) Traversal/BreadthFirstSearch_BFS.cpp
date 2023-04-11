#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Breadth First Search (BFS) Traversal ------------------------------- */
class BreadthFirstSearchTraversal
{
private:
    /* Breadth First Search Algorithm. */
    // Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
    // Space Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
    void BreadthFirstSearch(int startVertex, vector<int> &ans, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited)
    {
        // The queue is used to keep track of the vertices that have been visited but not processed yet.
        queue<int> q;

        // push the starting vertex into the queue.
        q.push(startVertex);

        // mark the starting vertex as visited.
        visited[startVertex] = true;

        // Perfrom BFS.
        while (!q.empty())
        {
            // Take out the front node or vertex from the queue.
            int frontNode = q.front();

            // Pop the front node or vertex from the queue.
            q.pop();

            // Print that front Node that you took out from the queue before popping it.
            ans.push_back(frontNode);

            // Now, Push all the neighbors of frontNode into the queue only when the neighbours is not visited.
            // All the neighbours of frontNode is present in the adjacency list.
            for (auto neighbor : adjList[frontNode])
            {
                // If neighbor is not visited in the past, then push it into the queue.
                if (!visited[neighbor])
                {
                    q.push(neighbor);

                    // mark this neighbour as visited.
                    visited[neighbor] = true;
                }
            }
        }
    }

public:


    /* Given graph is undirected and may contain disconnected components. */
    vector<int> BFS(int vertex, vector<pair<int, int>> edges)
    {
        // Step 1: Create Graph, We have to create adjacency list of the given vertices and edges.
        unordered_map<int, list<int>> adjList; // map for creating adjacency list.
        for (int i = 0; i < edges.size(); i++)
        {
            // Extracting vertices.
            int u = edges[i].first;
            int v = edges[i].second;

            // Now, Given Graph is undirected graph.
            // And in undirected graph, we have to create two edges,
            //  First is from "u" to "v".
            //  and Second is from "v" to "u".
            adjList[u].push_back(v); // edge created from "u" to "v".
            adjList[v].push_back(u); // edge created from "v" to "u".
        }

        // Step 2: Traverse the graph using BFS, remember this graph may contains disconnected components so you need to traverse all the vertices.
        unordered_map<int, bool> visited; // map to check if a particular node is visited or not.
        vector<int> bfsTraversal;         // vector to store the BFS Traversal.
        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i])
            {
                BreadthFirstSearch(i, bfsTraversal, adjList, visited);
            }
        }

        // return the BFS traversal.
        return bfsTraversal;
    }

    /* method to print vector. */
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
    int V = 4;
    int E = 4;
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 3},
        {1, 2},
        {2, 3},
    };

    // Solution.
    BreadthFirstSearchTraversal bfs;
    vector<int> ans = bfs.BFS(V, edges);
    cout<<"BFS Traversal of given graph is: ";
    bfs.printVec(ans);
}