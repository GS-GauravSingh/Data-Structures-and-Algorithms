#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Method to create a adjacency list for undirected weighted graph. */
    void createAdjacencyList(vector<vector<int>> &edges, unordered_map<int, list<pair<int, int>>> &adjList)
    {
        // Traverse the edges vector.
        for (int i = 0; i < edges.size(); i++)
        {
            // Take out the both the vertices and edge weight.
            int u = edges[i][0];
            int v = edges[i][1];
            int edgeWeight = edges[i][2]; // u ------- edge weight ------> v.

            // Create adjacency list according to weighted undirected graph.
            adjList[u].push_back({v, edgeWeight});
            adjList[v].push_back({u, edgeWeight});
        }
    }

public:
    /* Question: You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

    You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

    Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7. */

    /*
    Time Complexity: O( E* log(V)) { As we are using simple Dijkstra’s algorithm here, the time complexity will be or the order E*log(V)}
    Where E = Number of edges and V = No. of vertices.

    Space Complexity :  O(N) { for dist array + ways array + approximate complexity for priority queue }
    Where, N = Number of nodes.
    */
    int countPaths(int n, vector<vector<int>> &roads)
    {
        // create an adjacency list for undirected weighted graph.
        unordered_map<int, list<pair<int, int>>> adjList;
        createAdjacencyList(roads, adjList);

        // Using Dijkstra's Algorithm to find the number of shortest paths.

        // Min-Heap is used in this Priority Queue implementation of Dijkstra's Algorithm.
        // Priority Queue which would contain pairs of the type {dist, node}, where ‘dist’ indicates the currently updated value of the shortest distance from the source to the ‘node’.
        // The node with minimum distance will present at the top of the min heap, because in Min-Heap minimum element is present at the top.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-Heap.

        // Distance Array.
        // Declaring distance of size 'V', because we have to store the shortest distance from source node to all the other nodes in the graph.
        // Initializing distance array with 'INT_MAX', initially "INT_MAX" represent that the node is unreachable and as we traverse the graph, "INT_MAX" is used to update the distance array with the shortest distance to reach a particular node from source.
        vector<int> distance(n, INT_MAX);
        distance[0] = 0; // Update the distance of source node (source node is 0) with 0, because we are starting from '0' and in order to reach '0' itself we need to travel 0 distance.

        // Ways array.
        // This will store the number of ways we can reach a particular node.
        // Initializing all nodes with 0, because initially we don't know in how many ways wa can reach a particular node.
        vector<int> ways(n, 0);
        ways[0] = 1; // There is only 1 way to reach source node i.e., the source itself.


        // Push the source node '0' into the priority queue with the distance 0.
        // Pair is of type {distance, Node}.
        pq.push({0, 0});

        // Mod value
        int mod = (int)(1e9 + 7);

        // Traverse the pq.
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

                // Now, this "if" condition signifies that, we are reaching this neighbor node with the shortest distance.
                if ((dist + edgeWeight) < distance[neighbor])
                {
                    // update the distance.
                    distance[neighbor] = (dist + edgeWeight);

                    // push this pair into the queue.
                    pq.push({distance[neighbor], neighbor});

                    // Update the ways array.
                    // How many ways you can reach this neighbor ?
                    // number of ways we can reach this neighbor = number of ways we can reach the parent of this neighbor.
                    ways[neighbor] = ways[node];
                }

                // But, if we again reaches this neighbor with the same distance as before, it means that there is more than one shortes paths exists to reach this particular node.
                // so in this case we simply increment the number of ways to reach this node.
                else if ((dist + edgeWeight) == distance[neighbor])
                {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % mod;
                }
            }
        }

        // Finally, we return the number of ways to reach the (n-1)th node.
        return ways[n - 1] % mod;
    }
};

int main(void)
{
    int n = 7;
    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    // Solution.
    Solution S;
    cout << S.countPaths(n, edges);
}