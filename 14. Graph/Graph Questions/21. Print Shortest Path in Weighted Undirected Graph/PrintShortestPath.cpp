#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Method to create adjacency list of weighted undirected graph. */
    void createAdjacencyList(vector<vector<int>> edges, unordered_map<int, list<pair<int, int>>> &adjList)
    {
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int edgeWeight = edges[i][2];

            adjList[u].push_back({v, edgeWeight});
            adjList[v].push_back({u, edgeWeight});
        }
    }

public:
    /* Question: You are given a weighted undirected graph having n+1 vertices numbered from 0 to n and m edges describing there are edges between a to b with some weight, find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1. */

    /*
    Time Complexity: O( E log(V) ) { for Dijkstra’s Algorithm } + O(V) { for backtracking in order to find the parent for each node } Where E = Number of edges and V = Number of Nodes.
    
    Space Complexity: O( |E| + |V| ) { for priority queue and dist array } + O( |V| ) { for storing the final path } Where E = Number of edges and V = Number of Nodes.
    */
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // creating adjacency list.
        unordered_map<int, list<pair<int, int>>> adjList;
        createAdjacencyList(edges, adjList);

        // Using Dijkstra's Algorithm for finding shorted path from node '1' to node 'N'.

        // Min Heap.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Distance Array.
        // Node are labelled from O to N, that's why we have to create array of size N+1.
        vector<int> distance(N + 1, INT_MAX);
        // Update the distance of source node "src" with 0, because we are starting from 'src' and in order to reach 'src' itself we need to travel 0 distance.
        distance[1] = 0; // Source node is 1.

        // Push the 'src' node into the priority queue with the distance 0.
        // Pair is of type {distance, Node}.
        pq.push({0, 1}); // source node is 1.

        // Additional Data Structure to store parent of each node.
        // Node are labelled from O to N, that's why we have to create array of size N+1.
        vector<int> parent(N + 1);
        for (int i = 0; i <= N; i++)
        {
            parent[i] = i; // Initially, a node itself is its parent.
        }

        // Traversing the priority queue.
        while (!pq.empty())
        {
            // Take out the top element of the queue.
            pair<int, int> topElement = pq.top();

            // Pop the top element of the queue.
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
                if ((distance[node] + edgeWeight) < distance[neighbor])
                {
                    // update the distance.
                    distance[neighbor] = (dist + edgeWeight);

                    // push this pair into the queue.
                    pq.push({distance[neighbor], neighbor});

                    // Update the parent of this neighbor.
                    parent[neighbor] = node;
                }
            }
        }

        // Our destination node is 'N' and if distance[N] == INT_MAX, it means that node is unreachable.
        // So we have to return an array containing -1.
        if (distance[N] == INT_MAX)
        {
            return {-1};
        }

        // Vector to store the final shorted path from source '1' to destination 'N'.
        vector<int> path;

        // Iterate the parent array, start the traversal from the destination.
        int node = N;
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);

        // Since the path stored is in a reverse order, we reverse the array
        // to get the final answer and then return the array.
        reverse(path.begin(), path.end());
        return path;
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
    // Vertices are labelled from 0 to N.
    int N = 5;
    int M = 6;

    // u = Edges[i][0].
    // v = Edges[i][1].
    // edge weight = Edges[i][2] (u ----- edge weight ------ v).
    vector<vector<int>> edges = {
        {1, 2, 2},
        {2, 5, 5},
        {2, 3, 4},
        {1, 4, 1},
        {4, 3, 3},
        {3, 5, 1},
    };

    // Solution.
    Solution S;
    vector<int> path = S.shortestPath(N, M, edges);
    S.printVec(path);
}