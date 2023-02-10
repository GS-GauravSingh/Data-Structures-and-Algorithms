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
import java.util.Arrays;

public class MergeSortedArrays {

    /*
     * Approach 1:- Put all elements of nums2 into nums1 and sort the nums1 array.
     */
    // Time Complexity :- O(m+n log(m+n))
    // Space Complexity :- O(1)
    static void merge_Approach_1(int[] nums1, int m, int[] nums2, int n) {

        // Putting all elements of nums2, into nums1.
        for (int i = 0; i < nums2.length; i++) {
            nums1[m + i] = nums2[i];
        }

        // sort the nums1 array.
        Arrays.sort(nums1);
    }

    /* Approach 2:- using 3 pointers. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    static void merge_Approach_2(int[] nums1, int m, int[] nums2, int n) {

        // initilaize 3 pointers.
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            // we are inserting elements from back.
            // So we have to insert elements in descending order.
            if (nums1[i] < nums2[j]) {
                nums1[k] = nums2[j];
                j--;
                k--;
            } else {
                // nums1[i] > nums2[j].
                nums1[k] = nums1[i];
                i--;
                k--;

            }
        }

        // if nums2 has some elements left.
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }

    public static void main(String[] args) {
        int nums1[] = { 1, 2, 3, 0, 0, 0 };
        int nums2[] = { 2, 5, 6 };

        int m = 3, n = 3;

        merge_Approach_2(nums1, m, nums2, n);

        for(int x : nums1)
        {
            System.out.print(x + " ");
        }
    }
}
