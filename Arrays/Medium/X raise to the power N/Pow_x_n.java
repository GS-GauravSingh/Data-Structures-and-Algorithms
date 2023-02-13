
public class Pow_x_n {
    /*
     * Brute Force Approach :- using for loop, run a loop from 1 to n and multiply
     * x, n times.
     */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    static int pow_Approach_1(int x, int n) {
        // i am taking abs(n) because, it will handle the -ve value of n.
        int ans = 1;
        for (int i = 0; i < Math.abs(n); i++) {
            ans *= x;
        }

        // If power is negative, ex :- 2^-4
        // answer is (1/(2^4)).
        if (n < 0) {
            ans = 1 / ans;
        }

        return ans;

    }

    /* Optimized Approach :- Binary Exponentiation. */
    // Time Complexity :- O(log(n)), where n is the power.
    // Space Complexity :- O(log(n)), recursive stack space.
    static int binaryExponentiation_Recursive(int x, int n) {
        // Base Case
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }

        // Recursive Case
        int ans = binaryExponentiation_Recursive(x, n / 2);

        // if n is odd.
        if ((n & 1) == 1) {
            return ans * ans * x;
        }

        // if n is even.
        return ans * ans;
    }

    // Time Complexity :- O(log(n)), where n is the power.
    // Space Complexity :- O(1).
    static int binaryExponentiation_Iterative(int x, int n) {
        // Base Case
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }

        // Iterative Case
        int power = n;
        int ans = 1;

        while (power != 0) {
            if ((power & 1) == 1) {
                ans = ans * x;
            }

            ans = ans * ans;

            power = power >> 1;
        }

        return ans;
    }

    static int myPow_Optimized(int x, int n) {
        // int ans = binaryExponentiation_Recursive(x, Math.abs(n));
        int ans = binaryExponentiation_Iterative(x, Math.abs(n));
        if (n < 0) {
            ans = 1 / ans;
        }
        return ans;
    }

    public static void main(String[] args) {
        int x = 2;
        int n = 10;

        System.out.println(pow_Approach_1(x, n));
        System.out.println(myPow_Optimized(x, n));
    }
}
