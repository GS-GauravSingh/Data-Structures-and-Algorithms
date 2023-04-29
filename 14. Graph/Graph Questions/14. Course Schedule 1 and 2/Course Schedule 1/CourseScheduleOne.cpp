#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Data Members or Properties of Solution Class. */
public:
    /* Question: There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
    Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

    Example 1:
    Input:
    N = 4, P = 3
    prerequisites = {{1,0},{2,1},{3,2}}
    Output:
    Yes
    Explanation:
    To do task 1 you should have completed
    task 0, and to do task 2 you should
    have finished task 1, and to do task 3 you
    should have finished task 2. So it is possible.
    */

    /* Intution: The questions state that the given pairs signify the dependencies of tasks.

    For example, the pair {0, 1} signifies that to perform task 0, first we need to complete task 1. So basically task 0 is dependent on task 1.

    Now, if we consider this pair of tasks as nodes, like u = 0 and v = 1. Now the pair would look like this {u, v}. Now, I can say the to perform task 'u', first I need to complete task 'v'.

    And I can say that there is a directed edge from node 'v' to 'u' (v -> u), because to perform task 'u', first I need to complete task 'v'. Similarly first we need to "perform or print or visit" "task or node" 'v', only then we can move toward the node 'u'.

    Now, this entire problem becomes a graph problem.

    Now, let’s analyze the examples from the graph point of view:

    For example 1, the number of tasks(considered as nodes) is 4, and pairs(considered as edges) are 3. If we draw the graph accordingly, the following illustration is produced:

    Graph (DAG):        3 -> 2 -> 1 -> 0

    And For example 2, the number of tasks(considered as nodes) is 4, and pairs(considered as edges) are 4. If we draw the graph accordingly, the following illustration is produced:

    Graph:        1 -> 2 -> 4 -> 3   (Directed Cyclic Graph).
                  ^         |
                  |         |
                  -----------
    Analyzing the graphs, we can conclude that performing all the tasks from the first set is possible because the first graph does not contain any cycle but as the second graph contains a cycle, performing all the tasks from the second set is impossible(there exists a cyclic dependency between the tasks).

    So, if a graph is directd acyclic graph then we can say that it is possible to finish all the tasks otherwise if the graph is not a DAG then it is not possible to finish all the tasks.

    Using Kanh's Algorithm we can easily find out whether a graph is DAG or not.
    */

    /* Kahn's Algorithm (Modified BFS). */
    // Time Complexity: O(V) + O(E), where V is the number of vertices and E is the number of edges in the graph.
    // O(E) because the given graph is a directed graph.
    // Space Complexity: O(V).
    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {
        // creating adjacency list.
        unordered_map<int, list<int>> adjList;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i].first;
            int v = prerequisites[i].second;

            adjList[v].push_back(u);
        }
        // Perform Topological Sorting using Kahn's Algorithm.

        // Step 1: Compute the indegree of each vertex.
        int indegree[N] = {0}; // array to store indegree of each vertex.
        for (int i = 0; i < N; i++)
        {
            for (auto neighbor : adjList[i])
            {
                indegree[neighbor]++;
            }
        }

        // Step 2: Push all the vertices having indegree '0' into the queue.
        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // vector to store vertices in topological sorting.
        vector<int> topoSort;

        // Traversing the queue.
        while (!q.empty())
        {
            // Take out the front node of the queue.
            int frontNode = q.front();

            // Pop the fron node of the queue.
            q.pop();

            // Store the front Node into our answer list.
            topoSort.push_back(frontNode);

            // Traverse the neighbors of frontNode and decrement the indegree of each neighbor by 1.
            for (auto neighbor : adjList[frontNode])
            {
                indegree[neighbor]--;

                // After decrementing the indegree of neighbor, if the indegree becomes 0, then push that neighbor into the queue.
                if (indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }

        // After the end of the above while loop, if the topoSort vector contains all the vertices it means the graph is not cyclic and if the topoSort vector does not contain all the vertices it means the graph is cyclic.
        if (topoSort.size() == N)
        {
            // Graph is not cyclic, it means it is possible to finish all the tasks.
            return true;
        }

        // Else, return false, it means graph is cyclic and it is not possible to finish all the tasks.
        return false;
    }
};

int main(void)
{
    int N = 4;
    vector<pair<int, int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2},
    };
    int P = prerequisites.size();

    // Solution.
    Solution S;
    cout << "Possible or not : " << ((S.isPossible(N, prerequisites) == true) ? "Yes." : "No.");
}