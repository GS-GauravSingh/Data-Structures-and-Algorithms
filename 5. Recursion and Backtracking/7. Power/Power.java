public class Power {
    /* Approach 1 :- Using loop. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    static int pow(int x, int n) {
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            ans = ans * x;
        }
        return ans;
    }

    /* Approach 2 :- Binary Exponentiation, recursive code. */
    // Time Complexity :- O(log(n))
    // Space Complexity :- O(log(n)), recursive stack space.
    static int binaryExponentiation_Recursive(int x, int n) {
        // Base Condition.
        if (n == 0) {
            // 2^0 = 1.
            return 1;
        }
        if (n == 1) {
            // 2^1 = 2.
            return x;
        }

        // Recursive Case.
        int ans = binaryExponentiation_Recursive(x, n / 2);

        if ((n & 1) == 1) {
            // odd power.
            return ans * ans * x;
        }

        // even power.
        return ans * ans;
    }

    /* Approach 3 :- Iterative code for Binary Exponentiation. */
    // Time Complexity :- O(log(n))
    // Space Complexity :- O(1)
    static int binaryExponentiation_Iterative(int x, int n) {
        int ans = 1;
        while (n != 0) {
            int lastBit = n & 1;
            if (lastBit == 1) {
                // multiply answer with current power of x.
                ans = ans * x;
            }

            // if last bit is 0, increase the power of x.
            x = x * x;

            n = n >> 1;
        }

        return ans;
    }

    public static void main(String[] args) {

        int x = 2;
        int n = 10;

        System.out.println(x + "^" + n + " = " + binaryExponentiation_Iterative(x, n));
    }
}