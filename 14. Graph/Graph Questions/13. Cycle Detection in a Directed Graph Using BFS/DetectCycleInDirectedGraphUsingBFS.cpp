#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Method to create an adjacency list. */
    void createAdjacencyList(vector<pair<int, int>> &edges, unordered_map<int, list<int>> &adjList)
    {
        // Traversing the edges vector.
        for (int i = 0; i < edges.size(); i++)
        {
            // Take out the vertices from edges vector.
            int u = edges[i].first;
            int v = edges[i].second;

            // Given Graph is an undirected graph so we need to create 2 edges.
            // First is from "u" to "v" and second is from "v" to "u".
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

public:
    /* Intuition:

    1. Since we know topological sorting is only possible for directed acyclic graphs(DAGs), if we apply Kahn’s algorithm in a directed cyclic graph(A directed graph that contains a cycle), it will fail to find the topological sorting(i.e. The final sorting will not contain all the nodes or vertices).

    2. So, finally, we will check the sorting to see if it contains all V vertices or not. If the result does not include all V vertices, we can conclude that there is a cycle.

    Note: The intuition is to check the size of the final topological sorting if it equals V(no. of vertices or nodes) or not.
    */

    /*
    Time Complexity: O(V) + O(E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.
    O(E) because the graph is directed graph.
    Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the in-degree array, and O(N) for the queue data structure used in BFS(where N = no.of nodes).
    */
    bool isCyclic(int V, int E, vector<pair<int, int>> &edges)
    {
        // Creating Adjacency List.
        unordered_map<int, list<int>> adjList;
        createAdjacencyList(edges, adjList);

        // Perform Topological Sorting using Kahn's Algorithm.

        // Step 1: Compute the indegree of each vertex.
        int indegree[V] = {0}; // array to store indegree of each vertex.
        for (int i = 0; i < V; i++)
        {
            for (auto neighbor : adjList[i])
            {
                indegree[neighbor]++;
            }
        }

        // Step 2: Push all the vertices having indegree '0' into the queue.
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // vector to store vertices in topological sorting.
        vector<int> topoSort;

        // Traversing the queue.
        while (!q.empty())
        {
            // Take out the front node of the queue.
            int frontNode = q.front();

            // Pop the fron node of the queue.
            q.pop();

            // Store the front Node into our answer list.
            topoSort.push_back(frontNode);

            // Traverse the neighbors of frontNode and decrement the indegree of each neighbor by 1.
            for (auto neighbor : adjList[frontNode])
            {
                indegree[neighbor]--;

                // After decrementing the indegree of neighbor, if the indegree becomes 0, then push that neighbor into the queue.
                if (indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        // After the end of the above while loop, if the topoSort vector contains all the vertices it means the graph is not cyclic and if the topoSort vector does not contain all the vertices it means the graph is cyclic.
        if (topoSort.size() == V)
        {
            // Graph is not cyclic.
            return false;
        }

        // Else, return true, it means graph is cyclic.
        return true;
    }
};

int main(void)
{
    int V = 4;
    vector<pair<int, int>> edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 3}, /* self loop. */
    };
    int E = edges.size();

    // Solution.
    Solution S;
    bool ans = S.isCyclic(V, E, edges);
    cout << "Cycle Present : " << ((ans == true) ? "Yes." : "No.");
}