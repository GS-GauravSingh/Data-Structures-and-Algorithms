
public class NextPermutation {
    // So, In Java there is no in-built method to find the next permutation.

    /*
     * Approach :- Algorithm,
     * 
     * Step 1:- traverse from the back and find index element a[i] i.e., a[i] <
     * a[i+1].
     * Step 2:- if no such element is found it means the given array is sorted in
     * descending order. In this case your next permutation is the reverse of the
     * original array. So, reverse the array and return ans.
     * Step 3:- If there is an element a[i] exists such that a[i] < a[i+1]. In this
     * case, again traverse form back and find the element which if greater than
     * a[i].
     * Step 4:- swap(a[i], element which is greater than a[i]);
     * Step 5:- in last step, reverse that array from index, index of(a[i]) to end.
     * 
     * 
     * Time Complexity:- O(n)
     * Space Complexity:- O(1)
     */

    static void reverse(int nums[], int i, int j) {
        int start = i, end = j;

        while (start < end) {
            // swap nums[start], nums[end];
            nums[start] = nums[start] ^ nums[end];
            nums[end] = nums[start] ^ nums[end];
            nums[start] = nums[start] ^ nums[end];
        }
    }

    static void nextPermutation(int nums[]) {
        // Step 1:- traverse from the back and find index element a[i] i.e., a[i] <
        // a[i+1].
        int n = nums.length;
        int index1 = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                index1 = i;
                break;
            }
        }

        // Step 2:- if no such element is found it means the given array is sorted in
        // descending order. In this case your next permutation is the reverse of the
        // original array. So, reverse the array and return ans.
        if (index1 < 0) {
            reverse(nums, 0, nums.length - 1);
        } else {

            // Step 3:- If there is an element a[i] exists such that a[i] < a[i+1]. In this
            // case, again traverse form back and find the element which if greater than
            // a[i].
            int index2 = -1;
            for (int i = n - 1; i > index1; i--) {
                if (nums[i] > nums[index1]) {
                    index2 = i;
                    break;
                }
            }

            // Step 4:- swap(a[i], element which is greater than a[i]);
            nums[index1] = nums[index1] ^ nums[index2];
            nums[index2] = nums[index1] ^ nums[index2];
            nums[index1] = nums[index1] ^ nums[index2];

            // Step 5:- in last step, reverse that array from index, index of(a[i]) to end.
            reverse(nums, index1 + 1, nums.length - 1);
        }
    }

    public static void main(String[] args) {
        int nums[] = { 1, 2, 3 };

        nextPermutation(nums);

        for (int x : nums) {
            System.out.print(x + " ");
        }

    }
}
