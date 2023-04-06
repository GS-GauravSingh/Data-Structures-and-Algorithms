
public class Find_Pivot_Index {
    /* Approach 1 :- using prefix and suffix array. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n)
    static int pivotIndex_Approach_1(int[] nums) {

        // size of array.
        int n = nums.length;

        // prefix array
        int prefix[] = new int[n];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            prefix[i] = sum;
        }

        // suffix array
        sum = 0;
        int suffix[] = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            sum += nums[i];
            suffix[i] = sum;
        }

        // corner cases.
        if (suffix[1] == 0) {
            return 0;
        }
        if (prefix[n - 2] == 0) {
            return n - 1;
        }

        // finding index of pivot elemnet.
        for (int i = 1; i < n - 1; i++) {
            if (prefix[i - 1] == suffix[i + 1]) {
                return i;
            }
        }
        return -1;
    }

    /* Approach 2 :- optimizing above approach. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    static int pivotIndex_Approach_2(int nums[]) {

        // size of array.
        int n = nums.length;

        // Base Case
        if (n == 1) {
            return 0;
        }

        // calculate the sum of entire array.
        int prefixSum = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
        }

        // intialize 2 pointers, leftSum = 0, and rightSum = prefixSum.
        int leftSum = 0;
        int rightSum = prefixSum;

        for (int i = 0; i < n; i++) {
            // remove the current element.
            rightSum = rightSum - nums[i];

            // check if leftSum == right sum or not.
            if (leftSum == rightSum) {
                // if both are equal, return index pivot element.
                return i;
            }

            // add current element to leftSum.
            leftSum = leftSum + nums[i];
        }

        return -1;
    }

    public static void main(String[] args) {

        int nums[] = { 1, 7, 3, 6, 5, 6 };

        System.out.println("Pivot element index is : " + pivotIndex_Approach_1(nums));
        System.out.println("Pivot element index is : " + pivotIndex_Approach_2(nums));
    }
}
