/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.



Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).


Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-10^4 <= target <= 10^4
*/

import java.util.*;

public class ThreeSumClosest {
    /* Approach :- Using sorting and loops and 2 pointer. */
    // Time Complexity :- O(n log(n)) + O(n^2), n log(n) for sorting, and O(n^2) for
    // iterating through the array.
    // Space Complexity :- O(1)
    static int threeSumClosest(int[] nums, int target) {
        // size of array.
        int n = nums.length;

        // sort the array.
        Arrays.sort(nums);

        // variable to find sum closest to target.
        int diff = Integer.MAX_VALUE;

        // variable to store answer.
        int ans = -1;

        for (int i = 0; i < n; i++)
        {
            // first number.
            int firstNumber = nums[i];

            int start = i + 1;
            int end = n - 1;
            while (start < end)
            {
                // second number.
                int secondNumber = nums[start];

                // third number.
                int thirdNumber = nums[end];

                // sum
                int sum = firstNumber + secondNumber + thirdNumber;

                if (sum == target)
                {
                    return sum;
                }
                else if (Math.abs(sum - target) < diff)
                {
                    diff = Math.abs(sum - target);
                    ans = sum;
                }

                // move pointers.
                if (sum > target)
                {
                    end--;
                }
                else
                {
                    // sum < target
                    start++;
                }
            }
        }

        return ans;
    }
    public static void main(String[] args) {
        int nums[] = {-1,2,1,-4};
        int target = 1;

        System.out.println("Sum = " + threeSumClosest(nums, target));
    }
}
