/*
Question :-

Given a sorted array and a value x, the ceiling of x is the smallest element in array greater than or equal to x, and the floor is the greatest element smaller than or equal to x. Assume than the array is sorted in non-decreasing order. Write efficient functions to find floor and ceiling of x.

Examples :

For example, let the input array be {1, 2, 8, 10, 10, 12, 19}
For x = 0:    floor doesn't exist in array,  ceil  = 1
For x = 1:    floor  = 1,  ceil  = 1
For x = 5:    floor  = 2,  ceil  = 8
For x = 20:   floor  = 19,  ceil doesn't exist in array
 */

public class Find_Ceil_of_an_Element_in_a_Sorted_Array {
    /* Binary Search Algorithm */
    // Time Complexity :- O(log(n)).
    // Space Complexity :- O(1).
    static int binarySearch(int[] arr, int x) {
        // size of array.
        int n = arr.length;

        // low and high pointers.
        int low = 0;
        int high = n - 1;

        // if x is present in the array, then simply return the index of x.
        // But if it is not present, we have to return the smallest value which is
        // greater than x.

        int ans = -1;

        // loop (low <= high)
        while (low <= high) {
            // calculating mid.
            int mid = low + (high - low) / 2;

            // if x is found, then simply return the index of x.
            if (arr[mid] == x) {
                return mid;
            } else if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            } else {
                // arr[mid] < x.
                low = mid + 1;
            }
        }

        // return ans;
        return ans;
    }

    public static void main(String[] args) {
        int arr[] = { 1, 2, 3, 4, 8, 10, 12, 19 };
        int x = 5;

        int idx = binarySearch(arr, x);
        System.out.println("Ceil value of " + x + " is present at index " + idx);
    }
}
