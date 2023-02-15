#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
    /*
    Note :-
    This problem has 2 variation,
    1st is on leetcode and 2nd is on GFG.

    The first 3 approaches, works on both gfg and leetcode variation, and the first 2 approaches are brute force approach for both the variations.

    Approach 3 is the optimal approach for gfg variation but not for leetcode variation.

    Approach 4 is the optimal approach for leetcode variation.

    GFG variation, only states that matrix is row and column wise sorted, but leetcode has 1 extra property see approach 4 for details.
    */

    /* Approach 1 :- Using nested loops. */
    // Time Complexity :- O(m*n), m is number of row's and n is number of columns.
    // Space Complexity :- O(1)
    bool searchMatrix_Approach_1(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == target)
                {
                    return true;
                }
            }
        }

        return false;
    }

    /* Approach 2 :- Using Binary Search. Apply Binary Search on each row. */
    // Time Complexity :- O(m log(n)), m is number of row's and n is number of columns.
    // Space Complexity :- O(1)
    bool binarySearch(vector<int> &arr, int target)
    {
        int low = 0, high = arr.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (arr[mid] == target)
            {
                // target found.
                return true;
            }
            else if (arr[mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                // arr[mid] < target.
                low = mid + 1;
            }
        }

        return false;
    }

    bool searchMatrix_Approach_2(vector<vector<int>> &matrix, int target)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            if (binarySearch(matrix[i], target) == true)
            {
                return true;
            }
        }

        return false;
    }

    /* Approach 3 :- Stair Case Search. OPTIMAL APPROACH GFG VARIATION BUT NOT FOR LEETCODE VARIATION. */
    // Time Complexity :- O(n + m), m is number of row's and n is number of columns.
    // Space Complexity :- O(1)

    bool searchMatrix_Approach_3(vector<vector<int>> &matrix, int target)
    {
        // start traversing for top-right corner.
        int row = 0, col = matrix[0].size() - 1;

        while (row < matrix.size() && col >= 0)
        {
            if (matrix[row][col] == target)
            {
                // traget found.
                return true;
            }
            else if (matrix[row][col] > target)
            {
                // move left, because data is decreasing on left side.
                col--;
            }
            else
            {
                // matrix[row][col] < target
                // move down, because data is increasing on down side.
                row++;
            }
        }

        return false;
    }

    /* Approach 4 :- Stair Case Search. OPTIMIZED LEETCODE VARIATION. */
    /*
    Properties in Leetcode Variation,
    1. Each row is sorted in non-decreasing order.
    2. The first integer of each row is greater than the last integer of the previous row.

    So, because of the 2nd property the entire matrix is sorted in increasing order.
    Exanmple :-
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50},

        2nd property :- 7 < 10, 20 < 23

        The entire matrix will look like this, 1,3,5,7,10,11,16,20,23,30,34,50

        So, you can easily apply binary search on entire matrix.

    */
    // Time Complexity :- O(log(m*n)), m is number of row's and n is number of columns.
    // Space Complexity :- O(1)
    bool searchMatrix_Approach_4(vector<vector<int>> &matrix, int target)
    {
        // Binary Search.

        int row = matrix.size();
        int col = matrix[0].size();

        int low = 0, high = (row * col) - 1;

        while (low <= high)
        {
            int mid = (low + (high - low) / 2);

            // TO find the mid element, you need row and column index.
            // row index = mid / row.
            // column index = mid % col.

            int rowIdx = mid / col;
            int colIdx = mid % col;

            if (matrix[rowIdx][colIdx] == target)
            {
                // target found.
                return true;
            }
            else if (matrix[rowIdx][colIdx] > target)
            {
                high = mid - 1;
            }
            else
            {
                // matrix[rowIdx][colIdx] < target
                low = mid + 1;
            }
        }

        return false;
    }
};

int main()
{
    // TESTCASE FOR GFG VARIATION OF THIS PROBLEM.
    vector<vector<int>> matrix1 = {
        {10, 20, 30, 40},
        {11, 21, 36, 43},
        {50, 60, 74, 80},
    };

    // TESTCASE FOR LEETCODE VARIATION OF THIS PROBLEM.
    vector<vector<int>> matrix2 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50},
    };

    int target = 50;

    Solution S;
}