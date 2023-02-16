/*
About Binary Search :-

Binary Search is a searching algorithm used in a sorted arrayb y repeatedly dividing the search interval in half. The idea of binary search is to use the information that the array is sorted.

Time Complexity of Binary Search is O(log(n)).
Space Complexity of Binary Search is O(1).

Binary Search Algorithm :-
1. Initialize 2 pointer, low and high, low will be at 0 index and high at last index (n-1).
2. Run a loop till (low <= high).
3. Find the middle element.
4. Compare middle element with the given key,
5. If the key matches with the middle element, means key is found, return the index of the middle element.
6. If the middle element does not match the key, there can be 2 cases,
    1. middle element is greater than key,
        ==> If middle element is greater than key, then start searching for key on left half (mid - 1). Set high pointer to mid - 1.
        ==> Since the array is sorted in increasing order and if the middle element is greater than key, it means all the elements after mid are also greater than key. So, there is no point to search for key on right half. That's why we move to left half.

    2. middle element is less than key
        ==> If middle element is less than key, then start searching for key on right half (mid + 1). Set low pointer to mid + 1.
        ==> Since the array is sorted in increasing order and if the middle element is less than key, it means all the elements before mid are also lesser than key. So, there is no point to search for key on left half. That's why we move to right half.

7. return -1 if key not found.


** For calculation of Middle element you can below 2 methods, **

Method 1 :-  int mid = (low + high) / 2; // this will give integer overflow for larger size of array.

Method 2 :-  int mid = low + (high - low) / 2; // this will work perfectly for larger size of array.

*/

public class BinarySearch {
    /* Binary Search Algorithm */
    // Time Complexity :- O(log(n)).
    // Space Complexity :- O(1).
    static int binarySearch(int arr[], int key) {
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

    public static void main(String[] args) {
        int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        int target = 5;

        int idx = binarySearch(arr, target);

        if (idx != -1) {
            System.out.println("Key found at index " + idx + ".");
        } else {
            // key not found.
            System.out.println("Key not found.");
        }
    }

}