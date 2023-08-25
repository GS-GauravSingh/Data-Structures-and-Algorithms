#include <bits/stdc++.h>
using namespace std;

class Solution
{
    /* Brute Force Apporach: Using Sorting. */
    // Time Complexity: O(n*log(n)), where 'n' is the size of the nums vector.
    // Space Complexity: O(1).
    int longestConsecutive_BruteForce(vector<int> &nums)
    {
        // size of nums vector.
        int n = nums.size();

        // Base Case.
        // If the nums vector is empty, then the length of longest consecutive sequence is 0 because there is no element in nums vector or if the nums vector contains only single element, then the length of longest consecutive sequence is 1 because there is only single element in nums vector.
        if (n <= 1)
        {
            return n;
        }

        // sort the nums vector.
        sort(nums.begin(), nums.end());

        // Needed variables.
        int currLen = 1; // currLen = 1, because we have to include the length of the current element.
        int maxLen = 0;

        // Traverse the nums vector and find the answer.
        for (int i = 1; i < n; i++)
        {
            // Skip the duplicates.
            if (nums[i] == nums[i - 1])
            {
                continue;
            }

            // If the difference between current element (nums[i]) and previous element (nums[i-1]) is 1, it means these 2 elements are consecutive.
            // nums[i] - nums[i-1] = 1, then this is a consecutive sequence.
            // ex: 1,2 , diff = 2-1 = 1.
            else if (nums[i] - nums[i - 1] == 1)
            {
                // Increment currLen, because this is an consecutive sequence.
                currLen++;
            }
            else
            {
                // If the difference between current element (nums[i]) and previous element (nums[i-1]) is not 1, it means these 2 elements are not  consecutive. So re-initialize currLen with 1.
                currLen = 1;
            }

            // Store the maximum length.
            maxLen = max(maxLen, currLen);
        }

        // if maxLen == 0, it means, all duplicates are present in input array and in case of duplicates the length of longest consecutive sequence is 1.
        if (maxLen == 0)
        {
            maxLen = 1;
        }

        // finally, return answer.
        return maxLen;
    }

    /* Optimal Approach: Using unordered_set. */
    // Time Complexity: O(n) is for inserting element into set + O(n) is for finding answer, where 'n' is the size of the nums vector.
    // Space Complexity: O(n), space used by unordered_set.
    int longestConsecutive_Optimal(vector<int> &nums)
    {
        // size of nums vector.
        int n = nums.size();

        // Base Case.
        // If the nums vector is empty, then the length of longest consecutive sequence is 0 because there is no element in nums vector or if the nums vector contains only single element, then the length of longest consecutive sequence is 1 because there is only single element in nums vector.
        if (n <= 1)
        {
            return n;
        }

        // Declare an unordered_set of type integer.
        unordered_set<int> set;

        // Now, insert all elements of 'nums' vector into unordered_set.
        for (auto element : nums)
        {
            set.insert(element);
        }

        // Variable to store maximum length of consecutive sequence.
        int maxLen = 0;

        // Traverse the nums vector and find the answer.
        for (int i = 0; i < n; i++)
        {
            // Current Element.
            int currentElement = nums[i];

            // Predecessor of current element.
            // Example: if nums[i] = 100, 100 - 1 = 99 is predecessor of 100.
            int predecessor = currentElement - 1;

            // variable to store the length of current consecutive sequence.
            int len = 0;

            // Now, check if predecessor is present in our nums vector or not.
            // If predecessor is present, it means current element is a part of some other consecutive sequence, so current skip this element.

            // But, if predecessor is not present, it means current element is not a part of any other consecutive sequence and current element is start its own consecutive sequence. So, count the length of this sequence, starting with current element 'nums[i]'.
            if (set.find(predecessor) == set.end())
            {
                while (set.find(currentElement) != set.end())
                {
                    len++;
                    currentElement++;
                }
            }

            // Store the maximum length.
            maxLen = max(maxLen, len);
        }

        // finally, return answer.
        return maxLen;
    }

public:
    int longestConsecutive(vector<int> &nums)
    {

        // // Brute Force Approach.
        // return longestConsecutive_BruteForce(nums);

        // Optimal Approach.
        return longestConsecutive_Optimal(nums);
    }
};

int main(void)
{

    vector<int> nums{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

    // Solution.
    Solution obj;
    cout << obj.longestConsecutive(nums);
    return 0;
}