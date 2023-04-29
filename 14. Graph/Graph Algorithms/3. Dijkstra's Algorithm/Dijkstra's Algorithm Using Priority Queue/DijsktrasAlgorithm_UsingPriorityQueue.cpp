#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Method to create adjacency list of weighted graph.  */
    void createAdjacencyList(vector<vector<int>> &edges, unordered_map<int, list<pair<int, int>>> &adjList)
    {
        // Traverse the edges vector.
        for (int i = 0; i < edges.size(); i++)
        {
            // Taking out the vertices and edge weight.
            int u = edges[i][0];
            int v = edges[i][1];
            int edgeWeight = edges[i][2]; // u ----- edge weight -------- v.

            // undirected graph.
            adjList[u].push_back({v, edgeWeight});
            adjList[v].push_back({u, edgeWeight});
        }
    }

public:
    /* Dijkstra's algorithm is a popular algorithm for finding the shortest path between a starting node and all other nodes in a weighted graph. It is named after the Dutch computer scientist Edsger W. Dijkstra, who proposed it in 1956.

    Dijkstra's algorithm can be implemented using various data structures, including:

    1. Set.
    2. Priority Queue (Heap).
    3. Queue.

    And this is the Priority Queue Implementation of Dijkstra's Algorithm.

    Note: Dijkstra's Algorithm will not work on the graphs that contains negative edge weights. Dijkstra's Algorithm is specifically designed for graphs that do not contain negative edge weights.

    Reason: Dijkstra's Algorithm is based on the assumption that the shortest path between two nodes in a graph with non-negative weights is the path with the smallest total weight. If the graph has negative weights, this assumption is no longer true, and the algorithm may not give the correct result. Negative weights can cause the algorithm to get stuck in a loop, or to choose a suboptimal path. Therefore, to ensure the correctness of the algorithm, the graph should not contain negative weights.

    Example: assume we have a graph with -ve weights,
    graph:      0 ----- (-2) ----- 1, assume that the source node is '0'.

    */

    /*
    Time Complexity: O( E log(V) ), Where E = Number of edges and V = Number of Nodes.
    Space Complexity: O( |E| + |V| ), Where E = Number of edges and V = Number of Nodes.
    */
    vector<int> dijkstra(int V, int E, int src, vector<vector<int>> &edges)
    {
        // create an adjacency list.
        unordered_map<int, list<pair<int, int>>> adjList;
        createAdjacencyList(edges, adjList);

        // Min-Heap is used in this Priority Queue implementation of Dijkstra's Algorithm.
        // Priority Queue which would contain pairs of the type {dist, node}, where ‘dist’ indicates the currently updated value of the shortest distance from the source to the ‘node’.
        // The node with minimum distance will present at the top of the min heap, because in Min-Heap minimum element is present at the top.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-Heap.

        // Distance Array.
        // Declaring distance of size 'V', because we have to store the shortest distance from source node to all the other nodes in the graph.
        // Initializing distance array with 'INT_MAX', initially "INT_MAX" represent that the node is unreachable and as we traverse the graph, "INT_MAX" is used to update the distance array with the shortest distance to reach a particular node from source.
        vector<int> distance(V, INT_MAX);
        distance[src] = 0; // Update the distance of source node "src" with 0, because we are starting from 'src' and in order to reach 'src' itself we need to travel 0 distance.

        // Push the 'src' node into the priority queue with the distance 0.
        // Pair is of type {distance, Node}.
        pq.push({0, src});

        // Traverse the priority queue.
        while (!pq.empty())
        {
            // Take out the top element from the priority queue.
            pair<int, int> topElement = pq.top();

            // Pop the top element of the priority queue.
            pq.pop();

            // Take out the node(vertex) and distance from the topElement.
            // Pair is of type {distance, Node}.
            int dist = topElement.first;
            int node = topElement.second;

            // Update the distance of neighbors of node.
            // adjList will return a pair of type {node, edge weight}.
            for (auto pair : adjList[node])
            {
                int neighbor = pair.first;    // neighbor of node.
                int edgeWeight = pair.second; // node ---- edge weight ----- neighbor.

                // Everytime we find the shortest distance to reach the neighbor node from current node "node".
                // we update the distance of neighbor node and push this neighbor into the priority queue.
                if ((dist + edgeWeight) < distance[neighbor])
                {
                    // update the distance.
                    distance[neighbor] = (dist + edgeWeight);

                    // push this pair into the queue.
                    pq.push({distance[neighbor], neighbor});
                }
            }
        }

        // in distance array, if "INT_MAX" is store for any vertex it means that node is unreachable from given source.
        // So store -1 at that index.
        for (int i = 0; i < V; i++)
        {
            if (distance[i] == INT_MAX)
            {
                distance[i] = -1;
            }
        }

        // finally return the distance array.
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
    // Nodes are labelled from 0 to V-1.
    int V = 6;

    // Edhes of Weighted Undirected Graph.
    // u = edges[i][0].
    // v = edges[i][1].
    // edge weight (u ------ edge weight ----- v) = edges[i][2].
    vector<vector<int>> edges = {
        {0, 1, 4},
        {0, 2, 4},
        {1, 2, 2},
        {2, 3, 3},
        {2, 5, 6},
        {2, 4, 1},
        {3, 5, 2},
        {4, 5, 3},
    };
    int E = edges.size();

    // Solution.
    Solution S;
    int sourceVertex = 0;
    vector<int> dist = S.dijkstra(V, E, sourceVertex, edges);
    S.printVec(dist);
}