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

    int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
    {
        // create an adjacency list for directed weighted graph.
        unordered_map<int, list<pair<int, int>>> adjList;
        createAdjacencyList(flights, adjList);
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