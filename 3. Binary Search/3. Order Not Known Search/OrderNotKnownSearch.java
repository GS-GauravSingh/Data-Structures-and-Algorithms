public class OrderNotKnownSearch {
    /* Binary Search Algorithm for array which is sorted in decreasing order. */
    // Time Complexity :- O(log(n)).
    // Space Complexity :- O(1).
    static int binarySearch_AscendingOrder(int arr[], int key) {
        // size of array.
        int n = arr.length;

        // low and high pointers.
        int low = 0;
        int high = n - 1;

        // loop (low <= high)
        while (low <= high) {
            // calculating mid.
            int mid = low + (high - low) / 2;

            if (arr[mid] == key) {
                return mid;
            } else if (arr[mid] > key) {
                high = mid - 1;
            } else {
                // arr[mid] < key.
                low = mid + 1;
            }
        }

        // return -1 is key not found.
        return -1;
    }

    /* Binary Search Algorithm for array which is sorted in decreasing order. */
    // Time Complexity :- O(log(n)), for binary search.
    // Space Complexity :- O(1)
    static int binarySearch_DescendingOrder(int arr[], int key) {
        // size of array.
        int n = arr.length;

        // low and high pointers.
        int low = 0;
        int high = n - 1;

        // loop (low <= high)
        while (low <= high) {
            // calculating mid.
            int mid = low + (high - low) / 2;

            if (arr[mid] == key) {
                return mid;
            } else if (arr[mid] > key) {
                // since the array is sorted in decreasing order, and if the middle element is
                // greater than key.
                // So, smaller element are present at right half.
                low = mid + 1;
            } else {
                // arr[mid] < key.

                // since the array is sorted in decreasing order, and if the middle element is
                // less than key.
                // So, larger element are present at left half.
                high = mid - 1;
            }
        }

        // return -1 is key not found.
        return -1;
    }

    /* Question Main Method. */
    // Time Complexity :- O(log(n)), for binary search.
    // Space Complexity :- O(1)
    static int search(int arr[], int target) {
        // size of array.
        int n = arr.length;

        // if size of arrays is 1.
        if (n == 1) {
            if (arr[0] == target) {
                return 0;
            } else {
                return -1;
            }
        }

        // if arr[0] < arr[1], means array is sorted in ascending order.
        if (arr[0] < arr[1]) {
            return binarySearch_AscendingOrder(arr, target);
        } else {
            // if arr[0] > arr[1], means array is sorted in descending order.
            return binarySearch_DescendingOrder(arr, target);
        }
    }

    public static void main(String[] args) {
        int[] arr1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // ascending order
        // int[] arr2 = { 9, 8, 7, 6, 5, 4, 3, 2, 1 }; // descending order
        int key = 7;

        int idx1 = search(arr1, key);
        // int idx2 = search(arr2, key);

        if (idx1 != -1) {
            System.out.println("Key found at index " + idx1 + ".");
        } else {
            // key not found.
            System.out.println("Key not found.");
        }

    }
}
