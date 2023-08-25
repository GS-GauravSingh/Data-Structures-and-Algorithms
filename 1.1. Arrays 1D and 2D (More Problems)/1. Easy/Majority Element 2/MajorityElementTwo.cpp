#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Brute Force Approach: Using unordered_map. */
    // Time Complexity: O(n), where 'n' is the size of the nums vector.
    // Space Complexity: O(n), space used by unordered_map.
    vector<int> majorityElement_BruteForce(vector<int> &nums)
    {
        // size of vector.
        int n = nums.size();

        // vector to store answer.
        vector<int> ans;

        // map
        unordered_map<int, int> mpp;

        // counting frequency of each element.
        for (int i = 0; i < n; i++)
        {
            int element = nums[i];
            mpp[element]++;
        }

        // majority element is the element that appear more than n/3 times.
        int appear = n / 3;
        for (auto i : mpp)
        {
            if (i.second > appear)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }

    /* Optimized Approach: Using Extended Boyer Moore’s Voting Algorithm. */
    // Time Complexity :- O(n), where 'n' is the size of the nums vector.
    // Space Complexity :- O(1).
    vector<int> majorityElement_Optimized(vector<int> &nums)
    {
        /*
        Question: Can you tell me how many majority elements are possible, if the majority element is the element that appears more than ⌊ n/3 ⌋ times?
        Answer: Suppose, if the size of 'nums' vector is, let's say 10 and as we know that the majority element is the element that appears more than ⌊ n/3 ⌋ times.

        So, (n / 3) => (10 / 3) => 3. So, if the element is the majority element, then the element must appear more than 3 time in 'nums' array.

        Let's assume majority element has appear 4 times.

        Now, Observe carefully, if a single majority element appear 4 times in nums array.
        So, 2 majority elements must appear 8 times (4 + 4 = 8) in the nums array.

        Now, if you observe carefully, we have an array of size 10, and most of the space (8) is occupied by majority element and in rest of the space there can be no other majority elements that appear more than n/3 times, therefore we can say that, atmax there can be 2 majority elements exists in the array.
        */

        // Initialize 'freq' with 0.
        int freq_1 = 0, freq_2 = 0;

        // variable to store majority element.
        int majorityEle_1 = INT_MIN, majorityEle_2 = INT_MIN;

        // Traverse the array.
        for (int i = 0; i < nums.size(); i++)
        {
            // IF 'freq_1 == 0', in this case,
            // Step 1: Consider this current element 'nums[i]' as majority element 1.
            // Setp 2: Increment the frequence by 1.
            if (freq_1 == 0 && majorityEle_2 != nums[i])
            {
                majorityEle_1 = nums[i];
                freq_1++;
            }

            // else IF 'freq_2 == 0', in this case,
            // Step 1: Consider this current element 'nums[i]' as majority element 2.
            // Setp 2: Increment the frequence by 1.
            else if (freq_2 == 0 && majorityEle_1 != nums[i])
            {
                majorityEle_2 = nums[i];
                freq_2++;
            }

            // Simply check, if the the current element i.e., nums[i], if nums[i] == majorityEle_1, then increment the 'freq'.
            else if (nums[i] == majorityEle_1)
            {
                freq_1++;
            }

            // Simply check, if the the current element i.e., nums[i], if nums[i] == majorityEle_2, then increment the 'freq'.
            else if (nums[i] == majorityEle_2)
            {
                freq_2++;
            }

            // but, if the current element i.e., nums[i], if nums[i] != majorityEle_1 or nums[i] != majorityEle_2, then decrement the 'freq_1' and 'freq_2'.
            else
            {
                freq_1--;
                freq_2--;
            }
        }

        // Manually check if the stored elements in
        // majorityEle_1 and majorityEle_2 are the majority elements:
        freq_1 = 0, freq_2 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == majorityEle_1)
            {
                freq_1++;
            }

            if (nums[i] == majorityEle_2)
            {
                freq_2++;
            }
        }

        // The majority element is the element that appears more than ⌊ n/3 ⌋ times
        int appear = (nums.size() / 3);

        // vector to store answer.
        vector<int> ans;

        if (freq_1 > appear)
        {
            ans.push_back(majorityEle_1);
        }
        if (freq_2 > appear)
        {
            ans.push_back(majorityEle_2);
        }

        return ans;
    }

public:
    vector<int> majorityElement(vector<int> &nums)
    {
        //    // Brute Force Solution.
        //    return majorityElement_BruteForce(nums);

        // Optimized Solution.
        return majorityElement_Optimized(nums);
    }
};

int main(void)
{
    vector<int> nums{3, 2, 3};

    // Solution.
    Solution obj;
    vector<int> ans = obj.majorityElement(nums);

    cout << "Majority Elements: ";
    for (auto i : ans)
        cout << i << " ";
    return 0;
}