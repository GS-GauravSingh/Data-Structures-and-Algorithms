#include <bits/stdc++.h>
using namespace std;

/* ------------------------------ Solution Class ---------------------------------- */
class Solution
{
private:
public:
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

    /* Approach 3 :- Stair Case Search. OPTIMIZED FOR GFG VARIATION BUT NOT FOR LEETCODE VARIATION. */
    // Time Complexity :- O(n + m), m is number of row's and n is number of columns.
    // Space Complexity :- O(1)

    bool searchMatrix_Optimized(vector<vector<int>> &matrix, int target)
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
};

int main(void)
{
    vector<vector<int>> matrix{
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60},
    };
    int target = 3;

    // Solution.
    Solution obj;
    cout << ((obj.searchMatrix_Optimized(matrix, target) == true) ? "Present." : "Not Present.");
    return 0;
}