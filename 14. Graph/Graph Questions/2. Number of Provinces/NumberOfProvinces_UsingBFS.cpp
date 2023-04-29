#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Breadth First Search Algorithm (BFS). */
    // Time Complexity: O(V) + O(2E), where V is the number of vertices and E is the number of edges in the graph.
    // The while loop will run "V" times and the inner for loop will run total "2E" times.
    // In case of directed graph the Time Complexity is O(V) + O(E).
    // Space Complexity: O(V), where V is the number of vertices and E is the number of edges in the graph.
    void BreadthFirstSearch(int startVertex, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited)
    {
        // The queue is used to keep track of the vertices that have been visited but not processed yet.
        queue<int> q;

        // push the starting vertex into the queue.
        q.push(startVertex);

        // mark the starting vertex as visited.
        visited[startVertex] = true;

        // Perfrom BFS.
        while (!q.empty())
        {
            // Take out the front node or vertex from the queue.
            int frontNode = q.front();

            // Pop the front node or vertex from the queue.
            q.pop();

            // Print that front Node that you took out from the queue before popping it.
            // For this question, there is no need fron for printing and stroing the nodes.

            // Now, Push all the neighbors of frontNode into the queue only when the neighbours is not visited.
            // All the neighbours of frontNode is present in the adjacency list.
            for (auto neighbor : adjList[frontNode])
            {
                // If neighbor is not visited in the past, then push it into the queue.
                if (!visited[neighbor])
                {
                    q.push(neighbor);

                    // mark this neighbour as visited.
                    visited[neighbor] = true;
                }
            }
        }
    }

public:
    /* Question: Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces. */

    /* Approach: Basically we have to find the number of disconnected components. */

    // Time Complexity: O(V^2) for converting adjacency matrix to adjacency list + (O(V) + O(2E)) time complexity of BFS, V is the number of nodes / vertices in the graph.
    // Space Complexity: O(V) + O(2E) space used to store adjacnecy list + O(V) for queue data structure.
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
                BreadthFirstSearch(i, adjList, visited);

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