#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Brute Force Approach: Generate all possible pairs using nested loops or recursion and calculate the sum of each  pair, then check whether the sum of a particular pair matches to target or not. If the sum matches, then store the indices of pair elements.

    Time Complexity: O(n^2), where 'n' is the size of the nums vector.
    Space Complexity: O(2), O(2) is the size of answer vector to store the pair, O(2) can be treated as constant i.e., O(1).
    */
    vector<int> twoSum_Brute(vector<int> &nums, int target)
    {

        // Size of nums vector.
        int n = nums.size();

        // vector to store answer.
        vector<int> ans;

        // Generating All Pairs using nested loops.
        for (int i = 0; i < n; i++)
        {
            // 'j' will always be one element ahead of 'i', because we cannot use the same element twice.
            for (int j = i + 1; j < n; j++)
            {
                // sum of this pair.
                int sum = nums[i] + nums[j];

                // If the sum matches to target then store the indices of pair elements.
                if (sum == target)
                {
                    ans.push_back(i);
                    ans.push_back(j);

                    // In Constraint, it is clearly mentioned that, Only one valid answer exists.
                    // So, return answer.
                    return ans;
                }
            }
        }

        return {};
    }

    /* Better Approach: Better approach is to used sorting, Sort the given array in increasing order and then use 2 pointer apporach to find the pair whose summation is equal to given target.

    But here, we cannot use sorting, because sorting will reorder the element and we have to return the indices. Sorting the array will change the order of the elements, which will make it difficult to retrieve the original indices of the pair that sums up to the target value.

    Time Complexity: O(nlog(n)) + O(n/2), where 'n' is the size of the vector, O(nlog(n)) is TC of sorting and O(n/2) is TC of 2 pointer approach.
    Space Complexity: O(2), O(2) is the size of answer vector to store the pair, O(2) can be treated as constant i.e., O(1).
    */
    vector<int> twoSum_Better(vector<int> &nums, int target)
    {

        // Size of nums vector.
        int n = nums.size();

        // vector to store answer.
        vector<int> ans;

        // sort the given vector.
        sort(nums.begin(), nums.end());

        // Using 2 pointer approach to find the pair whose summation is equal to given target.
        int i = 0, j = n - 1;

        while (i < j)
        {
            // sum of this pair.
            int sum = nums[i] + nums[j];

            // If the sum matches to target then store the indices of pair elements.
            if (sum == target)
            {
                ans.push_back(i);
                ans.push_back(j);

                // In Constraint, it is clearly mentioned that, Only one valid answer exists.
                // So, return answer.
                return ans;
            }
            else if (sum < target)
            {
                // If sum < target, in this case you have to increase the sum.
                // Increment 'i' pointer.
                i++;
            }
            else
            {
                // If sum > target, in this case you have to decrease the sum.
                // Decrement 'j' pointer.
                j--;
            }
        }

        return {};
    }

    /* Optimal Approach: Optimal Approach is to use Hashing, Let's see how this works.

    Now, if we subtract nums[i] from our target, we get something lets call it as 'x'. Equation: target - nums[i] = x. So, from this equation we can say the if we found the 'x' in the rest of the array, then we can say that there exist a pair whose summation is equal to target.

    >> target - nums[i] = x.
    >> target = x + nums[i].

    Let's Dry run this approach on one example to understand.
    Ex: nums = {2, 7, 11, 15}, target = 9.

    Initial configuration: Initialize an empty hash map, I call it as map.

    Now, Start iterating through the array from left to right:

    >> i = 0,
    target - nums[i] = x => 9 - 2 = 7. Our map is empty, currently we don't have any pair whose sum is equal to target.
    Now, insert current element into our map with its index.

    map = {Element, Index}.
    map = {2, 0}

    >> i = 1,
    target - nums[i] = x => 9 - 7 = 2. Our map is not empty and 2 is present in our map. So, here we found one pair whose sum is equal to target.

    // target - nums[i] = x.
    // target = x + nums[i].

    // 9 - 7 = 2,
    // 9 = 7 + 2.

    Now, insert current element into our map with its index.

    map = {Element, Index}.
    map = {2, 0}, {7, 1}

    and so on ... till last index.

    Time Complexity: O(n), where 'n' is the size of the nums vector.
    Space Complexity: O(n) + O(2), O(n) space used by unordered_map because in the worst case, the unordered_map can store all elements of the input vector and O(2) is the size of answer vector to store the pair, O(2) can be treated as constant i.e., O(1).
    */
    vector<int> twoSum_Optimal(vector<int> &nums, int target)
    {

        // Size of nums vector.
        int n = nums.size();

        // vector to store answer.
        vector<int> ans;

        // unordered_map
        unordered_map<int, int> map;

        // Iterate through the elements.
        for (int i = 0; i < n; i++)
        {
            // Calculate the value of 'x'.
            int x = target - nums[i];

            // Iterator to check whether 'x' is present in map or not.
            auto it = map.find(x);

            // if 'x' is present in map.
            if (it != map.end())
            {
                // return the indices of pair elements.
                return {i, it->second};
            }

            // Insert current element into our map with its index.
            map[nums[i]] = i;
        }

        return {};
    }
};

int main(void)
{
    vector<int> nums{2, 7, 11, 15};
    int target = 9;

    // SOlution.
    Solution obj;
    vector<int> ans = obj.twoSum_Optimal(nums, target);

    cout << "Pair Index: [" << ans[0] << ", " << ans[1] << "]";
    return 0;
}