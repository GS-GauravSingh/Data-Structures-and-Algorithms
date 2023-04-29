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

    /* Depth First Search (DFS). */
    // Time Complexity: O(V) + O(2E), where V is the number of vertices and E is the number of edges in the graph.
    // In case of directed graph the Time Complexity is O(V) + O(E).
    // Space Complexity: O(V), excluding the space used by adjacency list because in most of the problems adjacency list is given.
    bool DFS(int startVertex, vector<int> &visited, vector<int> &dfsVisited, unordered_map<int, list<int>> &adjList)
    {
        // Mark the starting node as visited.
        visited[startVertex] = true;

        // Mark the dfsVisited of startVertex as true.
        dfsVisited[startVertex] = true;

        // Make a recursive call for all the neighbors.
        for (auto neighbor : adjList[startVertex])
        {
            // If any particular node is visited in the past and that node is the part of our current path, it means the cycle is present.
            // If a directed graph contains a cycle, the node has to be visited again on the same path and not through different paths.
            if (visited[neighbor] && dfsVisited[neighbor])
            {
                // Cycle Present.
                return true;
            }

            // Make a recursive call for unvisited neighbors.
            else if (!visited[neighbor])
            {
                // If any of the DFS calls return true it means cycle is present.
                if (DFS(neighbor, visited, dfsVisited, adjList) == true)
                {
                    // Cycle present.
                    return true;
                }
            }
        }

        // Backtracking Step, It means we are comming back from a particular path.
        // So, if you are coming back from any particular node, that node is no longer a part of your current path.
        // So mark the dfsvisited of that node as false.
        dfsVisited[startVertex] = false;

        // return false, it means cycle is not present.
        return false;
    }

public:
    /* Return true is cycle is present otherwise return false. */
    bool isCyclic(int V, int E, vector<pair<int, int>> &edges)
    {
        // Creating Adjacency List.
        unordered_map<int, list<int>> adjList;
        createAdjacencyList(edges, adjList);

        // Visited array.
        vector<int> visited(V, 0);

        // DFS visited.
        // when we are traversing the Graph using DFS this dfsVisited is used to check which nodes are part of our current path.
        vector<int> dfsVisited(V, 0);

        // Given Graph may contain disconnected components so we need to traverse all the vertices.
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (DFS(i, visited, dfsVisited, adjList) == true)
                {
                    // If the DFS function return true, it means cycle is present.
                    // So simply return true from here.
                    return true;
                }
            }
        }

        // If the above loop does not return true it means cycle is not present in the graph.
        // So simple return false from here.
        return false;
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