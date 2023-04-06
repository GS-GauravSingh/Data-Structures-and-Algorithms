import java.util.*;

public class ContainsDuplicate {
    /*
     * Approach 1:- Using nested loops.
     * 
     * Time Complexity :- O(n^2)
     * Space Complexity :- O(1)
     */
    static boolean containsDuplicate_Approach_1(int[] nums) {
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        return false;
    }

    /*
     * Approach 2 :- Using Sorting.
     * 
     * Time Complexity :- O(n log(n))
     * Space Complexity :- O(1)
     */
    static boolean containsDuplicate_Approach_2(int[] nums) {

        // sort the array.
        Arrays.sort(nums);

        // traverse through the array and chek duplicates.
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }

        return false;
    }

    /*
     * Approach 3 :- Using hashing.
     * 
     * Time Complexity :- O(n)
     * Space Complexity :- O(n)
     */
    static boolean containsDuplicate_Approach_3(int[] nums) {
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

        // traverse through the map, and any element having frequency > 1, means
        // duplicates is present.
        var entrySet = frequency.entrySet();

        for (var entry : entrySet) {
            int freq = entry.getValue();

            if (freq > 1) {
                return true;
            }
        }

        return false;

    }

    public static void main(String[] args) {

        int[] nums = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };

        boolean ans = containsDuplicate_Approach_3(nums);

        if (ans) {
            System.out.println("Duplicates Present.");
        } else {
            System.out.println("Duplicates not Present.");

        }
    }
}
