public class Move_Zeroes_To_Left {

    /* Brute Force Approach :- using extra space. */
    // Time Complexity:- O(n), n is size of vectors.
    // Space Complexity:- O(n)
    static void moveZeros_Approach_1(int nums[]) {
        int n = nums.length;

        int ans[] = new int[n];
        int k = 0;
        // first push elements which has value 0.
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                ans[k++] = nums[i];
            }
        }

        // then push non-zero elements.
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                ans[k++] = nums[i];

            }
        }

        // update original vector.
        for (int i = 0; i < n; i++) {
            nums[i] = ans[i];
        }
    }

    /* Optimized Approach. */
    // Time Complexity:- O(n), n is size of vector.
    // Space Complexity:- O(1)
    static void moveZeros_Approach_2(int arr[]) {
        int n = arr.length;
        int i = n - 1;
        int j = i - 1;

        while (j >= 0) {
            // if both are 0's, decrement j.
            if (arr[i] == 0 && arr[j] == 0) {
                j--;
            } else if (arr[i] == 0 && arr[j] != 0) {
                // if arr[i] == 0 and arr[j] != 0, than swap(arr[i], arr[j]) and decrement both.
                arr[i] = arr[i] ^ arr[j];
                arr[j] = arr[i] ^ arr[j];
                arr[i] = arr[i] ^ arr[j];

                i--;
                j--;
            } else {
                // if both are non-zeros elements, than decrement both.
                i--;
                j--;
            }
        }
    }

    public static void main(String[] args) {
        int nums[] = { 0, 1, 0, 3, 12 };

        moveZeros_Approach_2(nums);

        for (int x : nums) {
            System.out.print(x + " ");
        }
    }
}