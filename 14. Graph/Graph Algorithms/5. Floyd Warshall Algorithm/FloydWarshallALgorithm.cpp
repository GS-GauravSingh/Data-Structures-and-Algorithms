#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

/*
What is Floyd-Warshall algorithm ?

1. Floyd-Warshall algorithm is also a shortest path algorithm.
2. Floyd-Warshall algorithm is very much different from the Dijkstra’s algorithm and Bellman Ford algorithm because Dijkstra’s algorithm and Bellman Ford algorithm are single-source shortest path algorithms where we are given a single source node and we have to find the shortest distance from source node to all the other nodes in the graph. This means Dijkstra’s algorithm and Bellman Ford algorithm only compute the shortest path from a single source.
3. Floyd–Warshall’s Algorithm is used to find the shortest paths between all pairs of vertices in a graph, where each edge in the graph has a weight which is positive or negative.

Example: Suppose we have a graph with 5 vertices labelled from 0 to 4. So, for every node in this graph, floyd warshall algorithm will find the shortest path to every other node in the graph.

1. It means, If we take 0 as the source node, then the Floyd-Warshall algorithm will find the shortest path from vertex 0 to all the other nodes in the graph. That is
    1. Shortest path from vertex 0 to vertex 1.
    2. Shortest path from vertex 0 to vertex 2.
    3. Shortest path from vertex 0 to vertex 3.
    4. Shortest path from vertex 0 to vertex 4.

2. If we take 1 as the source node, then the Floyd-Warshall algorithm will find the shortest path from vertex 1 to all the other nodes in the graph.
    1. Shortest path from vertex 1 to vertex 0.
    2. Shortest path from vertex 1 to vertex 2.
    3. Shortest path from vertex 1 to vertex 3.
    4. Shortest path from vertex 1 to vertex 4.

3. If we take 2 as the source node, then the Floyd-Warshall algorithm will find the shortest path from vertex 2 to all the other nodes in the graph.
    1. Shortest path from vertex 2 to vertex 0.
    2. Shortest path from vertex 2 to vertex 1.
    3. Shortest path from vertex 2 to vertex 3.
    4. Shortest path from vertex 2 to vertex 4.

4. If we take 3 as the source node, then the Floyd-Warshall algorithm will find the shortest path from vertex 3 to all the other nodes in the graph.
    1. Shortest path from vertex 3 to vertex 0.
    2. Shortest path from vertex 3 to vertex 1.
    3. Shortest path from vertex 3 to vertex 2.
    4. Shortest path from vertex 3 to vertex 4.

5. If we take 4 as the source node, then the Floyd-Warshall algorithm will find the shortest path from vertex 4 to all the other nodes in the graph.
    1. Shortest path from vertex 4 to vertex 0.
    2. Shortest path from vertex 4 to vertex 1.
    3. Shortest path from vertex 4 to vertex 2.
    4. Shortest path from vertex 4 to vertex 3.

Basically, the Floyd Warshall algorithm is a multi-source shortest path algorithm and it helps to detect negative cycles as well.
*/

/* --------------------------- Solution Class ------------------------------------ */
class Solution
{
private:
    /* Method to create adjacency matrix for weighted directed graph. */
    void createAdjacencyMatrix(vector<vector<int>> &adjMatrix, vector<vector<int>> &edges)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            // vertex 'u'.
            int u = edges[i][0];

            // vertex 'v'.
            int v = edges[i][1];

            // edge weight (u ---- edge weight ------> v).
            int edgeWeight = edges[i][2];

            // create a directed edge from u to v.
            // In weighted Graphs, Each cell in adjacency matrix i.e., AdjMatrix[i][j] is filled with the edge weight from the ith vertex to the jth vertex.
            adjMatrix[u][v] = edgeWeight;
        }
    }

