#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    /* Burte Force Approach: Trying All possibilities.  */
    // Time Complexity :- O(n^2), where 'n' is the size of the height vector.
    // Space Complexity :- O(1).
    int containerWithMostWater_Brute(vector<int> &heights)
    {

        // size of array.
        int n = heights.size();

        // variable to store answer.
        int maxWaterTrapped = 0;

        // iterate through the array and find answer.
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {

                // calculation.
                int height = min(heights[i], heights[j]);
                int width = j - i;
                int trappedWater = height * width;

                // cout << "Area (" << heights[i] << "," << heights[j] << ") = " << trappedWater << endl;

                // store maximum trapped water.
                maxWaterTrapped = max(maxWaterTrapped, trappedWater);
            }
            // cout << endl;
        }

        return maxWaterTrapped;
    }

    /* Approach 2 :- Using 2 pointer's. */
    // Time Complexity :- O(n), where 'n' is the size of the height vector.
    // Space Complexity :- O(1).
    int containerWithMostWater_Optimal(vector<int> &heights)
    {

        // size of array.
        int n = heights.size();

        // variable to store answer.
        int maxWaterTrapped = 0;

        // 2 pointer
        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            // left tower height.
            int leftHeight = heights[left];

            // right tower height.
            int rightHeight = heights[right];

            // height
            int height = min(leftHeight, rightHeight);

            // width
            int width = right - left;

            // area
            int trappedWater = height * width;

            // maximum water trapped.
            maxWaterTrapped = max(maxWaterTrapped, trappedWater);

            // move pointers.
            if (leftHeight < rightHeight)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxWaterTrapped;
    }

public:
    int maxArea(vector<int> &height)
    {
        // return containerWithMostWater_Brute(height);
        return containerWithMostWater_Optimal(height);
    }
};

int main(void)
{
    vector<int> heights{1, 8, 6, 2, 5, 4, 8, 3, 7};

    // Solution.
    Solution obj;
    cout << "Maximum amount of water a container can store is: " << obj.maxArea(heights) << ".";
    return 0;
}