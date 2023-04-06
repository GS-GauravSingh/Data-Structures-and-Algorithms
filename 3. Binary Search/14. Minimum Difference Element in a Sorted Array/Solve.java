
public class Solve {
    /* Binary Search Algorithm */
    // Time Complexity :- O(log(n)).
    // Space Complexity :- O(1).
    static int binarySearch(int arr[], int key) {
        // size of array.
        int n = arr.length;

        // low and high pointers.
        int low = 0;
        int high = n - 1;

        int diff = Integer.MAX_VALUE;
        int ans = 0;

        // loop (low <= high)
        while (low <= high) {
            // calculating mid.
            int mid = low + (high - low) / 2;

            if (arr[mid] == key) {
                return mid;
            } else {
                if (Math.abs(arr[mid] - key) < diff) {
                    diff = Math.abs(arr[mid] - key);
                    ans = arr[mid];
                }
            }

            if (arr[mid] > key) {
                high = mid - 1;
            } else {
                // arr[mid] < key.
                low = mid + 1;
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        int arr[] = { 1, 3, 8, 10, 15 };
        int key = 12;

        System.out.println(binarySearch(arr, key));
    }
}
