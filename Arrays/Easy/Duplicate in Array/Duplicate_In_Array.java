/*
Question :-
You are given an array "arr" of size "n" and elements in the array are in the range of 1 to n-1. All elements in the array appear exactly once except for one element, your task is to return that element.

Example :
arr = {1,2,3, 4,4}; all elements appear exactly once, except for one element i.e, 4. So, our answer is 4.

*/

import java.util.Arrays;
import java.util.HashMap;

public class Duplicate_In_Array {

    /* Brute Force Approach 1 :- using nested loops. */
    // Time Complexity :- O(n^2)
    // Space Complexity :- O(1)
    static int findDuplicate_Approach_1(int arr[]) {

        // size of array.
        int n = arr.length;

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    return arr[i];
                }
            }
        }

        return -1;
    }

    /* Brute Force Approach 2 :- using sorting. */
    // Time Complexity :- O(n log(n))
    // Space Complexity :- O(1)
    static int findDuplicate_Approach_2(int arr[]) {

        // size of array.
        int n = arr.length;

        // sort the given array.
        Arrays.sort(arr);

        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                return arr[i];
            }
        }

        return -1;
    }

    /* Approach 3 :- using unordered_map. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    static int findDuplicate_Approach_3(int arr[]) {

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

        // traverse through the map, and any element having frequency > 1, means
        // that elements is duplicate element.
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
     * Approach 4 :- using Bitwise Xor(^) operator.
     * 
     * Algorithm :-
     * step 1:- store the xor of all the elemnets of array in a variable.
     * step 2:- take the xor of all element from 1 to n-1.
     * step 3:- return answer.
     * 
     * Dry Run :- arr = {1,2,3,4,4}
     * 
     * 
     * // Step 1: xoring of all array elements.
     * 
     * iterate 0 to n-1,
     * xorr = 1^2^3^4^4; [4 ^ 4 = 0 and 1^2^3 = 0 and 0^0 = 0].
     * xorr = 0;
     * 
     * // Step 2: take the xor of all element from 1 to n-1.
     * iterate 1 to n-1,
     * xorr = 1^2^3^4; [1^2^3 = 0 and 0^4 = 0].
     * xorr = 4;
     * 
     */

    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    static int findDuplicate_Approach_4(int arr[]) {

        // size of array.
        int n = arr.length;

        int xorr = 0;

        for (int i = 0; i < n; i++) {
            xorr = xorr ^ arr[i];
        }

        for (int i = 1; i < n; i++) {
            xorr = xorr ^ i;
        }

        return xorr;
    }

    // method to print array.
    static void print(int arr[]) {

        for (int x : arr) {
            System.out.print(x + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {

        int arr[] = { 1, 2, 3, 4, 4 };

        System.out.println(findDuplicate_Approach_1(arr));
        System.out.println(findDuplicate_Approach_2(arr));
        System.out.println(findDuplicate_Approach_3(arr));
        System.out.println(findDuplicate_Approach_4(arr));
    }
}