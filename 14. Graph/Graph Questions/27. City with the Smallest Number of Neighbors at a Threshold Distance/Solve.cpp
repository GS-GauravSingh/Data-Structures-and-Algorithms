#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

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

            // create a undirected edge from u to v.
            // In weighted Graphs, Each cell in adjacency matrix i.e., AdjMatrix[i][j] is filled with the edge weight from the ith vertex to the jth vertex.
            adjMatrix[u][v] = edgeWeight;
            adjMatrix[v][u] = edgeWeight;
        }
    }

public:
    /* Question: There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi , toi ,weighti]  represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distance Threshold. You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance, If there are multiple such cities, our answer will be the city with the greatest number.

    Note: that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path. */

    /* Basically we have to find the largest city from where we can go to the least number of cities with atmost threshold distance.

    Intution: For each node we have to find the shortest distance to every other node and this can be done using floyd warshall algorithm and after that we can easily identife the largest city from where we can go to the least number of cities with atmost threshold distance.
    */

    /*
    Time Complexity: O(V^3), as we have three nested loops each running for V times, where V = no. of vertices.
    Space Complexity: O(V^2), where V = no. of vertices. This space complexity is due to storing the adjacency matrix of the given graph.
    */
    int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold)
    {
        // Using Floyd Warshall algorithm for finding the shortest distance between every pair of vertices in the graph.
        // Step 1: Create a adjacency matrix for weighted undirected graph.
        vector<vector<int>> adjMatrix(n, vector<int>(n, 0));
        createAdjacencyMatrix(adjMatrix, edges);

        // Treverse the adjacency matrix.
        // and Initialize the distances between pairs of vertices that are not directly connected with INT_MAX.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
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

        // Now, one by one pick each node (from 0 to V-1) and find the shortest path for each pair for vertices via this node.
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
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

        // Now, adjMatrix contains the shortest distance between every pair of vertices in the graph.

        // Variable to store the largest city from where we can go to the least number of cities with atmost threshold distance.
        int cityNumber = -1;

        // Variable to store the least reachable cities from a particular city with the threshold distance.
        int cityCount = n;

        for (int i = 0; i < n; i++)
        {
            // Variable to store the total reachable cities from a particular city with the threshold distance.
            int cnt = 0;

            for (int j = 0; j < n; j++)
            {
                // from ith city if we reached the jth city and the distance is less than threshold,
                // then we can count this jth city
                if (adjMatrix[i][j] <= distanceThreshold)
                {
                    cnt++;
                }
            }

            if (cnt <= cityCount)
            {
                cityCount = cnt;
                cityNumber = i;
            }
        }

        return cityNumber;
    }
};

int main(void)
{
    // There are n cities numbered from 0 to n-1.
    int n = 4;

    // Edges of undirected weighted graph.
    // u = edges[i][0].
    // v = edges[i][1].
    // edge weight (u ---- edge weight ----> v) = edges[i][2].
    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}};

    int m = edges.size();
    int distanceThreshold = 4;

    // Solution.
    Solution S;
    cout << S.findCity(n, m, edges, distanceThreshold);

    return 0;
}
