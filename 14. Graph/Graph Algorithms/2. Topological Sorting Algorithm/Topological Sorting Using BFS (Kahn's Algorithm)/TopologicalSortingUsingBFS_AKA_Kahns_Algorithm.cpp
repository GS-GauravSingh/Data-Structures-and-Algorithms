#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Method to create an adjacency list for directed graph. */
    void createAdjacencyList(vector<pair<int, int>> &edges, unordered_map<int, list<int>> &adjList)
    {
        // Traversing the edges vector.
        for (int i = 0; i < edges.size(); i++)
        {
            // Taking out the vertices.
            int u = edges[i].first;
            int v = edges[i].second;

            // Given graph is a directed graph so we have to create only one edge that is from "u" to "v".
            adjList[u].push_back(v);
        }
    }

public:
    /* Kahn's Algorithm (Modified BFS). */
    // Time Complexity: O(V) + O(E), where V is the number of vertices and E is the number of edges in the graph.
    // O(E) because the given graph is a directed graph.
    // Space Complexity: O(V).
    vector<int> topoSort(int V, int E, vector<pair<int, int>> &edges)
    {
        // Step 1: Create an adjacency list.
        unordered_map<int, list<int>> adjList;
        createAdjacencyList(edges, adjList);

        // Step 2: Compute the in-degree (i.e., number of incoming edges) of each vertex in the graph.
        vector<int> indegree(V, 0); // vector to store indegree of each vertex.

        // How to find the indegree?
        // By visiting the adjacency list, we can find out the indegrees for each node. For example, if node 3 is an adjacent node of node 2, we will just increase indegree[3] by 1 as the adjacency list suggests that node 3 has an incoming edge from node 2.
        for (int i = 0; i < V; i++)
        {
            for (auto neighbor : adjList[i])
            {
                indegree[neighbor]++;
            }
        }

        // Step 3: Push all the vertices having indegree '0' into the queue.
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // vector to store answer.
        vector<int> ans;

        // Traverse the queue.
        while (!q.empty())
        {
            // Take out the front node of the queue.
            int frontNode = q.front();

            // Pop the fron node of the queue.
            q.pop();

            // Store the front Node into our answer list.
            ans.push_back(frontNode);

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

        // After the above loop ends, our answer list will contains the vertices in topological order.
        return ans;
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
    // Vertices are labelled from 0 to V - 1.
    int V = 4;

    // Edges of Directed Acyclic Graph.
    vector<pair<int, int>> edges = {
        {1, 0},
        {2, 0},
        {3, 0},
    };

    int E = edges.size();

    // Solution.
    Solution S;
    vector<int> ans = S.topoSort(V, E, edges);
    cout << "Topological Sort for given graph is : ";
    S.printVec(ans);
}