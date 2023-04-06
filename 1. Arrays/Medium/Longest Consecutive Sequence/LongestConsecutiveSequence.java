import java.util.Arrays;
import java.util.HashSet;

public class LongestConsecutiveSequence {
    /*
     * Approach 1 :- using sorting.
     * 
     * Intution:-
     * 1. The very first thing we can think of is we simply arrange the array in
     * ascending order.
     * 2. After arranging the array in sorted order, we just find the length of the
     * longest consecutive sequence.
     * 
     * Time Complexity :- O(n log(n)), n is the size of the array.
     * Space Complexity :- O(1).
     */
    static int longestConsecutive_Approach_1(int[] nums) {

        // size of array.
        int n = nums.length;

        // Base Case
        if (n == 0) {
            // if length of array is zero, then from here simply return 0.

            return 0;
        }
        if (n == 1) {
            // if length of array is 1, then the longest consecutive sequence is of length
            // 1.

            return 1;
        }

        // sort the given array.

        Arrays.sort(nums);

        // put currLen = 1 and maxLen = 0.
        int currLen = 1, maxLen = 0;

        for (int i = 1; i < n; i++) {
            // skip the duplicate elements.
            if (nums[i] == nums[i - 1]) {
                continue;
            }

            // if difference of nums[i] - nums[i-1] = 1, then this is a consecutive
            // sequence,
            // increment the currLen.
            // ex:- 1,2 , diff = 2-1 = 1.
            else if (nums[i] - nums[i - 1] == 1) {
                currLen++;
            } else {
                // if difference is not 1, reinitilized length with 1.
                currLen = 1;
            }

            // calculate max length.
            maxLen = Math.max(maxLen, currLen);
        }

        // update maxLen one more time, because if all duplicates are present,
        // then the answer is 1.
        maxLen = Math.max(maxLen, currLen);
        return maxLen;
    }

    /* optimized apporach :- using hashing. */
    // Time Complexity :- O(n), n is the size of the array.
    // Space Complexity :- O(n).
    static int longestConsecutive_Approach_2(int nums[]) {
        // size of vector.
        int n = nums.length;

        // Base Case
        if (n == 0) {
            // if length of array is zero, then from here simply return 0.
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        // insert all element into hashset.
        HashSet<Integer> s = new HashSet<>();

        for (int i = 0; i < nums.length; i++) {

            int element = nums[i];

            s.add(element);
        }

        // variable to store the length of longest consecutive sequence.
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            // current element is nums[i]. Now try to find the predecessor of current
            // element,
            // if predecessor is present it means this current element is a part of a
            // consecutive sequence.
            // So, ignore this element.

            // Example:- current element = 2, predecessor is 2-1 i.e., 1.
            int currElement = nums[i];
            int predecessor = currElement - 1;

            // But if predecessor is not present, it means this current element can start
            // it's own consecutive sequence.
            // Now, find it's successor and computer the length.
            int currLen = 0;

            if (s.contains(predecessor) == false) {
                while (s.contains(currElement) == true) {
                    currElement++;
                    currLen++;
                }
            }

            // update max length
            maxLen = Math.max(maxLen, currLen);
        }

        return maxLen;
    }

    public static void main(String[] args) {
        int nums[] = { 100, 4, 200, 1, 3, 2 };

        System.out.println("Length of Longest Consecutive Sequence is " + longestConsecutive_Approach_1(nums));
        System.out.println("Length of Longest Consecutive Sequence is " + longestConsecutive_Approach_2(nums));
    }
}
