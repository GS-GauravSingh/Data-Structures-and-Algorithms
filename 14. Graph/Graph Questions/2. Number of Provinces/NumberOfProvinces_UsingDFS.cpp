#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Depth First Search Algorithm (DFS). */
    // Time Complexity: O(V) + O(2E), where V is the number of vertices and E is the number of edges in the graph.
    // In case of directed graph the Time Complexity is O(V) + O(E).
    // Space Complexity: O(V), excluding the space used by adjacency list because in most of the problems adjacency list is given.
    void DepthFirstSearch(int startVertex, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited)
    {
        // mark the starting vertex as visited.
        visited[startVertex] = true;

        // For this question, there is no need for printing and stroing the nodes.

        // Make a recursive call for those neighbors who are not visited.
        // All the neighbours is present in the adjacency list.
        for (auto neighbor : adjList[startVertex])
        {
            // Make a recursive call for those neighbors who is not visited in the past
            if (!visited[neighbor])
            {
                DepthFirstSearch(neighbor, adjList, visited);
            }
        }
    }

public:
    /* Question: Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces. */

    /* Approach: Basically we have to find the number of disconnected components. */

    // Time Complexity: O(V^2) for converting adjacency matrix to adjacency list + (O(V) + O(2E)) time complexity of DFS, V is the number of nodes / vertices in the graph.
    // Space Complexity: O(V) + O(2E) space used to store adjacnecy list + O(V) recursive stack space.
    int numProvinces(vector<vector<int>> adjacencyMatrix, int V)
    {
        // Creating adjacency list from given adjacency matrix.
        unordered_map<int, list<int>> adjList;
        for (int u = 0; u < V; u++)
        {
            for (int v = 0; v < V; v++)
            {
                if (adjacencyMatrix[u][v] == 1 && u != v /* u == v, means self loop. */)
                {
                    // given graph is undirected.
                    adjList[u].push_back(v);
                    adjList[v].push_back(u);
                }
            }
        }

        // Counting the disconnected components.
        int disconnectedComponents = 0;
        unordered_map<int, bool> visited; // map to check if a particular node is visited or not.
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DepthFirstSearch(i, adjList, visited);

                // count the disconnected components.
                disconnectedComponents++;
            }
        }

        return disconnectedComponents;
    }
};

int main(void)
{
    int V = 3;
    vector<vector<int>> adjMatrix = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1},
    };

    // Solution.
    Solution S;
    cout << S.numProvinces(adjMatrix, V);
}