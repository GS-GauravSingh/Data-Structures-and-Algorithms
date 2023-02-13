

public class JumpGameTwo {
    static int jump(int nums[])
    {
        // Base Case
        if (nums.length == 1)
        {
            return 0;
        }

        // size of vector.
        int n = nums.length;

        // needed variables.
        int maxReach = 0;
        int jump = 0;
        int lastJumpPos = 0;

        // traverse through the vector and find the answer.
        for (int i = 0; i < n - 1; i++)
        {
            // update maxReach with maximum reachable index.
            maxReach = Math.max(maxReach, i + nums[i]);

            if (lastJumpPos == i)
            {
                lastJumpPos = maxReach;
                jump++;
            }
        }

        return jump;
    }

    public static void main(String[] args) {
        int nums[] = {2, 3, 1, 1, 4};

        System.out.println(jump(nums));
    }
}
