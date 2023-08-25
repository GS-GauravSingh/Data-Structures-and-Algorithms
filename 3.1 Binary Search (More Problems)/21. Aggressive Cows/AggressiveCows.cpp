#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* The task of this function is to check whether it is possible to place all the cows with the minimum difference 'minDiff'. */
    // Time Complexity:  O(n), where 'n' is the size of the 'stalls' vector.
    // Space Complexity: O(1).
    bool isPossible(vector<int> &stalls, int cows, int minDiff)
    {
        // variable to count the total number of cows that has been palced.
        int cowCnt = 1;

        // The first cow is placed at index 0.
        int prevCow = 0;

        // Check whether it is possible to place the rest of the cows or not.
        for (int i = 1; i < stalls.size(); i++)
        {
            // If the difference between the previous cow placed and current cow is >= minDiff, it means we can place the cow at this index.
            if (stalls[i] - stalls[prevCow] >= minDiff)
            {
                cowCnt++;

                // Now, this cows is placed at 'ith' index and for the next cow the index of previous cow is this 'ith' index.
                // So, update the index of previous cow place for next cow.
                prevCow = i;
            }
            // if cowCnt >= cows, it means we have placed all the cows.
            if (cowCnt >= cows)
            {
                return true;
            }
        }

        return false;
    }

public:
    // Time Complexity:  O(n log(n)) for sorting + O(n log(n)) for finding maximum possible minimum difference, where 'n' is the size of the 'stalls' vector.
    // Space Complexity: O(1).
    int aggressiveCows(vector<int> &stalls, int k)
    {
        // size of vector.
        int n = stalls.size();

        // Sort the given vector.
        // Because minimum distance can only be found on consecutive indexes.
        sort(stalls.begin(), stalls.end());

        // The minimum distance between any 2 cows is 1 and minimum distances cannot go lower then 1.
        // If minimum distance is 0, it means 2 cows are placed at the same stall and this is not the case.
        int low = 1;

        // We need to choose the upper bound for applying binary search, so let's sau the maximum difference between any 2 cows is (stalls[n-1] - stalls[0]) i.e., (max element - min element).
        int high = stalls[n - 1] - stalls[0];

        // variable to store maximum possible minimum difference.
        int ans = 0;

        // Binary Search.
        while (low <= high)
        {
            // Mid (Minimum Difference).
            int mid = low + (high - low) / 2;

            // Now, let's check whether it is possible to place all the 'k' cows with the minimum difference of 'mid'.
            if (isPossible(stalls, k, mid))
            {
                // IF it is possible to place all the cows with 'mid' minimum difference, then this minimum difference 'mid' can be a possible answer. So, store it.
                // Now, If it is possible to place all the cows with 'mid' minimum difference. So, it is obvious that, it is also possible to place all the cows with the minimum difference lower then 'mid'. So, eleminate the left half and move to right half for finding the maximum possible minimum difference.
                ans = mid;

                low = mid + 1;
            }

            // But, If it is not possible to place all the cows with 'mid' minimum difference, then it is obvious that, it is also not possible to place all the cows with the minimum difference greater then 'mid'.
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
    vector<int> stalls{0, 3, 4, 7, 10, 9};
    int k = 4;

    // Solution.
    Solution obj;
    cout << "The maximum possible minimum distance is: " << obj.aggressiveCows(stalls, k) << ".";
    return 0;
}