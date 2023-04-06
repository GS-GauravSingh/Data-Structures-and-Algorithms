/*
Question :-
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.



Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


Constraints:

1 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
*/

import java.util.*;

public class FourSum {
    /* Approach :- Using sorting, loops,and 2 pointer. */
    // Time Complexity :- O()
    // Space Complexity :- O()
    static List<List<Integer>> fourSum(int[] nums, int target) {

        // size of array.
        int n = nums.length;

        // sort the array.
        Arrays.sort(nums);

        // list of list to store answer.
        List<List<Integer>> ans = new ArrayList<>();

        // iterate through the array and find the answer.
        for (int i = 0; i < n; i++) {
            // first Number.
            long firstNumber = nums[i];

            for (int j = i + 1; j < n; j++) {
                // second Number .
                long secondNumber = nums[j];

                // find thrid and fourth number using 2 pointer approach.
                int start = j + 1;
                int end = n - 1;
                while (start < end) {
                    // third number.
                    long thirdNumber = nums[start];

                    // fourth number.
                    long fourthNumber = nums[end];

                    // sum
                    long sum = firstNumber + secondNumber + thirdNumber + fourthNumber;

                    if (sum == target) {
                        ans.add(Arrays.asList(nums[i], nums[j], nums[start], nums[end]));

                        // remove duplicate elements.
                        while (start < end && nums[start] == nums[start + 1]) {
                            start++;
                        }
                        while (start < end && nums[end] == nums[end - 1]) {
                            end--;
                        }

                        // move pointer's.
                        start++;
                        end--;
                    } else if (sum > target) {
                        end--;
                    } else {
                        // sum < target
                        start++;
                    }
                }
                // remove duplicate elements.
                while (j + 1 < n && nums[j] == nums[j + 1]) {
                    j++;
                }
            }
            // remove duplicate elements.
            while (i + 1 < n && nums[i] == nums[i + 1]) {
                i++;
            }
        }

        return ans;

    }

    public static void main(String[] args) {
        int nums[] = { 1, 0, -1, 0, -2, 2 };
        int target = 0;

        List<List<Integer>> ans = fourSum(nums, target);

        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans.get(i).size(); j++) {
                System.out.print(ans.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }
}
