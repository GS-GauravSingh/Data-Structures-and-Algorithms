
public class ReverseArray {

    /* Approach 1 :- Using 2 pointers. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    static void reverseIterative(int arr[]) {
        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {

            // swapping.
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            // move pointers.
            start++;
            end--;

        }
    }

    /* Approach 1 recursive code. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n), recursive stack space.
    static void reverseRecursive(int arr[], int start, int end) {
        // Base Condition.
        if (start >= end) {
            return;
        }

        // Recursive Case.
        // swapping.
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // recursive call.
        reverseRecursive(arr, start + 1, end - 1);
    }

    /* Method to print array. */
    static void print(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");

        }
        System.out.println(); // new line.
    }

    public static void main(String[] args) {
        int arr[] = { 1, 2, 3, 4, 5, 6, 7 };

        reverseIterative(arr);
        print(arr);
        reverseRecursive(arr, 0, arr.length - 1);
        print(arr);
    }
}
