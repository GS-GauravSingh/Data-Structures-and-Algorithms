import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

/*
Question:-
Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.


Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:

Input: nums = [1,1,2]
Output: [1]
Example 3:

Input: nums = [1]
Output: []


Constraints:

n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
Each element in nums appears once or twice.
*/
public class FindAllDuplicates {
    /* Approach 1 :- Using Nested Loops. */
    // Time Complexity :- O(n^2)
    // Space Complexity :- O(1)
    static List<Integer> findDuplicates_Approach_1(int nums[]) {
        // size of array.
        int n = nums.length;

        // list to store answer.
        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    ans.add(nums[i]);
                }
            }
        }

        return ans;
    }

    /* Approach 2 :- Using sorting. */
    // Time Complexity :- O(n log(n))
    // Space Complexity :- O(1)
    static List<Integer> findDuplicates_Approach_2(int nums[]) {
        // size of array.
        int n = nums.length;

        // list to store answer.
        List<Integer> ans = new ArrayList<>();

        // sort the given array.
        Arrays.sort(nums);

        for (int j = 0; j < n - 1; j++) {
            if (nums[j] == nums[j + 1]) {
                ans.add(nums[j]);
            }
        }

        return ans;
    }

    /* Approach 3 :- Using hashing. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    static List<Integer> findDuplicates_Approach_3(int nums[]) {
        // // size of array.
        // int n = nums.length;

        // list to store answer.
        List<Integer> ans = new ArrayList<>();

        // HashMap
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

        // duplicate element is the element having frequency greater that 1.
        var entrySet = frequency.entrySet();

        for (var entry : entrySet) {
            int freq = entry.getValue();

            if (freq > 1) {
                ans.add(entry.getKey());
            }
        }

        return ans;
    }

    /*
     * Approach 4 :- One Pass
     * 
     * Algorithm :-
     * 1. traverse through the array.
     * 2. Treat array elements an indexes and mark element at nums[index] as
     * negative.
     * int index = nums[i];
     * num[index] = -nums[index];
     * 3. Now check if the value a the index is +ve or not. If positive it's a
     * duplicate element. Because if this element appear only once then it's sign is
     * negative.
     * 
     * 
     * Dry Run :-
     * 
     * Example :- {4, 2, 4, 3, 1}
     * 
     * 1st Pass:
     * Element = nums[0] = 4.
     * index = nums[4 - 1] = nums[3], -1 is for 0-based indexing.
     * Array: {4, 2, 4, -3, 1}
     * nums[3] = -3, which is negative.
     * 
     * 2nd Pass:
     * Element = nums[1] = 2.
     * index = nums[2 - 1] = nums[1], -1 is for 0-based indexing.
     * Array: {4, -2, 4, -3, 1}
     * nums[1] = -2, which is negative.
     * 
     * 3rd Pass:
     * Element = nums[2] = 4.
     * index = nums[4 - 1] = nums[3], -1 is for 0-based indexing.
     * Array: {4, -2, 4, +3, 1}
     * nums[3] = +3, duplicate found.
     * 
     * 4th Pass:
     * Element = nums[3] = 3.
     * index = nums[3 - 1] = nums[2], -1 is for 0-based indexing.
     * Array: {4, -2, -4, 3, 1}
     * nums[2] = -2, which is negative.
     * 
     * 5th Pass:
     * Element = nums[4] = 1.
     * index = nums[1 - 1] = nums[0], -1 is for 0-based indexing.
     * Array: {-4, -2, -4, 3, 1}
     * nums[0] = -4, which is negative.
     * 
     */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    static List<Integer> findDuplicates_Approach_4(int nums[])
    {
        // size of array.
        int n = nums.length;

        // list to store answer.
        List<Integer> ans = new ArrayList<>();

        for (int i = 0; i < n; i++)
        {
            // index.
            int index = Math.abs(nums[i]) - 1; // 0-based indexing.

            // negate the element
            nums[index] = -nums[index];

            // if this element is positive means double negation had happened which 
            // means we editied this element twice.
            if(nums[index] > 0)
            {
                ans.add((index+1));
            }
        }
        
        return ans;
    }

    // Method to print list.
    static void printList(List<Integer> ans)
    {
        for (int i = 0; i < ans.size(); i++) {
            System.out.print(ans.get(i)+ " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int nums[] = { 4, 3, 2, 7, 8, 2, 3, 1 };

        List<Integer> ans1 = findDuplicates_Approach_1(nums);
        List<Integer> ans2 = findDuplicates_Approach_1(nums);
        List<Integer> ans3 = findDuplicates_Approach_1(nums);
        List<Integer> ans4 = findDuplicates_Approach_1(nums);

        printList(ans1);
        printList(ans2);
        printList(ans3);
        printList(ans4);
    }
}