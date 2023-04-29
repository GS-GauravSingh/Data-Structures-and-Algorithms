#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Method to create an adjacency list. */
    void createAdjacencyList(unordered_map<int, list<int>> &adjList, vector<vector<int>> &edges)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            // Take out the vertices.
            int u = edges[i][0];
            int v = edges[i][1];

            // Given graph is an undirected graph and in case of Undirected graph we have to create 2 edges,
            // First is from 'u' to 'v' and second is from 'v' to 'u'.
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    /* Depth First Search Algorithm (DFS). */
    // Time Complexity: O(V) + O(2E), where V is the number of vertices and E is the number of edges in the graph.
    // In case of directed graph the Time Complexity is O(V) + O(E).
    // Space Complexity: O(V), excluding the space used by adjacency list because in most of the problems adjacency list is given.
    bool DepthFirstSearch(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
    {
        // Mark this node as visited.
        visited[node] = true;

        // Move toward the neighbors of current node.
        // All the neighbours of current node is present in the adjacency list.
        for (auto neighbor : adjList[node])
        {
            // Condition for Cycle.
            if (visited[neighbor] == true && neighbor != parent)
            {
                // Cycle Present.
                return true;
            }
            else if (!visited[neighbor])
            {
                // Call DFS for neighbor node.
                if (DepthFirstSearch(neighbor, node, visited, adjList) == true)
                {
                    // If the return value of any function call is "true", it means cycle is present.
                    // So return true.
                    return true;
                }
            }
        }

        // If the above loop does not return "true", it means cycle is not present.
        // So simply return false.
        return false;
    }

public:
    /* Method to detect cycle in an Undirected Graph. Return "Yes" is cycle is present otherwise return "No". */
    string cycleDetection(vector<vector<int>> &edges, int V, int E)
    {
        // First Create the adjacency list.
        unordered_map<int, list<int>> adjList;
        createAdjacencyList(adjList, edges);

        // Map to check if a particulare node is visited or not..
        unordered_map<int, bool> visited;

        // The graph may contains disconnected components so we need to traverse all the vertices.
        // Vertices are labeled from 1 to V.
        for (int i = 1; i <= V; i++)
        {
            if (!visited[i])
            {
                bool ans = DepthFirstSearch(i, -1, visited, adjList);
                if (ans)
                {
                    return "Yes";
                }
            }
        }
        return "No";
    }
};

int main(void)
{
    vector<vector<int>> edges = {
        {1, 2},
        {2, 3},
        {1, 3},
    };
    int V = 3;
    int E = edges.size();

    // Solution.
    Solution S;
    cout << "Cycle Present : " << S.cycleDetection(edges, V, E) << ".\n";
}