#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Approach: Since the input is sorted we can use two-pointer approach to find the pairs whose summation is equal to target. */
    // Time Complexity: O(n/2) ~ O(n), where 'n' is the size of the numbers vector.
    // Space Complexity: O(1), excluding the space used by 'ans' vector to store pairs.
    vector<int> twoSum(vector<int> &numbers, int target)
    {

        // vector to store pairs.
        vector<int> ans;

        // Pointers.
        int start = 0;
        int end = numbers.size() - 1;
        while (start < end)
        {
            // sum of pair.
            int sum = numbers[start] + numbers[end];

            if (sum == target)
            {
                ans.push_back(start + 1);
                ans.push_back(end + 1);
                start++;
                end--;
            }
            else if (sum > target)
            {
                end--;
            }
            else
            {
                start++;
            }
        }

        return ans;
    }
};

int main(void)
{
    vector<int> nums{2, 3, 4};
    int target = 6;

    // SOlution.
    Solution obj;
    vector<int> ans = obj.twoSum(nums, target);

    cout << "Pair Index: [" << ans[0] << ", " << ans[1] << "]";
    return 0;
}