#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Graph Class ------------------------------- */
class Solution
{
private:
    /* Data Members or Properties of Graph Class. */

public:
    /* Methods or Behavior of Graph Class. */

    /* You are given an undirected grapg of "V" number of nodes(vertices) and "E" number of edges. Your task is to create the graph and print the adjacency list of the graph. */

    // Time Complexity: O(V+E).
    // Space Complexity: O(V+E).
    void printAdjacency(int V, int E, vector<vector<int>> &edges)
    {
        // adjacecny list.
        unordered_map<int, list<int>> adjList;

        for (int i = 0; i < E; i++)
        {
            // Extracting nodes from edges vector.
            int u = edges[i][0];
            int v = edges[i][1];

            // Give graph is undirected graph so we have to create 2 edges.
            // First is from "u" to "v" and second is from "v" to "u".
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // printing adjacency list.
        cout << "Adjacency List of the graph:" << endl;
        cout << "Format of Printing: Vertex -> Connected Vertices.\n";
        for (auto i : adjList)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main(void)
{
    int V = 3;
    int E = 2;

    vector<vector<int>> edges = {
        {2, 1},
        {2, 0},
    };

    Solution S;
    S.printAdjacency(V, E, edges);
}