
public class Prefix_Sum {
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    static void prefixSum(int arr[]) {
        /*
         * Prefix sum is a cumulative sum of array elements.
         * Example :
         * arr = {1,2,3,4}
         * Prefix Sum array = {1, 1+2, 1+2+3, 1+2+3+4 } => {1, 3, 6, 10}
         */

        int prefixSumArr[] = new int[arr.length];
        int k = 0;

        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            prefixSumArr[k++] = sum;
        }

        // printing.
        System.out.print("Original array => ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }

        System.out.print("\nPrefix sum array => ");
        for (int i = 0; i < prefixSumArr.length; i++) {
            System.out.print(prefixSumArr[i] + " ");

        }

    }

    public static void main(String[] args) {

        int arr[] = { 1, 2, 3, 4 };

        prefixSum(arr);
    }
}
