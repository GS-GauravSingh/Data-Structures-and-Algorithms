
public class Suffix_Sum {
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    static void prefixSum(int arr[]) {
        /*
         * Suffix sum is a cumulative sum of array elements in reverse order.
         * Example :
         * arr = {1,2,3,4}
         * Suffix Sum array = {4+3+2+1, 4+3+2, 4+3, 4 } => {1, 3, 6, 10}
         */

        int suffixSumArr[] = new int[arr.length];
        int k = arr.length - 1;

        int sum = 0;
        for (int i = arr.length - 1; i >= 0; i--) {
            sum += arr[i];
            suffixSumArr[k--] = sum;
        }

        // printing.
        System.out.print("Original array => ");
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }

        System.out.print("\nSuffix sum array => ");
        for (int i = 0; i < suffixSumArr.length; i++) {
            System.out.print(suffixSumArr[i] + " ");

        }

    }

    public static void main(String[] args) {

        int arr[] = { 1, 2, 3, 4 };

        prefixSum(arr);
    }
}
