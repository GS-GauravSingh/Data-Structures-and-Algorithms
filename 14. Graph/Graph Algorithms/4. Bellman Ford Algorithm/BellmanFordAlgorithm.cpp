#include <iostream>
#include <vector>
using namespace std;

/* --------------------------- Solution Class ------------------------------------ */
class Solution
{
private:
public:
    /* Bellman Ford Algorithm. */
    /*
    Parameters:
    'V' = total number of vertices in the graph.

    'src' = source vertex, because bellman ford is the single source shortest path algorithm and we have to find the shortest path from source node to all the other nodes in the graph.

    'edges' = vector of vectors that represents the graph, u = edges[i][0], v = edges[i][1], and edge weight (u ---- edge weight ----> v) = edges[i][2].
    */

    /*
    Time Complexity: O(V * E), where V = no. of vertices and E = no. of Edges.
    Space Complexity: O(V) for the distance array which stores the minimized distances.
    */
    vector<int> bellmanFord(int V, int src, vector<vector<int>> edges)
    {
        // Distance Array.
        // Declaring distance of size 'V', because we have to store the shortest distance from source node to all the other nodes in the graph.
        // Initializing distance array with '1e8', initially "1e8" represent that the node is unreachable and as we traverse the graph, "1e8" is used to update the distance array with the shortest distance to reach a particular node from source.
        vector<int> distance(V, 1e8);
        distance[src] = 0; // Update the distance of source node "src" with 0, because we are starting from 'src' and in order to reach 'src' itself we need to travel 0 distance.

        // Now, We will go on relaxing all the edges (n - 1) times sequentially, where n = number of vertices.
        for (int relax = 0; relax < V; relax++)
        {
            // Traversing the edges vector to relax each edge.
            for (int i = 0; i < edges.size(); i++)
            {
                // Vertex 'u'.
                int u = edges[i][0];

                // Vertex 'v'.
                int v = edges[i][1];

                // Edge Weight (u ----- edge weight ------> v).
                int edgeWeight = edges[i][2];

                // Relaxing Edges.
                // if distance[u] == 1e8, it means node 'u' is unreachable and if the node 'u' itself is unreachable, then there is no point of checking ahead, because we cannot move ahead.
                if (distance[u] != 1e8 && distance[u] + edgeWeight < distance[v])
                {
                    distance[v] = distance[u] + edgeWeight;
                }
            }
        }

        // Detecting negative cycle: We know if we keep on rotating inside a negative cycle, the path weight will be decreased in every iteration. But according to our intuition, we should have minimized all the distances within N-1 iterations(that means, after N-1 iterations no relaxation of edges is possible).

        // In order to check the existence of a negative cycle, we will relax the edges one more time after the completion of N-1 iterations. And if in that Nth iteration, it is found that further relaxation of any edge is possible, we can conclude that the graph has a negative cycle. Thus, the Bellman-Ford algorithm detects negative cycles.
        // Traversing the edges vector to relax each edge.
        for (int i = 0; i < edges.size(); i++)
        {
            // Vertex 'u'.
            int u = edges[i][0];

            // Vertex 'v'.
            int v = edges[i][1];

            // Edge Weight (u ----- edge weight ------> v).
            int edgeWeight = edges[i][2];

            // Relaxing Edges.
            if (distance[u] != 1e8 && distance[u] + edgeWeight < distance[v])
            {
                // If this condition is true, it means the graphs contains negative weight cycles.
                return {-1};
            }
        }

        // return the distance array.
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
    // Total vertices in the graph.
    int V = 6;

    // Edges of directed weighted graph.
    // u = edges[i][0].
    // v = edges[i][1].
    // edge weight (u ---- edge weight ----> v) = edges[i][2].
    vector<vector<int>> edges = {
        {3, 2, 6},
        {5, 3, 1},
        {0, 1, 5},
        {1, 5, -3},
        {1, 2, -2},
        {3, 4, -2},
        {2, 4, 3}};

    // Solution.
    Solution S;
    int src = 0;
    vector<int> ans = S.bellmanFord(V, src, edges);
    S.printVec(ans);

    return 0;
}
