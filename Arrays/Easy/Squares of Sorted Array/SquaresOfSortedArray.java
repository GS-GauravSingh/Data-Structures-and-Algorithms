import java.util.Arrays;

public class SquaresOfSortedArray {
    /* Method to print array. */
    static void print(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }

    /* Brute Force Approach. */
    // Time Complexity:- O(n log(n)), n is the size of array.
    // Space Complexity:- O(1)
    static void sortedSquares_Approach_1(int arr[]) {

        // iterate through the array and store the square of each element.
        for (int i = 0; i < arr.length; i++) {
            arr[i] = arr[i] * arr[i];
        }

        // sort the array.
        Arrays.sort(arr);

        // printing.
        print(arr);
    }

    /* Optimized Approach. */
    // Time Complexity:- O(n), n is the size of vector.
    // Space Complexity:- O(1)
    static void sortedSquares_Approach_2(int arr[]) {
        // Step 1:- Since we need to put squares in result array, we can consider that
        // all numbers are positive.
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] < 0) {
                arr[i] = -arr[i];
            }
        }

        // Step 2:- use 2 pointer apporach.
        int n = arr.length;
        int start = 0, end = n - 1;

        // array to store answer.
        int ans[] = new int[n];
        int k = n - 1;

        while (k >= 0) {
            if (arr[start] > arr[end]) {
                ans[k--] = arr[start] * arr[start];
                start++;
            } else {
                ans[k--] = arr[end] * arr[end];
                end--;

            }
        }

        // printing.
        print(ans);

    }

    public static void main(String[] args) {
        int arr[] = { -4, -1, 0, 3, 10 };
        // sortedSquares_Approach_1(arr);
        sortedSquares_Approach_2(arr);
    }
}
