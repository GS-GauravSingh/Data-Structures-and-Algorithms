import java.util.HashMap;

/*
 * Question :-
 * 
 * Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to
 * check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted
 * or unsorted.
 * 
 * 
 * Example 1:
 * 
 * Input:
 * a1[] = {11, 1, 13, 21, 3, 7}
 * a2[] = {11, 3, 7, 1}
 * Output:
 * Yes
 * Explanation:
 * a2[] is a subset of a1[]
 * 
 * 
 * Your Task:
 * You don't need to read input or print anything. Your task is to complete the
 * function isSubset() which takes the array a1[], a2[], its size n and m as
 * inputs and return "Yes" if arr2 is subset of arr1 else return "No" if arr2 is
 * not subset of arr1.
 * 
 * 
 * Expected Time Complexity: O(n)
 * Expected Auxiliary Space: O(n)
 * 
 * Constraints:
 * 1 <= n,m <= 105
 * 1 <= a1[i], a2[j] <= 10^6
 */

public class Array_subset_of_another_Array {

    /*
     * Brute Force Approach :-
     * check whether all elements of a2 are present in a1 or not.
     * If present that a2 is a subset of a1, otherwise a2 is not a subset of a1.
     * 
     * Time Complexity :- O(m*n), m and n are the size of a1 and a2.
     * Space Complexity :- O(1).
     */

    static String isSubset_BruteForce(long a1[], long a2[], long size1, long size2) {
        for (int i = 0; i < size2; i++) {
            boolean present = false;
            for (int j = 0; j < size1; j++) {
                if (a2[i] == a1[j]) {
                    // if a2[i] is present, set the flag (present) as true, and break the loop
                    // (because we have to search for next element).
                    present = true;

                    // mark this element as checked (because duplicates may present in a2).
                    // but this will modify the original array (a1).
                    a1[j] = Integer.MAX_VALUE;
                    break;
                }
            }

            // if a2[i] is not present, in this case flag (present) is equals to false.
            // Means, a2 is not a subset of a1.
            if (present == false) {
                return "No";
            }
        }

        // if all elements of a2 is present in a1, then a2 is a subset of a1.
        return "Yes";
    }

    /*
     * Optimized Approach :- Using Hashmap.
     * 
     * Approach :-
     * 
     * 1. Insert all element of a1 corresponds to it's frequency, in map.
     * 2. Iterate on a2, and check if a2[i], is present in map or not.
     * 
     * Time Complexity :- O(m), m is the size of a1.
     * Space Complexity :- O(m).
     */
    static String isSubset_Optimized(long a1[], long a2[], long size1, long size2) {
        // hashmap.
        HashMap <Long, Long> map = new HashMap<Long, Long>();

        // inserting all elements of a1 into map.
        for (int i = 0; i < size1; i++)
        {
            // key (element) -> value (frequency of element).
            long key = a1[i];
            if(map.containsKey(key) == true)
            {
                // means, a1[i] is present in map. SO, increase it's frequency.
                
                // getting the old frequency of element;
                long freq = map.get(key);
                
                // increment the frequency and store it in map.
                freq++;
                
                // storing new frequency.
                map.put(key, freq);
                
            }
            else{
                // means, a1[i] is not present in map. SO, insert a1[i] into map with frequency 1. 
                map.put(key, 1L);
            }
        }
        
        // Iterate on a2, and check if a2[i], is present in map or not.
        int presentAll = 0;
        for (int i = 0; i < size2; i++)
        {
            if(map.containsKey(a2[i]) == true)
            {
                // means, a2[i] is present in map.
                // erase this element from map, because if same element is appearing more that once,
                // then it can cause error.
                long element = a2[i];

                // decrement it's frequency from map.
                // and if the frequency become 0 after decrementing, erase this element from map.
                // so, this will handle the case of duplicates.

                // getting the old frequency of element;
                long freq = map.get(a2[i]);

                // decrementing the frequency.
                freq--;

                if(freq == 0)
                {
                    map.remove(element);
                }

                presentAll++;

            }
            else{
                // means, a2[i] is  not present in map.
                return "No";
            }
        }

        if(presentAll == size2){
            return "Yes";
        }

        return"No";
    }

    public static void main(String[] args) {
        long arr1[] = { 11, 1, 13, 21, 3, 7 };
        long arr2[] = { 11, 3, 7, 1 };

        long size1 = arr1.length;
        long size2 = arr2.length;

        // System.out.println(isSubset_BruteForce(arr1, arr2, size1, size2));
        System.out.println(isSubset_Optimized(arr1, arr2, size1, size2));
    }
}