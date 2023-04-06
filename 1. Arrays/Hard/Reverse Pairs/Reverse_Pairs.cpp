#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /* Brute Force Approach :- Uisng nested loops. */
    // Time Complexity :- O(n^2)
    // Space Complexity :- O(1)
    int reversePairs_BruteForce(vector<int> &nums)
    {
        int n = nums.size();
        int countRevPairs = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] > (2 * nums[j]))
                {
                    countRevPairs++;
                }
            }
        }

        return countRevPairs;
    }

    /* Optimized Approach :- Using Modified Merge Sort. */
    // Time Complexity :- O(n log(n)) + O(n) + O(n), one O(n) is for merging, second O(n) is for counting reverse pairs and O(n log(n)) for merge sort.
    // Space Complexity :- O(n)
    int ans = 0;
    void merge(vector<int> &nums, int start, int end, int &ans)
    {
        // left array is from start to mid.
        // right array is from mid+1 to end.
        int mid = (start + end) / 2;
        int i = start;
        int j = mid + 1;

        vector<int> temp;

        // before merging the arrays, we need to count the reverse pairs.
        int right = mid + 1;
        int prevPairs = 0;
        int cnt = 0;
        for (int left = start; left <= mid; left++)
        {
            while (right <= end && nums[left] > (long) 2 * nums[right])
            {
                right++;
                prevPairs++;
            }

            cnt += prevPairs;
        }
        ans += cnt;

        // merging.
        // this loop will break if any one of the array is exhausted.
        while (i <= mid && j <= end)
        {
            if (nums[i] < nums[j])
            {
                temp.push_back(nums[i]);
                i++;
            }
            else
            {
                temp.push_back(nums[j]);
                j++;
            }
        }

        // copying remaining element from left part.
        while (i <= mid)
        {
            temp.push_back(nums[i]);
            i++;
        }

        // copying remaining element from right part.
        while (j <= end)
        {
            temp.push_back(nums[j]);
            j++;
        }

        // copying all elements of temp vector to original vector.
        int k = 0;
        for (int i = start; i <= end; i++)
        {
            nums[i] = temp[k++];
        }
    }

    void mergeSort(vector<int> &nums, int start, int end, int &ans)
    {
        // Base Case
        if (start >= end)
        {
            return;
        }

        // Recursive Case
        int mid = (start + end) / 2;

        // left part
        mergeSort(nums, start, mid, ans);

        // right part
        mergeSort(nums, mid + 1, end, ans);

        // merge 2 sorted arrays.
        return merge(nums, start, end, ans);
    }

    int reversePairsOptimized(vector<int> &nums)
    {
        int ans = 0;
        int start = 0;
        int end = nums.size() - 1;
        mergeSort(nums, start, end, ans);
        return ans;
    }
};

int main()
{
    Solution s;

    vector<int> nums = {1, 3, 2, 3, 1};

    cout << s.reversePairsOptimized(nums) << endl;
    for (auto i : nums)
    {
        cout << i << " ";
    }
}