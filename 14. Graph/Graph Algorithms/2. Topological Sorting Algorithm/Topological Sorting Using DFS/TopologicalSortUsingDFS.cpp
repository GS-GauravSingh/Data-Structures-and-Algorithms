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

    /* Modified Depth First Search (DFS) algorithm for Topological Sorting. */
    // Time Complexity: O(V) + O(E), where V is the number of vertices and E is the number of edges in the graph.
    // O(E) because the graph is a directed graph.
    // Space Complexity: O(V), excluding the space used by adjacency list because in most of the problems adjacency list is given.
    void DFS(int startVertex, vector<int> &visited, stack<int> &st, unordered_map<int, list<int>> &adjList)
    {
        // Mark the current node as visited.
        visited[startVertex] = true;

        // No need to print the vertex. Move towards the neighbors of current vertex.
        // First visit all the neighbors of current node and then push the current node into the stack.

        // Traversing the neighbors of current node.
        for (auto neighbor : adjList[startVertex])
        {
            // Making a DFS call for unvisited neighbors of current node.
            if (!visited[neighbor])
            {
                DFS(neighbor, visited, st, adjList);
            }
        }

        // Backtracking Step.
        // After visiting all the neighbors of current node, push the current node into the stack.
        st.push(startVertex);
    }

public:
    /* Method to return list containing vertices in Topological order. */
    vector<int> topoSort(int V, int E, vector<pair<int, int>> &edges)
    {
        // Creating adjacency list.
        unordered_map<int, list<int>> adjList;

        //  Initialize a stack to store the vertices in topological order.
        stack<int> st;

        // Visited array.
        vector<int> visited(V, 0);

        // A graph may contain disconnected components so we need to traverse all the vertices.
        for (int i = 0; i < V; i++)
        {
            // Calling DFS for unvisited nodes or vertices.
            if (!visited[i])
            {
                DFS(i, visited, st, adjList);
            }
        }

        // After the DFS traversal ends, our stack will containg the one of the topological sorting of the given graph.
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        // return answer.
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