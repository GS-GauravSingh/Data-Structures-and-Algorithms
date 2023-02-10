import java.util.*;

/*
Question :-
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 3⌋ times. You may assume that the majority element always exists in the array.

 

Example 1:

Input: nums = [3,2,3]
Output: 3
Example 2:


Constraints:

n == nums.length
1 <= n <= 5 * 10^4
-10^9 <= nums[i] <= 10^9
*/

public class MajorityElement_2 {
    /* Approach 1 :- Using Hashmap. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    static List<Integer> majorityElement_Approach_1(int nums[]) {
        // size of length.
        int n = nums.length;

        // list to store answers.
        List<Integer> ans = new ArrayList<Integer>();

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

        // majority element is the element that appear more than n/3 times.
        int appear = n / 3;
        var entrySet = frequency.entrySet();

        for (var entry : entrySet) {
            int freq = entry.getValue();

            if (freq > appear) {
                ans.add(entry.getKey());
            }
        }

        return ans;
    }

    /* Approach 2 :- Boyer Moore Voting Algorithm (Extended Version). */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    static List<Integer> majorityElement_Approach_2(int nums[]) {
        // size of array.
        int n = nums.length;

        // list to store answers.
        List<Integer> ans = new ArrayList<Integer>();
        
        // at max, we can have only 2 majority elements.
        // and minimum, we can have 0 majority elements.
        int num1 = -1, num2 = -1, votes_1 = 0, votes_2 = 0;

        for (int i = 0; i < nums.length; i++) {
            
            if(nums[i] == num1)
            {
                votes_1++;
            }
            else if(nums[i] == num2)
            {
                votes_2++;
            }
            else if(votes_1 == 0)
            {
                num1 = nums[i];
                votes_1++;
            }
            else if(votes_2 == 0)
            {
                num2 = nums[i];
                votes_2++;
            }
            else{
                votes_1--;
                votes_2--;
            }
        }

        // verify if num1 and num2 appear more than n/3 times or not.
        votes_1 = 0;
        votes_2 = 0;

        for (int i = 0; i < nums.length; i++) {
            if(nums[i] == num1)
            {
                votes_1++;
            }
            else if(nums[i] == num2)
            {
                votes_2++;
            }
        }

        int appear = n/3;
        if(votes_1 > appear)
        {
            ans.add(num1);
        }
        if(votes_2 > appear)
        {
            ans.add(num2);
        }

        return ans;
    }

    public static void main(String[] args) {

        int nums[] = { 1, 2 };

        List<Integer> ans = new ArrayList<>();
        // ans = majorityElement_Approach_1(nums);
        ans = majorityElement_Approach_1(nums);

        for (int x : ans) {
            System.out.print(x + " ");
        }
    }
}
