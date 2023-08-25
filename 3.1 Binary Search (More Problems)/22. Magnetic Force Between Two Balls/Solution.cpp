#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* The task of this function is to check whether it is possible to place all the balls with the minimum difference 'minDiff'. */
    // Time Complexity:  O(n), where 'n' is the size of the 'positions' vector.
    // Space Complexity: O(1).
    bool isPossible(vector<int> &positions, int balls, int minDiff)
    {
        // variable to count the total number of balls that has been palced.
        int ballCnt = 1;

        // The first ball is placed at index 0.
        int prevBall = 0;

        // Check whether it is possible to place the rest of the balls or not.
        for (int i = 1; i < positions.size(); i++)
        {
            // If the difference between the previous ball placed and current ball is >= minDiff, it means we can place the ball at this index.
            if (positions[i] - positions[prevBall] >= minDiff)
            {
                ballCnt++;

                // Now, this ball is placed at 'ith' index and for the next ball the index of previous ball is this 'ith' index.
                // So, update the index of previous ball place for next ball.
                prevBall = i;
            }
            // if ballCnt >= balls, it means we have placed all the balls.
            if (ballCnt >= balls)
            {
                return true;
            }
        }

        return false;
    }

public:
    // Time Complexity:  O(n log(n)) for sorting + O(n log(n)) for finding maximum possible minimum difference, where 'n' is the size of the 'positions' vector.
    // Space Complexity: O(1).
    int maxDistance(vector<int> &positions, int m)
    {
        // size of vector.
        int n = positions.size();

        // Sort the given vector.
        // Because minimum distance can only be found on consecutive indexes.
        sort(positions.begin(), positions.end());

        // The minimum distance between any 2 balls is 1 and minimum distances cannot go lower than 1.
        // If minimum distance is 0, it means 2 balls are placed at the same position and this is not the case.
        int low = 1;

        // We need to choose the upper bound for applying binary search, so let's say the maximum difference between any 2 balls is (positions[n-1] - positions[0]) i.e., (max element - min element).
        int high = positions[n - 1] - positions[0];

        // variable to store maximum possible minimum difference.
        int ans = 0;

        // Binary Search.
        while (low <= high)
        {
            // Mid (Minimum Difference).
            int mid = low + (high - low) / 2;

            // Now, let's check whether it is possible to place all the 'm' balls with the minimum difference of 'mid'.
            if (isPossible(positions, m, mid))
            {
                // If it is possible to place all the balls with 'mid' minimum difference, then this minimum difference 'mid' can be a possible answer. So, store it.
                // Now, If it is possible to place all the balls with 'mid' minimum difference. So, it is obvious that, it is also possible to place all the balls with the minimum difference lower then 'mid'. So, eleminate the left half and move to right half for finding the maximum possible minimum difference.
                ans = mid;

                low = mid + 1;
            }

            // But, If it is not possible to place all the balls with 'mid' minimum difference, then it is obvious that, it is also not possible to place all the balls with the minimum difference greater then 'mid'.
            // So, eleminate the right half and move to left half for finding the maximum possible minimum difference.
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main(void)
{
    vector<int> positions{1, 2, 3, 4, 7};
    int m = 3;

    // Solution.
    Solution obj;
    cout << "The maximum possible minimum magnetic force is: " << obj.maxDistance(positions, m) << ".";
    return 0;
}