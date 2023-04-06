public class Move_Zeroes_To_Right {

    /* Brute Force Approach :- using extra space. */
    // Time Complexity:- O(n), n is size of vectors.
    // Space Complexity:- O(n)
    static void moveZeros_Approach_1(int nums[]) {
        int n = nums.length;

        int ans[] = new int[n];
        int k = 0;
        // first push non-zero elements.
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                ans[k++] = nums[i];
            }
        }

        // then push elements which has value 0.
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
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
    static void moveZeros_Approach_2(int nums[]) {
        // Base Case
        if (nums.length == 0 || nums.length == 1) {
            return;
        }

        // 2 pointers
        int i = 0;
        int j = i + 1;

        while (j < nums.length) {
            if (nums[i] == 0 && nums[j] == 0) {
                // if both are 0, then increment j.
                j++;
            } else if (nums[i] == 0 && nums[j] != 0) {
                // if nums[i] == 0 && nums[j] != 0, then swap(nums[i], nums[j]).
                // and increment both i and j.
                nums[i] = nums[i] ^ nums[j];
                nums[j] = nums[i] ^ nums[j];
                nums[i] = nums[i] ^ nums[j];

                i++;
                j++;
            } else {
                // if both are non-zero elements,
                // then increment both i and j.
                i++;
                j++;
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