/*
Question :-
Given an array arr[] of size N having distinct numbers sorted in increasing order and the array has been right rotated (i.e, the last element will be cyclically shifted to the starting position of the array) k number of times, the task is to find the value of k.

Examples:  

Input: arr[] = {15, 18, 2, 3, 6, 12}
Output: 2
Explanation: Initial array must be {2, 3, 6, 12, 15, 18}. 
We get the given array after rotating the initial array twice.

Input: arr[] = {7, 9, 11, 12, 5}
Output: 4
 */
public class Number_of_Times_a_Sorted_Array_is_Rotated {
    /* Modified Binary Search Algorithm */
    // Time Complexity :- O(log(n)).
    // Space Complexity :- O(1).
    static int binarySearch(int arr[]) {
        // size of array.
        int n = arr.length;

        // low and high pointers.
        int low = 0;
        int high = n - 1;

        // variable to store rotation count.
        int k = 0;

        // loop (low <= high)
        while (low <= high) {
            // calculating mid.
            int mid = low + (high - low) / 2;

            // left half
            // if arr[low] <= arr[mid], it means, left half is sorted.
            if (arr[low] <= arr[mid]) {
                if (arr[mid + 1] < arr[mid]) {
                    k = mid + 1; // +1 is for 1-based indexing.
                    break;
                } else {
                    low = mid + 1;
                }
            }
            // right half.
            // if arr[mid] <= arr[high], it means, right half is sorted.
            else if (arr[mid] <= arr[high]) {
                if (arr[mid] < arr[mid - 1]) {
                    k = mid;
                    break;
                } else {
                    high = mid - 1;
                }
            }
        }

        // if k == n, it means array is sorted in increasing order.
        if (k == n) {
            return 0;
        }

        return k;
    }

    /* Another apporach is, value of k = index of minimum element. */

    /* Using Modified Binary Search. See the code above. */
    static int countRotations(int arr[]) {
        return binarySearch(arr);
    }

    public static void main(String[] args) {
        int arr[] = { 11, 12, 15, 18, 2, 5, 6, 8 };
        System.out.println(countRotations(arr));
    }
}
