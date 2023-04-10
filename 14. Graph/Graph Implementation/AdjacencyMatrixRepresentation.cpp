#include <bits/stdc++.h>
using namespace std;

// Define a constant for the maximum number of vertices in the graph.
const int MAX_VERTICES = 100;

/* ---------------------------------- Graph Class ------------------------------- */

class Graph
{
private:
    /* Data Members or Properties of Graph Class. */
    int V;                                     // Number of vertices in the Graph.
    int E;                                     // Number of edges in the Graph.
    int adjMatrix[MAX_VERTICES][MAX_VERTICES]; // 2D array to store the adjacency matrix
public:
    /* Methods or Behavior of Graph Class. */

    // Parametersized Constructor of Graph Class.
    Graph(int vertices /* Total number of vertices in the Graph. */)
    {
        V = vertices; // setting up the total number of nodes(vertices) in the graph.
        V++; // increameting V, just for 1-based indexing.
        E = 0;        // Initially there is no edge between any pair of vertices.

        // Initialize all elements of the adjacency matrix to 0, because Initially there is no edges between any pair of vertices.
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                // adjMatrix[i][j] = 0, it means there is no edge between vertex "i" and vertex "j".
                // adjMatrix[i][j] = 1, it means there is an edge between vertex "i" and vertex "j".
                adjMatrix[i][j] = 0;
            }
        }
    }

    /* Method to add an edge in between two vertices. */
    // If the graph is directed then I am creating an edges from "u" to "v" and if the graph is undirected then we have to create one more edge that is from "v" to "u".
    // the boolean variable "isDirected" is used to identify, whether the user wants to create a directed graph or an undirected graph.
    // isDirected = true, it means user wants to create a directed graph.
    // isDirected = false, it means user wants to create a undirected graph.
    void addEdge(int u, int v, bool isDirected)
    {
        // If (isDirected == true), it means the user wants to create a directed graph.
        if (isDirected)
        {
            // And in directed graph, we have to create only one edges, that is from "u" to "v".
            adjMatrix[u][v] = 1; // edge created from "u" to "v".
        }

        // If (isDirected == false), it means the user wants to create a undirected graph.
        else
        {
            // And in undirected graph, we have to create two edges,
            //  First is from "u" to "v".
            //  and Second is from "v" to "u".
            adjMatrix[u][v] = 1; // edge created from "u" to "v".
            adjMatrix[v][u] = 1; // edge created from "v" to "u".
        }

        // Increment the number of edges in the graph
        E++;
    }

    /* Method to print the Adjacency Matrix. */
    void printGraph()
    {
        cout << "Adjacency matrix of the graph:" << endl;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

/* Main function to test the adjacency matrix representation of a graph. */
int main(void)
{
    int vertices, edges, u, v;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    cout << "Enter the number of edges in the graph: ";
    cin >> edges;

    bool isDirected;
    cout << "Tell us which type of graph you want to create.\nType: 0 for Undirected Graph and 1 for Directed Graph.\nEnter your choice: ";
    cin >> isDirected;

    // creating object of graph class.
    Graph g(vertices);
    for (int i = 0; i < edges; i++)
    {
        cout<<"Enter Nodes (u, v): ";
        cin >> u >> v;
        g.addEdge(u, v, isDirected);
    }

    g.printGraph();
}