/*
Given an infinite sorted array consisting 0s and 1s. The problem is to find the index of first ‘1’ in that array. As the array is infinite, therefore it is guaranteed that number ‘1’ will be present in the array.

Example:
Input : arr[] = {0, 0, 1, 1, 1, 1}
Output : 2
*/
public class Index_of_first_1_in_Infinite_Sorted_Binary_Array {
    /* Binary Search Algorithm */
    // Time Complexity :- O(log(n)).
    // Space Complexity :- O(1).
    static int binarySearch(int arr[], int l, int h, int key) {

        // low and high pointers.
        int low = l;
        int high = h;

        // variable to store first occurence of 1.
        int idx = 0;

        // loop (low <= high)
        while (low <= high) {
            // calculating mid.
            int mid = low + (high - low) / 2;

            if (arr[mid] == key) {
                idx = mid;
                high = mid - 1;
            } else if (arr[mid] > key) {
                high = mid - 1;
            } else {
                // arr[mid] < key.
                low = mid + 1;
            }
        }

        // return -1 is key not found.
        return idx;
    }

    static int findHighIdx(int arr[]) {
        int low = 0;
        int high = 1;

        while (arr[high] == 0) {
            low = high;
            high = high * 2;
        }

        return binarySearch(arr, low, high, 1);
    }

    public static void main(String[] args) {
        int[] arr = { 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1 };

        System.out.println("First Occurence of 1 is present at index " + findHighIdx(arr));
    }
}
