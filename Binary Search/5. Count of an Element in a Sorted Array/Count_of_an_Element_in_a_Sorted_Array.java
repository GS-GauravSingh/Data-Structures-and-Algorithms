
public class Count_of_an_Element_in_a_Sorted_Array {
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

    /*
     * Approach :- Just find the first and last occurence of target.
     */
    // Time Complexity :- O(log(n)).
    // Space Complexity :- O(1).
    static int count(int arr[], int target) {
        // finding the first occurence of target.
        int firstOcc = binarySearch_firstOccurence(arr, target);

        // finding the last occurence of target.
        int lastOcc = binarySearch_lastOccurence(arr, target);

        // number of time target appear = lastOcc - firstOcc + 1;
        int appear = lastOcc - firstOcc + 1;

        // if target is not present. Then return -1.
        if(firstOcc == -1 && lastOcc == -1)
        {
            return - 1;
        }

        // else return ans.
        return appear;
    }

    public static void main(String[] args) {
        int arr[] = { 2, 4, 10, 10, 10, 18, 20 };
        int target = 10;

        System.out.println("Count of " + target + " is " + count(arr, target));
    }
}
