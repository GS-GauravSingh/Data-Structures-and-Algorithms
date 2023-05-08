#include <bits/stdc++.h>
using namespace std;

/* ---------------------------- Disjoint Set Class. ------------------------------------------- */
class DisjointSet
{
private:
    // Parent array will store the ultimate parent of each node.
    // Rank array will store the rank of each node and Rank array is used in Union by Rank.
    // Size array will store the size (size of a node means number of nodes connected to it) of each node and Rank array is used in Union by Size.
    vector<int> parent, rank, size;

public:
    // Constructor of Disjoint set class.
    DisjointSet(int n /* In Disjoint Set, initially we have 'n' individual nodes. */)
    {
        // Declaring parent, rank, and size array with size 'n+1', because this size will work for both 0 and 1 based indexing graphs.
        parent.resize(n + 1);

        // Initializing parent array.
        for (int i = 0; i <= n; i++)
        {
            // Initially each node is a ultimate parent of itself.
            parent[i] = i;
        }

        // Initially size of all nodes is 1.
        size.resize(n + 1, 1);

        // Initially rank of all nodes is 0.
        rank.resize(n + 1, 0);
    }

    /* Method to find the Ultimate Parent of a particular node. */
    // This is the code with path compression.
    int findUParent(int node)
    {
        // Base Case
        if (node == parent[node] /* Because the ultimate parent of a ultimate parent is a ultimate parent itself. */)
        {
            // return ultimate parent.
            return node;
        }

        // else, move towards the base case and find the ultimate parent of the node in the path.
        int ultimateParent = findUParent(parent[node]);

        // Backtracking step (while comming back from the base case).
        // Connect all the nodes directly with the ultimate parents.
        parent[node] = ultimateParent;
    }

    /* Performing Union using Union by rank Method. */
    /* The time complexity of both Union by Size and Union by Rank is O(4 alpha), which is a constant time complexity and is considered to be O(1). */
    void unionByRank(int u, int v)
    {
        // Step 1: find the ultimate parent of node 'u' and node 'v'.
        int ulp_u = findUParent(u); // ultimate parent of U.
        int ulp_v = findUParent(v); // ultimate parent of V.

        // Additional Step.
        // If both the nodes already belongs to the same component, you can simply return from here.
        if (ulp_u == ulp_v)
        {
            return;
        }

        // Step 2: Find ranks of ultimate parents.
        int rankOf_ulp_u = rank[ulp_u]; // Rank of ultimate parent of U.
        int rankOf_ulp_v = rank[ulp_v]; // Rank of ultimate parent of V.

        /* Step 3: Check the ranks of the ultimate parents,
            3.1. Now, if the ranks of both the ultimate parents is equal, in this case you can connect any ultimate parent to other ultimate parent and we will increase the rank by one for the ultimate parent node to whom we have connected the other one.
            3.2. But, if the ranks of both the ultimate parents are not equal, in this case, we always connect the ultimate parent with a smaller rank to the other ultimate parent with a larger rank. (Smaller rank waale ultimate parent ko larger rank waale ultimate parent se connect karo).
        */
        if (rankOf_ulp_u < rankOf_ulp_v)
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rankOf_ulp_v < rankOf_ulp_u)
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            // rankOf_ulp_u == rankOf_ulp_v
            // I am connecting 'ulp_u' with 'ulp_v'.
            parent[ulp_u] = ulp_v;

            // And when you connect 2 nodes of the same rank then the height/rank will increase by one and when 2 nodes have different ranks in this case we will not do anything with the ranks.
            rank[ulp_v]++;
        }
    }

    /* Performing Union using Union by size Method. */
    /* The time complexity of both Union by Size and Union by Rank is O(4 alpha), which is a constant time complexity and is considered to be O(1). */
    void unionBySize(int u, int v)
    {
        // Step 1: find the ultimate parent of node 'u' and node 'v'.
        int ulp_u = findUParent(u); // ultimate parent of U.
        int ulp_v = findUParent(v); // ultimate parent of V.

        // Additional Step.
        // If both the nodes already belongs to the same component, you can simply return from here.
        if (ulp_u == ulp_v)
        {
            return;
        }

        // Step 2: Find size of ultimate parents.
        int sizeOf_ulp_u = size[ulp_u]; // Size of ultimate parent of U.
        int sizeOf_ulp_v = size[ulp_v]; // Size of ultimate parent of V.

        /* Step 3: Check the sizes of the ultimate parents,
            3.1. Now, if the ranks of both the ultimate parents is equal, in this case you can connect any ultimate parent to other ultimate parent.

            3.2 But, if the ranks of both the ultimate parents are not equal, in this case, we always connect the ultimate parent with a smaller rank to the other ultimate parent with a larger rank. (Smaller rank waale ultimate parent ko larger rank waale ultimate parent se connect karo).

            Note: Now, in case of Union by rank, we only increment the rank, when we connect 2 components of same sizes, but in case of Union by Size While connecting in both cases we will increase the size of the parent node to whom we have connected by the size of the other parent node which is actually connected.
        */

        if (sizeOf_ulp_u < sizeOf_ulp_v)
        {
            parent[ulp_u] = ulp_v;

            // Update the size of "ulp_v" with the size of "ulp_u".
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;

            // Update the size of "ulp_u" with the size of "ulp_v".
            size[ulp_u] += size[ulp_v];
        }
    }
};

