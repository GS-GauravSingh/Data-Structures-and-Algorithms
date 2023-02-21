import java.util.Scanner;

public class FibonacciSeries {
    /* Iterative Function to find nth term of fibonacci series. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    static void fibIterative(int n) {
        // The first term of the Fibonacci series is 0,
        // the second term of the Fibonacci series is 1
        // and the next term of the fibonacci series is the summation of previous 2
        // terms.
        int firstTerm = 0;
        int secondTerm = 1;
        int nextTerm = 0;

        // printing first 2 terms of fibonacci series.
        System.out.print(firstTerm + " " + secondTerm + " ");

        for (int i = 2; i <= n; i++) {
            // the next term of the fibonacci series is the summation of previous 2 terms.
            nextTerm = firstTerm + secondTerm;

            // printing next term.
            System.out.print(nextTerm + " ");

            // update first and second terms.
            firstTerm = secondTerm;
            secondTerm = nextTerm;
        }

        System.out.print("\n" + n + "th term of fibonacci series is " + nextTerm + ".\n");
    }

    /* Recursive Function to find nth term of fibonacci series. */
    // Time Complexity :- O(2^n)
    // Space Complexity :- O(n), recursive stack space.
    static int fibRecursive(int n) {
        // The first term of the Fibonacci series is 0,
        // the second term of the Fibonacci series is 1
        // and the next term of the fibonacci series is the summation of previous 2
        // terms.

        // Base Condition.
        if (n == 0) {
            // The first term of the Fibonacci series is 0.
            return 0;
        }
        if (n == 1) {
            // the second term of the Fibonacci series is 1.
            return 1;
        }

        // Recursive Case.
        // The next term of the fibonacci series is the summation of previous 2 terms.
        int nextTerm = fibRecursive(n - 1) + fibRecursive(n - 2);
        return nextTerm;
    }

    public static void main(String[] args) {

        // taking the value of n.
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        System.out.print("---- Iterative Method Output ----\n");
        fibIterative(n);
        System.out.print("\n---- Recursive Method Output ----\n" + n + "th fibonacci term is " + fibRecursive(n) + ".");

        // closing scanner object.
        sc.close();
    }
}
