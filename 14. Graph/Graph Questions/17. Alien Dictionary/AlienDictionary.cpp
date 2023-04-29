#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------- */
class Solution
{
private:
    /* Kahn's Algorithm (Modified BFS). */
    // Time Complexity: O(V) + O(E), where V is the number of vertices and E is the number of edges in the graph.
    // O(E) because the given graph is a directed graph.
    // Space Complexity: O(V).
    vector<int> topoSort(int V, unordered_map<int, list<int>> &adjList)
    {
        // Step 2: Compute the in-degree (i.e., number of incoming edges) of each vertex in the graph.
        vector<int> indegree(V, 0); // vector to store indegree of each vertex.

        // How to find the indegree?
        // By visiting the adjacency list, we can find out the indegrees for each node. For example, if node 3 is an adjacent node of node 2, we will just increase indegree[3] by 1 as the adjacency list suggests that node 3 has an incoming edge from node 2.
        for (int i = 0; i < V; i++)
        {
            for (auto neighbor : adjList[i])
            {
                indegree[neighbor]++;
            }
        }

        // Step 3: Push all the vertices having indegree '0' into the queue.
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // vector to store answer.
        vector<int> ans;

        // Traverse the queue.
        while (!q.empty())
        {
            // Take out the front node of the queue.
            int frontNode = q.front();

            // Pop the fron node of the queue.
            q.pop();

            // Store the front Node into our answer list.
            ans.push_back(frontNode);

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

        // After the above loop ends, our answer list will contains the vertices in topological order.
        return ans;
    }

public:
    /* Question: Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.

    Note: Many orders may be possible for a particular test case, thus you may return any valid order.

    Example 1:
    Input: N = 5, K = 4
    dict = {"baa","abcd","abca","cab","cad"}

    Output: b d a c

    Explanation:
    We will analyze every consecutive pair to find out the order of the characters.
    The pair “baa” and “abcd” suggests ‘b’ appears before ‘a’ in the alien dictionary.
    The pair “abcd” and “abca” suggests ‘d’ appears before ‘a’ in the alien dictionary.
    The pair “abca” and “cab” suggests ‘a’ appears before ‘c’ in the alien dictionary.
    The pair “cab” and “cad” suggests ‘b’ appears before ‘d’ in the alien dictionary.
    So, [‘b’, ‘d’, ‘a’, ‘c’] is a valid ordering.
    */

    /*
    Time Complexity: O(N*len)+O(K+E), where N is the number of words in the dictionary, ‘len’ is the length up to the index where the first inequality occurs, K = no. of nodes, and E = no. of edges.

    Space Complexity: O(K) + O(K)+O(K)+O(K) ~ O(4K), O(K) for the indegree array, and O(K) for the queue data structure used in BFS(where K = no.of nodes), O(K) for the answer array and O(K) for the adjacency list used in the algorithm.
    */
    string findOrder(string dict[], int N, int K)
    {
        // creating adjacency list for directed graph.
        unordered_map<int, list<int>> adjList;
        for (int i = 0; i < N - 1; i++)
        {
            // Comparing string at index "i" and "i+1".
            string first = dict[i];
            string second = dict[i + 1];
            for (int j = 0; j < min(first.length(), second.length()); j++)
            {
                // If first[j] != second[j], when we found an unequal character it means that
                // character present at first[j] appear before character present at second[j].
                // That why we can create a directed edge from character present at first[j] to character present at second[j].
                if (first[j] != second[j])
                {
                    adjList[first[j] - 'a'].push_back(second[j] - 'a');
                    break;
                }
            }
        }

        // Perform Topological Sorting to get the order.
        vector<int> topo = topoSort(K, adjList);

        string ans = "";
        for (auto i : topo)
        {
            ans.push_back(i + 'a');
        }

        return ans;
    }
};

int main(void)
{
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};
    int N = 5;
    int K = 4;

    // Solution.
    Solution S;
    cout << S.findOrder(dict, N, K);
}