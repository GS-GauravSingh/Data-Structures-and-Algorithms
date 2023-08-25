#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Brute Force Approach: Using Sorting. */
    // Time Complexity: O(n*log(n)), where 'n' is the size of the nums vector.
    // Space Complexity: O(1).
    void sortColors_BruteForce(vector<int> &nums)
    {
        // Sort the given vector.
        sort(nums.begin(), nums.end());
    }

    /* Better Approach: Since in this case there are only 3 distinct values in the array so it’s easy to maintain the count of all, Like the count of 0, 1, and 2. This can be followed by overwriting the array based on the frequency(count) of the values. */

    // Time Complexity: O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(1).
    void sortColors_Better(vector<int> &nums)
    {
        // Variable to count the frequency of 0, 1 and 2.
        int zeroCount = 0;
        int oneCount = 0;
        int twoCount = 0;

        // Store the frequency of 0, 1 and 2.
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zeroCount++;
            }
            else if (nums[i] == 1)
            {
                oneCount++;
            }
            else
            {
                twoCount++;
            }
        }

        // In 2nd traversal of array, we will now over write the first ‘a’ indices / positions in array with ’0’, the next ‘b’ with ‘1’ and the remaining ‘c’ with ‘2’.
        for (int i = 0; i < nums.size(); i++)
        {
            if (zeroCount)
            {
                nums[i] = 0;
                zeroCount--;
            }
            else if (oneCount)
            {
                nums[i] = 1;
                oneCount--;
            }
            else
            {
                nums[i] = 2;
                twoCount--;
            }
        }
    }

    /* Optimal Approach: Using Dutch National Flag Algorithm. */
    // Time Complexity: O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(1).
    void sortColors_Optimal(vector<int> &nums)
    {
        // Size of nums vector.
        int n = nums.size();

        // Needed variable for Dutch National Flag Algorithm.
        int low = 0;
        int mid = 0;
        int high = n - 1;

        // Dutch National Flag Algorithm.
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }

public:
    void sortColors(vector<int> &nums)
    {

        // // Brute Force.
        // sortColors_BruteForce(nums);

        // // Better Approach.
        // sortColors_Better(nums);

        // Optimal Approach.
        sortColors_Optimal(nums);
    }
};

int main(void)
{
    vector<int> nums{2, 0, 2, 1, 1, 0};

    // Solution.
    Solution obj;
    obj.sortColors(nums);

    for (int i : nums)
        cout << i << " ";
    return 0;
}