/* ------------------------------------- Solution Class ----------------------------------------- */
class Solution
{
public:
    /*
    Time Complexity: O(Q*4α) ~ O(Q) where Q = no. of queries. The term 4α is so small that it can be considered constant.

    Space Complexity: O(Q) + O(N*M) + O(N*M), where Q = no. of queries, N = total no. of rows, M = total no. of columns. The last two terms are for the parent and the size array used inside the Disjoint set data structure. The first term is to store the answer.
    */
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        // Object of Disjoint set class.
        // represent each cell with a number, so in total we have n*m cells or nodes.
        DisjointSet ds(n * m);

        // visited array.
        // This is used to check if a cell is previously visited or not.
        vector<vector<int>> visited(n, vector<int>(m, 0)); // initially all cells are unvisited, so mark ithese cell with 0.

        // variable to store the group of islands after each query.
        int islandsCnt = 0;

        // vector to store answer.
        vector<int> ans;

        // Traverse the queries.
        for (auto query : operators)
        {
            // 'x' coordinate of cell or row index of cell.
            int rowIdx = query[0];

            // 'y' coordinate of cell or column index of cell.
            int colIdx = query[1];

            // Now, if this cell is already visited in the past, then no need to visit this cell again.
            // and the count of Islands remains the same.
            if (visited[rowIdx][colIdx] == true)
            {
                // store the count of islands into our answer vector.
                ans.push_back(islandsCnt);

                // and move towards the next query.
                continue;
            }

            //  Now, if this cell is not visited in the past, then mark this cell as visited,
            // and count this cell as a individual group of island.
            visited[rowIdx][colIdx] = true;
            islandsCnt++;

            // Now, chekc the surrounding of this particular cell and
            // if this cell is surrounded (in four directions i.e., top, down, left and right) by an Island,
            // then connect this cell with the surrounded island and decrement the count of Islands.

            // Now, we have to check the four neighbors of this cell.
            /*
                // Shortcut for traversing all 4 neighbors (top, bottom, left and right) using a single loop.

                coordinates for top neighbour is :   row - 1, col
                coordinates for right neighbour is : row    , col + 1
                coordinates for bottom neighbour is: row + 1, col
                coordinates for left neighbour is:   row    , col - 1

                Basically all the row coordinates are = {-1, 0, +1, 0};
                Basically all the col coordinates are = {0, +1, 0, -1};

                Using the above 2 array we can easily find all the neighbours,

                Row Coordinate   Column Coordinate  =>   Neighbour (row + row coordinate[i], col + col coordinate[i])
                ------------------------------------------------------------------------------------------------------
                    -1                  0                   row + (-1), col + 0 ==>  (row - 1, col), coordinates of top neighbor.
                    0                   +1                  row + 0, col + 1 ==>  (row, col + 1), coordinates of right neighbor.
                    +1                  0                   row + 1, col + 0 ==>  (row + 1, col), coordinates of bottom neighbor.
                    0                   -1                  row + 0, col + (-1) ==>  (row, col - 1), coordinates of left neighbor.
            */

            int rowCoordinate[] = {-1, 0, +1, 0};
            int colCoordinate[] = {0, +1, 0, -1};

            for (int i = 0; i < 4 /* size of both the array is 4. */; i++)
            {
                // Row and column indexes of neighbors.
                int neighborRowIdx = rowIdx + rowCoordinate[i];
                int neighborColIdx = colIdx + colCoordinate[i];

                if ((neighborRowIdx >= 0 && neighborRowIdx < n && neighborColIdx >= 0 && neighborColIdx < m /* checking for out of bound. */) &&
                    (visited[neighborRowIdx][neighborColIdx] == 1 /* Neighbor cell has to be an island and if the neighbor is not an island then we cannot connect to this neighbor. */))
                {
                    // One more condition.
                    // If this current cell and the neighbor is already connected by some other cell, in this case this cell and the neighbor belongs to the same component or island, so in this case, no need to connect them again.

                    // calculating the node number of this cell.
                    // formula = i * m + j, i = row index, m = total number of columns and j = column index.
                    int nodeNumber = rowIdx * m + colIdx;

                    // calculating the node number of neighbor cell.
                    // formula = i * m + j, i = row index, m = total number of columns and j = column index.
                    int neighborNumber = neighborRowIdx * m + neighborColIdx;

                    if (ds.findUParent(nodeNumber) != ds.findUParent(neighborNumber))
                    {
                        islandsCnt--;
                        ds.unionBySize(nodeNumber, neighborNumber);
                    }
                }
            }

            ans.push_back(islandsCnt);
        }

        return ans;
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

int main()
{
    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1}, {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}};

    Solution S;
    vector<int> ans = S.numOfIslands(n, m, operators);
    S.printVec(ans);
    return 0;
}