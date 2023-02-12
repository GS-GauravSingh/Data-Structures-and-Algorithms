import java.util.*;

public class Find_Elements_that_Appear_More_than_N_by_k_times {
    /* Approach 1 :- Using hashing. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    static void moreThanNbyk_Approach_1(int arr[], int n, int k) {
        // we have to find those elements that appear more than n/k times.
        int occur = n / k;

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

        // Traverse the map and print the element which has frequency more than n/k.
        var entrySet = frequency.entrySet();

        for (var entry : entrySet) {
            int freq = entry.getValue();

            if (freq > occur) {
                System.out.println(entry.getKey() + " ");
            }
        }

    }

    public static void main(String[] args) {
        int arr[] = { 1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1 };
        int k = 4;

        moreThanNbyk_Approach_1(arr, arr.length, k);

    }
}
