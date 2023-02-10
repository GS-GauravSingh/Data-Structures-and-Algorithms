/*
Question :-
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.


Constraints:
nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-10^9 <= nums1[i], nums2[j] <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

/*------------------------------ Solution Class -----------------------------*/
class Solution
{
public:
    /* Approach 1 :- Put all elements of nums2 into nums1 and sort the nums1 array */
    // Time Complexity:- O(m+n log(m+n)), m and n are size of vectors.
    // Space Complexity:- O(1).
    void merge_Approach_1(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nums1[i + m] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }

    /* Approach 2 :- using 3 pointers. */
    // Time Complexity:- O(n)
    // Space Complexity:- O(1)
    void merge_Approach_2(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1; // variable to traverse both vectors.
        int k = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] < nums2[j])
            {
                // we are inserting elements from back. 
                // So we have to insert elements in descending order.
                nums1[k--] = nums2[j--];
            }
            else{
                nums1[k--] = nums1[i--];

            }
        }

        // if nums2 has some elements left.
        while(j >= 0){
            nums1[k--] = nums2[j--];
        }
    }

    /* Method to print vector. */
    void print(vector<int> arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
/*-------------------------- Solution Class Ends Here. ------------------------- */

int main()
{
    vector<int> arr1 = {1, 2, 3, 0, 0, 0};
    vector<int> arr2 = {2, 5, 6};
    int m = 3;
    int n = 3;

    Solution s;
    s.merge_Approach_2(arr1, m, arr2, n);
    s.print(arr1);
}