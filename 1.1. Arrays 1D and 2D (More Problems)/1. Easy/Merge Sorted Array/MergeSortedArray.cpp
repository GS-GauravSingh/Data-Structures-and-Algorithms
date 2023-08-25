#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* Brute Force Approach: Using Sorting. */
    // Time Complexity: O(n) is for inserting all elements of nums2 in nums1 + O(m+n*log(m+n)) is for sorting nums1 vector. Where 'm' is the size of nums1 vector and 'n' is the size of nums2 vector.
    // Space Complexity: O(1).
    void merge_BruteForce(vector<int> &nums1, int nums1_size, vector<int> &nums2, int nums2_size)
    {
        // Step 1: Insert all the elements of nums2 in nums2.
        for (int i = 0; i < nums2.size(); i++)
        {
            nums1[nums1_size + i] = nums2[i];
        }

        // Step 2: Sort the nums1 vector and our answer is ready.
        sort(nums1.begin(), nums1.end());
    }

    /* Optimized Approach: Using 3-Pointers. */
    // Time Complexity: O(m + n),  Where 'm' is the size of nums1 vector and 'n' is the size of nums2 vector.
    // Space Complexity: O(1).
    void merge_Optimized(vector<int> &nums1, int nums1_size, vector<int> &nums2, int nums2_size)
    {
        /*
        Step 1: Initialize 3-pointers, i, j, and k. Now, let's see where are these 3 pointer points initially.

        Nums1   :   [1,2,3,0,0,0],   Nums2 :    [2,5,6]
        Pointers:        i     k                     j

        'i' pointer points to the last element of nums1 array, remember nums1 is of size 'm' and total capacity of nums1 is 'm+n'.
        'j' pointer points to the last element of nums2 array and nums2 is of size 'n'.
        and 'k' pointer points to the 'm+n - 1'th index of nums1 array.
        */

        int i = nums1_size - 1;
        int j = nums2_size - 1;
        int k = nums1_size + nums2_size - 1;

        // Step 2: Now, our pointers are ready, Now, compare the element using 'i' and 'j' pointer and store the largest element on the 'k'th index.
        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }

        // Now, after the above loop ends, it may possible that our nums2 vector has some elements left.
        // So, Porcess the remaining element.
        while (j >= 0)
        {
            nums1[k--] = nums2[j--];
        }
    }

public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        // // Brute Force Solution.
        // merge_BruteForce(nums1, m, nums2, n);

        // Optimized Approach.
        merge_Optimized(nums1, m, nums2, n);
    }
};

int main(void)
{

    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};

    int nums1_size = 3;
    int nums2_size = 3;

    // Solution.
    Solution obj;
    obj.merge(nums1, nums1_size, nums2, nums2_size);

    for (int i = 0; i < nums1.size(); i++)
        cout << nums1[i] << " ";
    return 0;
}