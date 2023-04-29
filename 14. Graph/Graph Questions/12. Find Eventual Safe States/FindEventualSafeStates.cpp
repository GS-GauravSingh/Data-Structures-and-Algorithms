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
            adjList[u].push_back(v);
        }
    }

    /* Cycle Detection using Depth First Search (DFS). */
    // Time Complexity: O(V) + O(2E), where V is the number of vertices and E is the number of edges in the graph.
    // In case of directed graph the Time Complexity is O(V) + O(E).
    // Space Complexity: O(V), excluding the space used by adjacency list because in most of the problems adjacency list is given.
    bool DFS(int startVertex, vector<int> &visited, vector<int> &dfsVisited, vector<int> &checkCycle, unordered_map<int, list<int>> &adjList)
    {
        // Mark the starting node as visited.
        visited[startVertex] = true;

        // Mark the dfsVisited of startVertex as true.
        dfsVisited[startVertex] = true;

        // Initially we cannot say if the cycle is present or not.
        // So for the current node store '0' in the checkCycle vector.
        checkCycle[startVertex] = 0;

        // Make a recursive call for all the neighbors.
        for (auto neighbor : adjList[startVertex])
        {
            // If any particular node is visited in the past and that node is the part of our current path, it means the cycle is present.
            // If a directed graph contains a cycle, the node has to be visited again on the same path and not through different paths.
            if (visited[neighbor] && dfsVisited[neighbor])
            {
                // Now, if the cycle is present this function will return true from here and when this condition evaluates to true it means cycle is present and we are standing at the starting or ending node of the cycle because in case of cycle starting and ending nodes are same.
                // So this node can never be the safe node because this node is the part of the cycle. So mark this node as 1 in our checkCycle vector.
                checkCycle[startVertex] = 1;

                // Cycle Present.
                return true;
            }

            // Make a recursive call for unvisited neighbors.
            else if (!visited[neighbor])
            {
                // If any of the DFS calls return true it means cycle is present.
                if (DFS(neighbor, visited, dfsVisited, checkCycle, adjList) == true)
                {
                    // If any of the DFS calls return true it means cycle is present and current node is the part of the cycle.
                    // So this node can never be the safe node because this node is the part of the cycle. So mark this node as 1 in our checkCycle vector.
                    checkCycle[startVertex] = 1;

                    // Cycle present.
                    return true;
                }
            }
        }

        // Backtracking Step, It means we are comming back from a particular path.
        // So, if you are coming back from any particular node, that node is no longer a part of your current path.
        // So mark the dfsvisited of that node as false.
        dfsVisited[startVertex] = false;

        // While comming back from a particular path it means cycle is not present, so mark the current node as 0 is our checkCycle vector.
        checkCycle[startVertex] = 0;

        // return false, it means cycle is not present.
        return false;
    }

public:
    /* Question: A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.
    A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.
    You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order. */

    /* Intution: If we closely observe, all possible paths starting from a node are going to end at some terminal node unless there exists a cycle and the paths return back to themselves.

    So, every node that is a part of the cycle and every node which is connected to the cycle can never be the safe node and Apart from these types of nodes, every node is a safe node.

    And we can easily figure out these type of nodes using cycle detection technique.
    */
    vector<int> eventualSafeNodes(int V, int E, vector<pair<int, int>> &edges)
    {
        // first create adjacency list.
        unordered_map<int, list<int>> adjList;
        createAdjacencyList(edges, adjList);

        // Mark all the nodes which are connected to the cycle or nodes which are part of the cycle as visited.
        // and rest all the node are safe nodes.

        // visited array.
        vector<int> visited(V, 0);

        // DFS Visited array.
        vector<int> dfsVisited(V, 0);

        // This vector is used to check is a particular node is a part of the cycle or not or
        // it is used to check is a particular node is connected to the cycle or not.
        vector<int> checkCycle(V, 0);

        // vector to store safe nodes.
        vector<int> safeNodes;

        // Graph may contain disconnected components so we need to traverse all the vertices.
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                // Any node which is a part of the cycle and any node which is connected to the cycle can never be the safe node.
                DFS(i, visited, dfsVisited, checkCycle, adjList);
            }
        }

        // Traverse the checkCycle vector and store the safe nodes.
        // checkCycle[i] == 1, it means ith node is a part of the cycle or it is connected to the cycle.
        // checkCycle[i] == 0, it means ith node is not a part of the cycle or it is not connected to the cycle. So its a safe node.
        for (int i = 0; i < checkCycle.size(); i++)
        {
            if (checkCycle[i] == 0)
            {
                safeNodes.push_back(i);
            }
        }

        // return safe nodes.
        return safeNodes;
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