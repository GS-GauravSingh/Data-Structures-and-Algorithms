#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Brute Force Approach: Using nested loops generate all pairs and then count the number of reverse pairs in the array.  */
    // Time Complexity: O(n^2), where 'n' is the size of the nums vector.
    // Space Complexity: O(1).
    int reversePairs_BruteForce(vector<int> &nums)
    {
        // Size of nums vector.
        int n = nums.size();

        // variable to count reverse pairs.
        int cnt = 0;

        // Generate all pairs.
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long val = 2l * nums[j]; // converting nums[j] into long long.

                if (nums[i] > val)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }

    /* Optimized Approach: Using Merge Sort. */

    /* Merge method of Merge Sort Algorithm. */
    // Time Complexity: O(n) is for merging both the halfs + O(n) for counting reverse pairs, where 'n' is the size of the array.
    // Space Complexity: O(n), space used by auxiliary vector.
    int merge(vector<int> &nums, long long low, long long high)
    {
        // Calculating Mid.
        int mid = low + (high - low) / 2;

        // vector to store elements in sorted order.
        vector<int> temp;

        // Our left half is from [low, mid] and right half is from [mid + 1, high].
        int left = low;
        int right = mid + 1;

        // variable to store inversion count.
        int rev_cnt = 0;

        // variable to count reverse pairs for each number.
        int cnt = 0;

        // Counting reverse pairs.
        while (left <= mid)
        {
            // Move the right pointer until we found that 2l*nums[right] > nums[left].
            while (right <= high && nums[left] > 2l * nums[right] /* Avoiding Integer Overflow by multiplying nums[j] with 2l. */)
            {
                right++; // Increment the pointer.
                cnt++;   // count the reverse pair.
            }

            // Store the count reverse pairs.
            rev_cnt += cnt;

            // increment left pointer.
            left++;
        }

        // Re-initialize left and right pointer for the merging step.
        left = low;
        right = mid + 1;

        // In 'temp' vector, compare and Store the elements in sorted order.
        while (left <= mid && right <= high)
        {
            if (nums[left] <= nums[right])
            {
                // store element.
                temp.push_back(nums[left]);

                // update left pointer.
                left++;
            }
            else
            {
                // arr[left] > arr[right].

                // store element.
                temp.push_back(nums[right]);

                // update right pointer.
                right++;
            }
        }

        // Process remaining elements of left half if exists.
        while (left <= mid)
        {
            // store element.
            temp.push_back(nums[left]);

            // update left pointer.
            left++;
        }

        // Process remaining elements of right half if exists.
        while (right <= high)
        {
            // store element.
            temp.push_back(nums[right]);

            // update right pointer.
            right++;
        }

        // Copy back all the element from temp array to original array.
        // 'temp' array contains the elements in sorted order.

        int k = 0; // Pointer to traverse the 'temp' vector.

        for (int i = low; i <= high; i++)
        {
            nums[i] = temp[k++];
        }

        // return inversion count.
        return rev_cnt;
    }

    /* Merge Sort Algorithm. */
    // Time Complexity: O(2n*log(n)), where 'n' is the size of the array.
    // Space Complexity: O(n) + O(log (n)), space used by auxiliary vector in merge method and recursive stack space.
    int mergeSort(vector<int> &nums, int low, int high)
    {
        // variable to store inversion count.
        int rev_cnt = 0;

        // Base case
        if (low >= high)
        {
            return rev_cnt;
        }

        // Recursive Case.

        // Calculating Mid.
        int mid = low + (high - low) / 2;

        // Left Half.
        rev_cnt += mergeSort(nums, low, mid);

        // Right Half.
        rev_cnt += mergeSort(nums, mid + 1, high);

        // Merge.
        rev_cnt += merge(nums, low, high);

        // return the count of reverse pairs.
        return rev_cnt;
    }

public:
    int reversePairs(vector<int> &nums)
    {

        // // Brute Force Approach.
        // return reversePairs_BruteForce(nums);

        // Optimized Approach.
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main(void)
{
    vector<int> nums{1, 3, 2, 3, 1};

    // Solution.
    Solution obj;
    cout << "Reverse Pairs Count: " << obj.reversePairs(nums) << ".";
    return 0;
}