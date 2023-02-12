
/*
 * Question :-
 * 
 * Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
 

Constraints:

1 <= n <= 105
nums.length == n + 1
1 <= nums[i] <= n
All the integers in nums appear only once except for precisely one integer which appears two or more times.
 */
import java.util.*;

public class FindTheDuplicateNumber {
    /* Brute Force Method 1:- Using nested loops. */
    // Time Complexity:- O(n^2)
    // Space Complexity:- O(1)
    static int findDuplicate_Approach_1(int nums[]) {
        // size of array.
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    return nums[i];
                }
            }
        }
        return -1;
    }

    /*
     * Brute Force Method 2:- Use sorting (so the duplicate element come together).
     */
    // Time Complexity:- O(n log(n))
    // Space Complexity:- O(1)
    static int findDuplicate_Approach_2(int nums[]) {
        // size of array.
        int n = nums.length;

        // sort the given array.
        Arrays.sort(nums);

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }
        }

        return -1;
    }

    /* Brute Force Method 3:- Use Hashing */
    // Time Complexity:- O(n)
    // Space Complexity:- O(n)
    static int findDuplicate_Approach_3(int nums[]) {
        // hashmap
        HashMap<Integer, Integer> frequency = new HashMap<>();

        // store the frequency of each element into map.
        for (int i = 0; i < nums.length; i++) {
            int element = nums[i];

            if (frequency.containsKey(element) == true) {
                // means, nums[i] is present in map. SO, increase it's frequency.

                // getting the old frequency of element;
                int freq = frequency.get(element);

                // increment the frequency and store it in map.
                freq++;

                // storing new frequency.
                frequency.put(element, freq);
            } else {
                // means, nums[i] is not present in map. SO, insert nums[i] into map with
                // frequency 1.
                frequency.put(element, 1);
            }
        }

        // Traverse the map and print the element which has frequency more than n/k.
        var entrySet = frequency.entrySet();

        for (var entry : entrySet) {
            int freq = entry.getValue();

            if (freq > 1) {
                return entry.getKey();
            }
        }

        return -1;
    }

    /*
     * Optmized Approach:- Marking visited value within the array.
     * Since all values of the array are between [1…n] and the array size is n+1,
     * while scanning the array from left to right, we set the nums[n] to its
     * negative value.
     * 
     * With extra O(1) space, with modifying the input.
     */
    // Time Complexity:- O(n)
    // Space Complexity:- O(1)
    static int findDuplicate_Optimized_1(int nums[]) {
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            int idx = Math.abs(nums[i]);

            // if any element is already visited, then return it's index.
            if (nums[idx] < 0) {
                return idx;
            }

            // mark visited.
            nums[idx] = -nums[idx];
        }

        return -1;
    }

    public static void main(String[] args) {
        int nums[] = { 1, 3, 4, 2, 2 };

        System.out.println(findDuplicate_Approach_1(nums));
        System.out.println(findDuplicate_Approach_2(nums));
        System.out.println(findDuplicate_Approach_3(nums));
        System.out.println(findDuplicate_Optimized_1(nums));

    }
}
