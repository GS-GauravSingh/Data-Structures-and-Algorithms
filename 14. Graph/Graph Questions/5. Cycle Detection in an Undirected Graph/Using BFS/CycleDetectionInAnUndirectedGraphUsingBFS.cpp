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

    /* Breadth First Search Algorithm (BFS). */
    // Time Complexity: O(V) + O(2E), where V is the number of vertices and E is the number of edges in the graph.
    // The while loop will run "V" times and the inner for loop will run total "2E" times.
    // In case of directed graph the Time Complexity is O(V) + O(E).
    // Space Complexity: O(V), where V is the number of vertices and E is the number of edges in the graph.
    bool BreadthFirstSearch(int startNode, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
    {
        // Queue.
        // First block of pair represents the actual vertex.
        // Second block of pair represents the parent node of vertex.
        queue<pair<int, int>> q;

        // Push the starting Node into the queue.
        // Parent of starting node is -1, because the starting node has no parent.
        q.push({startNode, -1});

        // Mark this starting node as visited.
        visited[startNode] = true;

        // Traversing the Queue.
        while (!q.empty())
        {
            // Take out the frontNode from the queue.
            pair<int, int> frontNode = q.front();

            // Pop that front node from the queue.
            q.pop();

            // Take out the Vertex from that frontNode.
            int vertex = frontNode.first;

            // Take out the Parent node of Vertex from that frontNode.
            int parentOfVertex = frontNode.second;

            // Now, Push all the neighbors of frontNode into the queue only when the neighbours is not visited.
            // All the neighbours of frontNode is present in the adjacency list.
            for (auto neighbor : adjList[vertex])
            {
                // Condition for Cycle.
                if (visited[neighbor] == true && neighbor != parentOfVertex)
                {
                    // Cycle Present.
                    return true;
                }
                else if (!visited[neighbor])
                {
                    // Else, push neighbor into the queue and the parentNode for neighbor is vertex.
                    q.push({neighbor, vertex});

                    // mark this neighbour as visited.
                    visited[neighbor] = true;
                }
            }
        }

        // If the above loop does not return "true", it means cycle is not present in the graph.
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
                bool ans = BreadthFirstSearch(i, visited, adjList);
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