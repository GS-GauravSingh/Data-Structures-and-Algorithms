#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Depth First Search (DFS) Traversal ------------------------------- */
class DepthFirstSearchTraversal
{
private:
    /* Depth First Search Algorithm. */
    // Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
    // Space Complexity: O(V), recursive stack space.
    void DepthFirstSearch(int startVertex, vector<int> &ans, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited)
    {
        // matk the current node as visited.
        visited[startVertex] = true;

        // Store the current node is answer list.
        ans.push_back(startVertex);

        // Move toward the neighbors of current node.
        // All the neighbours of current node is present in the adjacency list.
        for(auto neighbor : adjList[startVertex])
        {
            // Make a recursive call to the neighbors which are not visited in the past.
            if(!visited[neighbor])
            {
                DepthFirstSearch(neighbor, ans, adjList, visited);
            }
        }
    }

public:


    /* Given graph is undirected and may contain disconnected components. */
    vector<int> DFS(int vertex, vector<pair<int, int>> edges)
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

        // Step 2: Traverse the graph using DFS, remember this graph may contains disconnected components so you need to traverse all the vertices.
        unordered_map<int, bool> visited; // map to check if a particular node is visited or not.
        vector<int> dfsTraversal;         // vector to store the BFS Traversal.
        for (int i = 0; i < vertex; i++)
        {
            if (!visited[i])
            {
                DepthFirstSearch(i, dfsTraversal, adjList, visited);
            }
        }

        // return the BFS traversal.
        return dfsTraversal;
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
    DepthFirstSearchTraversal dfs;
    vector<int> ans = dfs.DFS(V, edges);
    cout<<"DFS Traversal of given graph is: ";
    dfs.printVec(ans);
}