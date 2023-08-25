#include <bits/stdc++.h>
using namespace std;

/* ---------------------------------- Solution Class ------------------------------------------ */
class Solution
{
private:
    /* Method to find the floor value of x. */
    // Time Complexity: O(log(n)), where 'n' is the size of the nums vector.
    // Space Complexity: O(1).
    int findFloor(vector<int> &nums, int x)
    {
        // Needed variables for Binary Search.
        int low = 0, high = nums.size() - 1;

        // variavle to store floor value of x.
        // Now, Floor of 'x' is the value that is "just" smaller than x. In case when there is no element present in the array that is smaller than the 'x'. In this case, we have to return -1. So, initialize floorValue with -1.
        int floorValue = -1;

        // Binary Search.
        while (low <= high)
        {
            // Mid.
            int mid = low + (high - low) / 2;

            // 'x' is Present in the array.
            if (nums[mid] == x)
            {
                // In case of 'x' is present in the array, then floor and ceil value of 'x' will be 'x'.
                floorValue = nums[mid];
                return floorValue;
            }

            // nums[mid] < x, it means nums[mid] is less then x and we are looking for a value that is smaller than 'x', because Floor of 'x' is the value that is "just" smaller than x. So, store the value in our ans because this can be a possible answer.
            else if (nums[mid] < x)
            {
                floorValue = nums[mid];

                // Move to Right Half.
                low = mid + 1;
            }
            else
            {
                // nums[mid] > x.
                high = mid - 1;
            }
        }

        return floorValue;
    }

    /* Method to find the ceil value of x. */
    // Time Complexity: O(log(n)), where 'n' is the size of the nums vector.
    // Space Complexity: O(1).
    int findCeil(vector<int> &nums, int x)
    {
        // Needed variables for Binary Search.
        int low = 0, high = nums.size() - 1;

        // variavle to store floor value of x.
        // Now, Ceil of 'x' is the value that is "just" greater than x. In case when there is no element present in the array that is greater than the 'x'. In this case, we have to return -1. So, initialize ceilValue with -1.
        int ceilValue = -1;

        // Binary Search.
        while (low <= high)
        {
            // Mid.
            int mid = low + (high - low) / 2;

            // 'x' is Present in the array.
            if (nums[mid] == x)
            {
                // In case of 'x' is present in the array, then floor and ceil value of 'x' will be 'x'.
                ceilValue = nums[mid];
                return ceilValue;
            }

            // nums[mid] < x.
            else if (nums[mid] < x)
            {
                // Move to Right Half.
                low = mid + 1;
            }

            // nums[mid] > x, it means nums[mid] is greater then 'x' and we are looking for an element that is just greater than 'x'. SO, this can be a possible ans, store it.
            else
            {
                ceilValue = nums[mid];

                // Move Left.
                high = mid - 1;
            }
        }

        return ceilValue;
    }

public:
    /* Question: You’re given an unsorted array arr of n integers and an integer x. Find the floor and ceiling of x in given array 'arr'. */
    pair<int, int> floorAndCeil(vector<int> &nums, int x)
    {
        // Step 1: Sort the given Array.
        sort(nums.begin(), nums.end());

        // Floor of 'x' is the value that is "just" smaller than x.
        // Ceil of 'x' is the value that is "just" greater than x.
        // Note: In case of 'x' is present in the array, then floor and ceil value of 'x' will be 'x'.
        int floorValue = findFloor(nums, x);
        int ceilValue = findCeil(nums, x);

        return {floorValue, ceilValue};
    }
};

int main(void)
{
    vector<int> nums{3, 4, 4, 7, 8, 10};
    int x = 5;

    // Solution.
    Solution obj;

    auto ans = obj.floorAndCeil(nums, x);
    cout << "Floor value of " << x << " is: " << ans.first << ".\nCeil value of " << x << " is: " << ans.second << ".";
    return 0;
}