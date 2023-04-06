import java.util.HashMap;

public class Single_Number {
    /* Brute Force Approach :- Using Hashmap. */
    // Time Complexity:- O(n)
    // Space Complexity:- O(n)
    static int singleNumber_Approach_1(int arr[]) {
        // hashmap
        HashMap<Integer, Integer> frequency = new HashMap<>();

        // store the frequency of each element into map.
        for (int i = 0; i < arr.length; i++) {
            int element = arr[i];

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

        // traverse through the map, and any element having frequency == 1, means
        // that elements is unique element.
        var entrySet = frequency.entrySet();

        for (var entry : entrySet) {
            int freq = entry.getValue();

            if (freq == 1) {
                return entry.getKey();
            }
        }
        return -1;

    }

    /* Optimize Approach :- Using Xor(^) operator. */
    // Time Complexity:- O(n)
    // Space Complexity:- O(1)

    /*
     * Xor (^) =
     * 1 ^ 1 = 0
     * 0 ^ 1 = 1
     * 1 ^ 0 = 1
     * 0 ^ 0 = 0
     */
    static int singleNumber_Approach_2(int nums[]) {
        int result = nums[0];

        for (int i = 1; i < nums.length; i++) {
            result = result ^ nums[i];
        }
        return result;

    }

    public static void main(String[] args) {
        int arr[] = { 7, 3, 5, 4, 5, 3, 4 };

        System.out.println("Unique Element is " + singleNumber_Approach_1(arr));
        System.out.println("Unique Element is " + singleNumber_Approach_2(arr));
    }
}