public:
    /* Floyd Warshall Algorithm. */
    /*
    Parameters:
    'V' = total number of vertices in the graph.
    'edges' = vector of vectors that represents the graph, u = edges[i][0], v = edges[i][1], and edge weight (u ---- edge weight ----> v) = edges[i][2].
    */
    vector<vector<int>> floydWarshall(int V, vector<vector<int>> edges)
    {

        // Step 1: Create a adjacency matrix for weighted directed graph.
        vector<vector<int>> adjMatrix(V, vector<int>(V, 0));
        createAdjacencyMatrix(adjMatrix, edges);

        // Treverse the adjacency matrix.
        // and Initialize the distances between pairs of vertices that are not directly connected with INT_MAX.
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                // i == j means self loops and there is no self loops in graph, that's why we set the diagonal element with 0.
                if (i == j)
                {
                    adjMatrix[i][j] = 0;
                }

                // i != j (means this is not a diagonal element) && adjMatrix[i][j] == 0, it means there is no edge from ith vertex to jth vertex, it means there is no path from ith vertex to jth vertex, and if there is no path from ith vertex to jth vertex we can store 'INT_MAX' in it because 'INT_MAX' represent there is no path from ith vertex to jth vertex.
                if (i != j && adjMatrix[i][j] == 0)
                {
                    adjMatrix[i][j] = INT_MAX;
                }
            }
        }

        // Now see this adjacency matrix as our distance array.
        // if distance[i][j] == 0, it means it is a diagonal element and in case of diagonal element value of i, j is same. Now suppose i = 0 and j = 0, i and j both are same it means it is a diagonal element and in order to reach 0 itself we need to travel 0 distance. That's why diagonal elements are set to 0.

        // if distance[i][j] == INT_MAX, it means there is no path from ith vertex to jth vertex (no directed edge from ith vertex to jth vertex) and 'INT_MAX' represent there is no path from ith vertex to jth vertex.

        // if distance[i][j] == some value, it means there is an directed edge from ith vertex to jth vertex and distance[i][j] is storing the edge weight.

        // Now, one by one pick each node (from 0 to V-1) and find the shortest path for each pair for vertices via this node.
        for (int k = 0; k < V; k++)
        {
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    // If the selected node itself is unreachable then we cannot move via this node.
                    if (adjMatrix[i][k] == INT_MAX || adjMatrix[k][j] == INT_MAX)
                    {
                        continue;
                    }

                    // and if the selected node is reachable then we can move via this node.
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }

        // Replace all INT_MAX values with -1.
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adjMatrix[i][j] == INT_MAX)
                {
                    adjMatrix[i][j] = -1;
                }
            }
        }

        /*
        Question: How to detect a negative cycle using the Floyd Warshall algorithm ?
        Answer: We have previously said that the cost of reaching a node from itself must be 0. But in the below graph, if we try to reach node 0 from itself we can follow the path: 0->1->2->0. In this case, the cost to reach node 0 from itself becomes -3 which is less than 0. This is only possible if the graph contains a negative cycle.
        So, if we find that the cost of reaching any node from itself is less than 0, we can conclude that the graph has a negative cycle.

        graph:              (0)---- -2 --->(1)----- -3 ---->(2)
                             ^                               |
                             |                               |
                             -------------- 2 ----------------

                            sum of edges weights from 0 to 0 = -2 + -3 + 2 = -3.
        */
        for (int i = 0; i < V; i++)
        {
            if (adjMatrix[i][i] < 0)
            {
                cout << "Negative weight cucle is present in the Graph.\n";
            }
        }

        // return the final array.
        return adjMatrix;
    }

    /* Method to print 2D vector. */
    void print2dVec(vector<vector<int>> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main(void)
{
    // Total vertices in the graph.
    // Vertices are labelled from 0 to V-1.
    int V = 4;

    // Edges of directed weighted graph.
    // u = edges[i][0].
    // v = edges[i][1].
    // edge weight (u ---- edge weight ----> v) = edges[i][2].
    vector<vector<int>> edges = {
        {0, 1, 2},
        {1, 0, 1},
        {1, 2, 3},
        {3, 0, 3},
        {3, 1, 5},
        {3, 2, 4},
    };

    // Solution.
    Solution S;
    vector<vector<int>> allPairShortestPath = S.floydWarshall(V, edges);
    S.print2dVec(allPairShortestPath);

    return 0;
}
