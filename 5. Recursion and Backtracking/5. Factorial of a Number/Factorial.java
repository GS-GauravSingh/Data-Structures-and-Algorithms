import java.util.Scanner;

public class Factorial {

    /* Iterative Function to find a factorial. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    public static int factorialIterative(int n) {

        int factorial = 1;
        for (int i = 1; i <= n; i++) {
            factorial *= i;
        }

        return factorial;

    }

    /* Recursive Function to find a factorial. */
    // Time Complexity :- O()
    // Space Complexity :- O()
    public static int factorialRecursive(int n) {

        // Base Condition.
        if (n == 0 || n == 1) {
            return 1;
        }

        // Recursive Case.
        return n * factorialRecursive(n - 1);

    }

    public static void main(String[] args) {

        // taking the value of n.
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        System.out.println("(Iterative Method) Factorial of " + n + " is : " + factorialIterative(n));
        System.out.println("(Recursive Method) Factorial of " + n + " is : " + factorialRecursive(n));

        // closing the scanner object.
        sc.close();
    }
}