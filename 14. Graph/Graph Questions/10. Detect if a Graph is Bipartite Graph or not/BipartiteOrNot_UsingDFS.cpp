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

    /* Depth First Search (BFS). */
    // Time Complexity: O(V) + O(2E), where V is the number of vertices and E is the number of edges in the graph.
    // In case of directed graph the Time Complexity is O(V) + O(E).
    // Space Complexity: O(V), excluding the space used by adjacency list because in most of the problems adjacency list is given.

    // Initially, the color array will have all -1s, where -1 means nodes are not colored yet.
    // And We will try to colour the nodes with 0 and 1, but you can choose other colours as well.
    // We will start with the colour 0, you can start with 1 as well, just make sure for the adjacent node, it should be opposite of what the current node has.
    bool DFS(int startVertex, int nodeColor, vector<int> &visited, vector<int> &color, unordered_map<int, list<int>> &adjList)
    {
        // Mark this starting vertex or node as visited.
        visited[startVertex] = true;

        // Color this starting vertex with color 0.
        // NodeColor value is 0 initially.
        color[startVertex] = nodeColor;

        // Make a recursive call for all the neighbors of startVertex.
        // Make sure to color all the neighbors with the opposite color to that of the startVertex.
        // All the neighbors of frontNode are present in the adjacency list.

        // Getting the color of current node because we have to color all the neighbors with the opposite color to that of the current node.
        int colorOfCurrentNode = color[startVertex];

        for (auto neighbor : adjList[startVertex])
        {
            // If a particular neighbor has already visited and it has the same color as it of the frontNode.
            // If a particular node is visited in this we have 2 cases,
            // 1st Case: the you are checking the parent node of current Node.
            // 2nd case: Graph contains a cycle.
            // that's why some other node colored this neighbor and 2 adjacent node have the same color, it means graph is not bipartite. So return false from here.

            // Getting the color of neighbor.
            int colorOfNeighbor = color[neighbor];

            if (visited[neighbor] && colorOfNeighbor == colorOfCurrentNode /* It means neighbor and parent has the same color. */)
            {
                // And if the parent node and neighbor node has the same color, it means 2 adjacent nodes have the same color.
                // It means the Graph is not Bipartite.
                // So simply return false.
                return false;
            }

            // If the neighbor node is not visited in the past, so color this neighbor node with the opposite color to that of the front node and push this neighbor into the queue.
            else if (!visited[neighbor])
            {
                // If any DFS call return false, it means the graph is not bipartite.
                // So simply return false from here.
                if(DFS(neighbor, !nodeColor, visited, color, adjList) == false)
                {
                    return false;
                }
            }
        }

        // If the above while loop does not return false, it means we are able to color the graph using 2 colors (1 and 0), it means the graph is two-colorable. It means the graph is Bipartite, so simply return true from here.
        return true;
    }

public:
    /* Return true if a graph is bipartite otherwise return false. */
    bool isBipartite(int V, int E, vector<pair<int, int>> &edges)
    {
        // Creating Adjacency List.
        unordered_map<int, list<int>> adjList;
        createAdjacencyList(edges, adjList);

        // A bipartite graph is a graph which can be coloured using 2 colours such that no adjacent nodes have the same colour.
        // Traverse the graph usig BFS or DFS and if the graphs is two-colorable, it means the graph is bipartite otherwise not.

        // Visited array.
        vector<int> visited(V, 0);

        // Color array.
        vector<int> color(V, -1); // -1 means the nodes are not colored.

        // Given Graph may contain disconnected components so we need to traverse all the vertices.
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (DFS(i, 0, visited, color, adjList) == false)
                {
                    // If the DFS function return false, it means the graph is not two-colorable.
                    // It means the graph is not Bipartite.
                    // So simply return false from here.
                    return false;
                }
            }
        }

        // If the above loop does not return false it means we are able to color the graph using 2 colors, it means the graph is two-colorable. It means the graph is Bipartite, so simply return true from here.
        return true;
    }
};

int main(void)
{
    // vertices are labelled from 0 to V - 1.
    int V = 4;
    vector<pair<int, int>> edges = {
        {0, 2},
        {2, 3},
        {3, 1},
        {0, 3},
    };
    int E = edges.size();

    // Solution.
    Solution S;
    bool ans = S.isBipartite(V, E, edges);
    cout << "Graph is Bipartite : " << ((ans == true) ? "Yes." : "No.");
}