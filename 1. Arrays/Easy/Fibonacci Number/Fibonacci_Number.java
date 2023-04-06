
public class Fibonacci_Number {

    static int fib(int n) {
        // Recurrence relation,
        // F0 = 0, F1 = 1, and Fn = Fn-1 + Fn-2.

        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }

        int term1 = 0;
        int term2 = 1;
        int term3 = 0;

        // printing first 2 terms.
        System.out.print(term1 + " " + term2 + " ");

        for (int i = 2; i <= n; i++) {
            // eacn n term is the summation of previous 2 terms.
            term3 = term1 + term2;

            // update term1 and term2.
            term1 = term2;
            term2 = term3;

            // print fibonacci series.
            System.out.print(term3 + " ");
        }

        return term3;
    }

    public static void main(String[] args) {
        int n = 10;

        System.out.print("\n" + n + "th fibonacci term is " + fib(n));
    }
}
