public class JumpGame {
    // Time Complexity :- O()
    // Space Complexity :- O()
    static boolean canJump(int nums[]) {

        // Corner Case
        // if the first element of array is 0 and size of array is greater than 1, it
        // means you cannot reach thye last index.
        // because from index 0, the minimum jumps you can take is 0 i.e., no jump.
        if (nums[0] == 0 && nums.length > 1) {
            return false;
        }

        // if the array only contains a single element, it means you are at the last
        // index.
        if (nums.length == 1) {
            return true;
        }

        // size of array.
        int n = nums.length;

        // needed variables.
        int maxReach = nums[0];

        // traverse through the vector and find the answer.
        for (int i = 1; i < n; i++) {
            // if maxReach having value < i,
            // means we cannot reach the end, return false.
            if (maxReach < i) {
                return false;
            }

            // if maxReach having value >= n-1,
            // means we reached the last index, retun true.
            if (maxReach >= n - 1) {
                return true;
            }

            // update maxReach with maximum reachable index.
            maxReach = Math.max(maxReach, (i + nums[i]));
        }

        return false;
    }

    public static void main(String[] args) {
        int nums[] = { 2, 3, 1, 1, 4 };

        if (canJump(nums)) {
            System.out.println("You reach the end of the array.");
        } else {
            System.out.println("You cannot reach the end of the array.");
        }
    }
}