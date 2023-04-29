#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Method to create an adjacency list of weighted graph. */
    void createAdjacencyList(vector<vector<int>> &edges, unordered_map<int, list<pair<int, int>>> &adjList)
    {
        // Traversing the edges vector.
        for (int i = 0; i < edges.size(); i++)
        {
            // Taking out the vertices and edge weight from the edges vector.
            int u = edges[i][0];
            int v = edges[i][1];
            int edgeWeight = edges[i][2]; // u -------Edge Weight-----> v

            // This is a weighted Directed Acyclic Grapg so create a directed edge from u to v and store the edge weight.
            adjList[u].push_back({v, edgeWeight});
        }
    }

    /* Topological Sort using Depth First Search (DFS). */
    // Time Complexity: O(V) + O(E), where V is the number of vertices and E is the number of edges in the graph.
    // O(E) because the graph is a directed graph.
    // Space Complexity: O(V), excluding the space used by adjacency list because in most of the problems adjacency list is given.
    void topologicalSort(int node, vector<int> &visited, stack<int> &st, unordered_map<int, list<pair<int, int>>> &adjList)
    {
        // Mark the current node as visited.
        visited[node] = true;

        // Make a DFS call for all the unvisited neighbors of current node.
        // adjList[node] will return a pair because this is a weighted graph.
        for (auto pair : adjList[node])
        {
            int neighbor = pair.first; // first block of pair contains the vertex 'v' and second block of pair contains the edge weight.

            // Calling DFS for unvisited neighbor.
            if (!visited[neighbor])
            {
                topologicalSort(neighbor, visited, st, adjList);
            }
        }

        // After visiting current node and all the neighbors of current node.
        // We can push this current node into the stack.
        st.push(node);
    }

public:
    /* Question: Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2].

    Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex. */

    /*
    Algorithm:
    Step 1: Compute the Topological Sort of the DAG. This can be done using either the DFS-based or the BFS-based algorithm, as explained earlier.

    Step 2: Initialize an array dist[] with a large value for all nodes except the source node, which is initialized to 0. The dist[] array will keep track of the shortest distance from the source node to each node in the DAG.

    Step 3: For each node u in the Topological Sort, iterate over its outgoing edges (u,v) and update the distance to node v if a shorter path is found. The new distance is given by dist[v] = min(dist[v], dist[u] + weight(u,v)), where weight(u,v) is the weight of the edge (u,v).

    Step 4: After iterating over all nodes in the Topological Sort, the dist[] array will contain the shortest distance from the source node to every other node in the DAG.
    */

    /*
    Time Complexity: O(N+M) {for the topological sort} + O(N+M) {for relaxation of vertices, each node and its adjacent nodes get traversed} ~ O(N+M).

    Space Complexity:  O( N) {for the stack storing the topological sort} + O(N) {for storing the shortest distance for each node} + O(N) {for the visited array} + O( N+2M) {for the adjacency list} ~ O(N+M) .

    Where N= number of vertices and M= number of edges.
    */
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {

        /*
        This graph contains edge weights so we have to modify the adjacency list to include the weight of each edge.

        Map will store the vertices like this,
        Adjacency List:
        Vertex ------------>  List of Neighbors or Adjacent Node
          u    ------------>      v, edge weight(u, v), where 'v' is the neighbor of 'u' and edge weight(u, v) is the weight on the edge from 'u' to 'v'.
        */
        unordered_map<int, list<pair<int, int>>> adjList;
        createAdjacencyList(edges, adjList);

        // Step 1: Compute the Topological Sort of the DAG. This can be done using either the DFS-based or the BFS-based algorithm, as explained earlier.
        // Visited array.
        vector<int> visited(N, 0);

        // Stack is used in topological sort usidng DFS.
        // After performing the topological sorting, this stack will have all the vertices in topological order.
        stack<int> st;

        // A graph may contain disconnected components so we need to traverse all the vertices.
        for (int vertex = 0; vertex < N; vertex++)
        {
            // calling topological sort for unvisited nodes.
            if (!visited[vertex])
            {
                topologicalSort(vertex, visited, st, adjList);
            }
        }

        // Step 2: Initialize an array dist[] with a large value for all nodes except the source node, which is initialized to 0. The dist[] array will keep track of the shortest distance from the source node to each node in the DAG.

        // Declaring distance array of size N, 'N' because we have total N number of vertices.
        // Initializing all the vertices with 'INT_MAX', because this INT_MAX is used for comparing and storing the shortest distance.
        vector<int> distance(N, INT_MAX);
        distance[0] = 0; // Because our source node is 0 and shortest distance source (0) to destination (0 itself) is 0.

        // Step 3: For each node u in the Topological Sort, iterate over its outgoing edges (u,v) and update the distance to node v if a shorter path is found. The new distance is given by dist[v] = min(dist[v], dist[u] + weight(u,v)), where weight(u,v) is the weight of the edge (u,v).

        while (!st.empty())
        {
            // Take out the top element of the stack.
            int top = st.top();

            // Pop the top element of the stack.
            st.pop();

            // Iterating on the neighbors of the top element of the stack and storing the shortest distance to reach the neighbors of the top element.
            // adjList[node] will return a pair because this is a weighted graph.

            // distance[top] == INT_MAX, it means we are unable to reach this particular vertex and if we are unable to reach this particular vertex so how can we move ahead from this vertex.

            // distance[top] != INT_MAX, it means we are able to reach this particular vertex and if we are able to reach this particular vertex so we move ahead from this vertex.
            if (distance[top] != INT_MAX)
            {
                for (auto pair : adjList[top])
                {
                    int neighbor = pair.first;    // first block of pair contains the vertex 'v'.
                    int edgeWeight = pair.second; // second block of pair contains the edge weight, u -------Edge Weight-----> v.

                    // Updating the distance array with the shortest distance.

                    // So currently we are standing at top (node which is presnet at the top of the stack).
                    // and we have to find the shortest distance to reach the neighbors of top.
                    distance[neighbor] = min(distance[neighbor], (distance[top] + edgeWeight));
                }
            }
        }

        // If distance array contains INT_MAX for any vertex it means that node is unreachable. So store -1 for that vertex.
        for (int i = 0; i < N; i++)
        {
            if (distance[i] == INT_MAX)
            {
                distance[i] = -1;
            }
        }

        return distance;
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
    int V = 6;
    int E = 7;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 4, 1},
        {4, 5, 4},
        {4, 2, 2},
        {1, 2, 3},
        {2, 3, 6},
        {5, 3, 1},
    };

    // Solution.
    Solution S;
    vector<int> distance = S.shortestPath(V, E, edges);
    S.printVec(distance);
}