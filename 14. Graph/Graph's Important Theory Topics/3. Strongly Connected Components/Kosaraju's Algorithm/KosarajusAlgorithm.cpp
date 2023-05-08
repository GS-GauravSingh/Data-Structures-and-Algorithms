#include <bits/stdc++.h>
using namespace std;

/* ------------------------------------ Solution Class -------------------------------------------- */
class Solution
{
private:
    /* Method to create an adjacency list for directed graph. */
    void createAdjacencyList(vector<vector<int>> &edges, unordered_map<int, list<int>> &adjList)
    {
        // Traversing the edges vector.
        for (int i = 0; i < edges.size(); i++)
        {
            // Taking out the vertices.
            int u = edges[i][0];
            int v = edges[i][1];

            // Given graph is a directed graph so we have to create only one edge that is from "u" to "v".
            adjList[u].push_back(v);
        }
    }

    /* Method to reverse all the edges of directed graph. */
    void reverseGraph(vector<vector<int>> &edges, unordered_map<int, list<int>> &reverseAdjList)
    {
        // Traversing the edges vector.
        for (int i = 0; i < edges.size(); i++)
        {
            // Taking out the vertices.
            int u = edges[i][0];
            int v = edges[i][1];

            // Reverse the edge.
            reverseAdjList[v].push_back(u);
        }
    }

    /* Method to sort all the node according to their finish time. */
    void sortNodeAccToFinishTIme(int startNode, vector<int> &visited, stack<int> &st, unordered_map<int, list<int>> &adjList)
    {
        // This method is almost same as DFS, but with one more line of code.
        // Mark the current node as visited.
        visited[startNode] = true;

        // First visit all the neighbors of current node and then push the current node into the stack.
        // Traversing the neighbors of current node.
        for (auto neighbor : adjList[startNode])
        {
            // Making a DFS call for unvisited neighbors of current node.
            if (!visited[neighbor])
            {
                sortNodeAccToFinishTIme(neighbor, visited, st, adjList);
            }
        }

        // Backtracking Step (This is an extra step we need in order to store the nodes according to their finish time).
        // After visiting all the neighbors of current node, push the current node into the stack.
        st.push(startNode);
    }

    /* Depth First Search (DFS). */
    void DFS(int startNode, vector<int> &visited, unordered_map<int, list<int>> &adjList)
    {
        // This method is almost same as DFS, but with one more line of code.
        // Mark the current node as visited.
        visited[startNode] = true;

        // First visit all the neighbors of current node and then push the current node into the stack.
        // Traversing the neighbors of current node.
        for (auto neighbor : adjList[startNode])
        {
            // Making a DFS call for unvisited neighbors of current node.
            if (!visited[neighbor])
            {
                DFS(neighbor, visited, adjList);
            }
        }
    }

public:
    /* Method to find number of strongly connected components in the graph. */

    /*
    Time Complexity: O(V+E) + O(V+E) + O(V+E) ~ O(V+E) , where V = no. of vertices, E = no. of edges. The first step is a simple DFS, so the first term is O(V+E). The second step of reversing the graph and the third step, containing DFS again, will take O(V+E) each.
    Space Complexity: O(V)+O(V)+O(V+E), where V = no. of vertices, E = no. of edges. Two O(V) for the visited array and the stack we have used. O(V+E) space for the reversed adjacent list.
    */
    int kosaraju(int V, int E, vector<vector<int>> &edges)
    {
        // create an adjacency list for directed graph.
        unordered_map<int, list<int>> adjList;
        createAdjacencyList(edges, adjList);

        // Algorithm Steps are as follows:
        // Step 1: Sort all the nodes according to their finishing time.
        stack<int> st;
        vector<int> visited(V, 0);
        // Graph may contains disconnected components so we need to traverse the all the vertices.
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                sortNodeAccToFinishTIme(i, visited, st, adjList);
            }
        }

        // After this, our stack will store all node according to their finish time.

        // Step 2: Reverse all the edges of the entire graph.
        unordered_map<int, list<int>> reverseAdjList;
        reverseGraph(edges, reverseAdjList);

        // Step 3: Perform the DFS and count the no. of different DFS calls to get the no. of SCC.
        // Mark all nodes as unvisited in visited array.
        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
        }

        // Graph may contains disconnected components so we need to traverse the all the vertices.
        int countSCC = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();

            // After reversing all the edges, this DFS will traverse all the node of a particular SCC and DFS will not move to the next SCC.
            if (!visited[node])
            {
                countSCC++;
                DFS(node, visited, reverseAdjList);
            }
        }

        return countSCC;
    }
};

int main()
{
    // Vertices are labelled from 0 to V-1.
    int V = 5;

    // Edges of directed graph.
    vector<vector<int>> edges = {
        {0, 2},
        {0, 3},
        {1, 0},
        {2, 1},
        {3, 4},
    };
    int E = edges.size();

    // Solution.
    Solution S;
    int ans = S.kosaraju(V, E, edges);
    cout << "The number of strongly connected components is: " << ans << endl;

    return 0;
}