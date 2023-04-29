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
            // Taking out the vertices from edges vector.
            int u = edges[i].first;
            int v = edges[i].second;

            // Given Graph is a directed graph se we have to create only one edges that is from "u" to "v".
            // For this question we have to reverse the edges, that is edges is from "v" to "u".
            adjList[v].push_back(u);
        }
    }

public:
    /* Question: A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.
    A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.
    You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order. */

    /*
    Time Complexity: O(V+E)+O(N*logN), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm. Extra O(N*logN) for sorting the safeNodes array, where N is the number of safe nodes.

    Space Complexity: O(N) + O(N) + O(N) ~ O(3N), O(N) for the indegree array, O(N) for the queue data structure used in BFS(where N = no.of nodes), and extra O(N) for the adjacency list to store the graph in a reversed order.
    */
    vector<int> eventualSafeNodes(int V, int E, vector<pair<int, int>> &edges)
    {
        // create a reverse adjacency list.
        // Terminal nodes are the node having outdegree = 0, but after reversing the graph.
        // Terminal nodes becomes the node having indegree = 0.

        // The intution behind reversing the graph is to make indgree '0' for terminal nodes, because terminal node are safe node.
        // and when we start our traversal form a terminal node, our topological sort algo. will traverse all the nodes that were actually end up at a terminal node.
        unordered_map<int, list<int>> adjList;
        createAdjacencyList(edges, adjList);

        // Perform Topological Sorting Using Kahn's Algorithm.

        // Compute the in-degree (i.e., number of incoming edges) of each vertex in the graph.
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

        // Push all the terminal nodes (vertices having indegree '0') into the queue.
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

        // sort the answer vector.
        sort(ans.begin(), ans.end());
        return ans;
    }

    /* Method to print vector. */
    void printVec(vector<int> &arr)
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
    // The vertices in the graph are labelled from 0 to V-1.
    int V = 7;

    // Edges of Directed Graph.
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {1, 2},
        {2, 5},
        {3, 0},
        {4, 5},
    };

    int E = edges.size();

    // Solution.
    Solution S;
    vector<int> safeNodes = S.eventualSafeNodes(V, E, edges);
    S.printVec(safeNodes);
}