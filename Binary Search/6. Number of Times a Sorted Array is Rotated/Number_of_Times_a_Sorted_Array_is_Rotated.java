
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

    /* Another apporach is, You can find the index of minimum element. */

    /* Using Modified Binary Search. See the code above. */
    static int countRotations(int arr[]) {
        return binarySearch(arr);
    }

    public static void main(String[] args) {
        int arr[] = { 11, 12, 15, 18, 2, 5, 6, 8 };
        System.out.println(countRotations(arr));
    }
}
