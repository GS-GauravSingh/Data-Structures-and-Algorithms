/*
Question :-
Given a sorted array arr[] with possibly duplicate elements, the task is to find indexes of the first and last occurrences of an element x in the given array.

Examples:

Input : arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125}, x = 5
Output : First Occurrence = 2
              Last Occurrence = 5
*/
public class First_and_Last_Occurence_of_an_Element {
    /* Binary Search Algorithm for find first occurence of an element. */
    // Time Complexity :- O(n log(n))
    // Space Complexity :- O(1)
    static int binarySearch_firstOccurence(int arr[], int target) {
        // size of array.
        int n = arr.length;

        // low and high pointers.
        int low = 0;
        int high = n - 1;

        // variable to store first occurence of traget.
        int firstOcc = -1;

        // loop (low <= high)
        while (low <= high) {
            // calculating mid.
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                // if target is found, store it's index because it may possible that this is the
                // first occurence of traget.
                firstOcc = mid;

                // first occurence is always present at the left half of array..
                high = mid - 1;
            } else if (arr[mid] > target) {
                high = mid - 1;
            } else {
                // arr[mid] < target.
                low = mid + 1;
            }
        }

        // return first occurence.
        return firstOcc;
    }

    /* Binary Search Algorithm for find last occurence of an element. */
    // Time Complexity :- O(n log(n))
    // Space Complexity :- O(1)
    static int binarySearch_lastOccurence(int arr[], int target) {
        // size of array.
        int n = arr.length;

        // low and high pointers.
        int low = 0;
        int high = n - 1;

        // variable to store last occurence of traget.
        int lastOcc = -1;

        // loop (low <= high)
        while (low <= high) {
            // calculating mid.
            int mid = low + (high - low) / 2;

            if (arr[mid] == target) {
                // if target is found, store it's index because it may possible that this is the
                // last occurence of traget.
                lastOcc = mid;

                // if this is not the last occurence of traget, then last occurence is always
                // present at the right half of array.
                low = mid + 1;
            } else if (arr[mid] > target) {
                high = mid - 1;
            } else {
                // arr[mid] < target.
                low = mid + 1;
            }
        }

        // return last occurence.
        return lastOcc;
    }

    public static void main(String[] args) {

        int arr[] = { 2, 4, 10, 10, 10, 18, 20 };
        int target = 10;

        System.out.println(
                "First Occurence of " + target + " is present at index " + binarySearch_firstOccurence(arr, target));
        System.out.println(
                "Last Occurence of " + target + " is present at index " + binarySearch_lastOccurence(arr, target));
    }
}
