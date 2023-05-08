#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Method to create a adjacency list for directed weighted graph. */
    void createAdjacencyList(vector<vector<int>> &edges, unordered_map<int, list<pair<int, int>>> &adjList)
    {
        // Traverse the edges vector.
        for (int i = 0; i < edges.size(); i++)
        {
            // Take out the both the vertices and edge weight.
            int u = edges[i][0];
            int v = edges[i][1];
            int edgeWeight = edges[i][2]; // u ------- edge weight ------> v.

            // Create adjacency list according to weighted directed graph.
            adjList[u].push_back({v, edgeWeight});
        }
    }

public:
    /* Question: There are n cities and m edges connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from the city fromi to city toi with cost pricei.

    You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.*/

    /*
    To solve this problem, we can use Dijkstra's algorithm with a small modification to keep track of the number of stops made.
    The simple Dijkstra's algorithm finds the shortest path from a source node to all other nodes in the graph, but it does not take into account the number of stops made. In this problem, we need to find the cheapest price from the source node to the destination node with at most k stops. Therefore, we need to modify Dijkstra's algorithm to keep track of the number of stops made and limit it to k stops.
    */

    /*
    Time Complexity: O( N ) { Additional log(N) of time eliminated here because we’re using a simple queue rather than a priority queue which is usually used in Dijkstra’s Algorithm }.
    Where N = Number of flights / Number of edges.

    Space Complexity:  O( |E| + |V| ) { for the adjacency list, priority queue, and the dist array }.
    Where E = Number of edges (flights.size()) and V = Number of Airports.
    */

    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        // create an adjacency list for directed weighted graph.
        unordered_map<int, list<pair<int, int>>> adjList;
        createAdjacencyList(flights, adjList);

        // No need to take a priority queue because the stop count is increasing linearly and the queue will ake sure that we will get the node with minimum stops.

        // Create a queue which stores the node and their distances from the
        // source in the form of {stops, {node, dist}} with ‘stops’ indicating
        // the no. of nodes between src and current node.
        queue<pair<int, pair<int, int>>> q;

        // Push the source node with the distance 0 and stops 0 into the queue.
        // Queue is of type {stops, {node, distance}}.
        q.push({0, {src, 0}});

        // Distance Array.
        // Declaring distance of size 'V', because we have to store the shortest distance from source node to all the other nodes in the graph.
        // Initializing distance array with 'INT_MAX', initially "INT_MAX" represent that the node is unreachable and as we traverse the graph, "INT_MAX" is used to update the distance array with the shortest distance to reach a particular node from source.
        vector<int> distance(n, INT_MAX);
        distance[src] = 0; // Update the distance of source node "src" with 0, because we are starting from 'src' and in order to reach 'src' itself we need to travel 0 distance.

        // Traversing the queue.
        while (!q.empty())
        {
            // Take out the front element of the queue.
            auto frontNode = q.front();

            // Pop the front element of the queue.
            q.pop();

            // Take out the node, distance and stops from the frontNode.
            int stops = frontNode.first;
            int node = frontNode.second.first;
            int dist = frontNode.second.second;

            // We stop the process as soon as the limit for the stops reaches.
            if (stops > K)
            {
                continue;
            }

            // Neighbors.
            // adjList will return a pair of type {node, edgeWeight}.
            for (auto pair : adjList[node])
            {
                int neighbor = pair.first;
                int edgeWeight = pair.second;

                // We only update the queue if the new calculated dist is
                // less than the prev and the stops are also within limits.
                if (dist + edgeWeight < distance[neighbor] && stops <= K)
                {
                    distance[neighbor] = dist + edgeWeight;
                    q.push({stops + 1, {neighbor, distance[neighbor]}});
                }
            }
        }

        // If the destination node is unreachable return ‘-1’
        if (distance[dst] == INT_MAX)
        {
            return -1;
        }

        // else return the calculated dist from src to dst.
        return distance[dst];
    }
};

int main(void)
{
    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200},
    };
    int m = flights.size();
    int source = 0;
    int destination = 3;
    int K = 1;

    // Solution.
    Solution S;
    cout << S.CheapestFLight(n, flights, source, destination, K);
}