import java.util.HashMap;

/*
Question :-
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:

n == nums.length
1 <= n <= 5 * 10^4
-10^9 <= nums[i] <= 10^9
*/

public class MajorityElement {
    /* Approach 1 :- Using Hashmap. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    static int majorityElement_Approach_1(int nums[]) {
        // size of length.
        int n = nums.length;

        // hashmap
        HashMap<Integer, Integer> frequency = new HashMap<>();

        // store the frequency of each element into map.
        for (int i = 0; i < n; i++) {
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

        // majority element is the element that appear more than n/2 times.
        int appear = n/2;
        var entrySet = frequency.entrySet();

        for (var entry : entrySet) {
            int freq = entry.getValue();

            if (freq > appear) {
                return entry.getKey();
            }
        }

        return -1;
    }

    /* Approach 2 :- Boyer Moore Voting Algorithm. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    static int majorityElement_Approach_2(int nums[]) {
        // size of array.
        int n = nums.length;

        int candidate = -1;
        int votes = 0;
        for (int i = 0; i < n; i++) {
            if (votes == 0) {
                candidate = nums[i];
                votes++;
            } else if (nums[i] == candidate) {
                votes++;
            } else {
                votes--;
            }
        }

        return candidate;
    }

    public static void main(String[] args) {

        int nums[] = { 2, 2, 1, 1, 1, 2, 2 };

        System.out.println("Majority Element is : " + majorityElement_Approach_1(nums));
        System.out.println("Majority Element is : " + majorityElement_Approach_2(nums));
    }
}
