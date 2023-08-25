#include <bits/stdc++.h>
using namespace std;

class Solution
{
    /* The divisionResult function calculates the sum of divisions of all elements in the nums array by a given divisor. It uses the ceil function to ensure that division results are rounded up to the nearest integer. */
    int divisionResult(vector<int> &nums, int divisor)
    {
        int sum = 0;
        for (int val : nums)
        {
            sum += ceil((float)val / (float)divisor);
        }
        return sum;
    }

public:
    // Time Complexity: O(n) for finding maximum element of array + O(n*log(n)) for finding answer.
    // Space Complexity: O(1).
    int smallestDivisor(vector<int> &nums, int threshold)
    {

        // The smallest divisor of every number is 1.
        int low = 1;

        // The largest divisor of any number is that number itself and in this case we have an arrays of numbers. So, let's pick the maximum element of array as largest divisor.
        int high = INT_MIN;
        for (int i : nums)
        {
            high = max(high, i);
        }

        // variable to store the smallest divisor.
        int ans = 0;

        // Search Space [1, max_element(nums)].
        while (low <= high)
        {
            // Mid (Divisor).
            int mid = low + (high - low) / 2;

            // Store the result of division.
            int result = divisionResult(nums, mid);

            
            if (result <= threshold)
            {
                ans = mid;

                // I am looking for a smallest divisor, so move to left half.
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main(void)
{
    vector<int> nums{44, 22, 33, 11, 1};
    int threshold = 5;

    // Solution.
    Solution obj;
    cout << obj.smallestDivisor(nums, threshold);
    return 0;
}