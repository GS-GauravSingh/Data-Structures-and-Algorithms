import java.util.*;

public class Sum_of_N_Natural_Numbers {

    /* Find sum of n natural numbers. */
    // Time Complexity :- O(1)
    // Space Complexity :- O(1)
    public static int sumofNaturalNumbers_Using_Formula(int n) {

        // Sum of N natural Numbers = (n*(n+1))/2;
        return (n * (n + 1)) / 2;
    }

    /* Iterative Function to find sum of n natural numbers. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    public static int sumofNaturalNumbers_Iterative(int n) {

        int sum = 0;
        for (int i = 0; i <= n; i++) {
            sum += i;
        }

        return sum;
    }

    /* Recursive Function to find sum of n natural numbers. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n), recursive stack space.
    public static int sumofNaturalNumbers_Recursive(int n) {

        // Base Condition.
        if (n == 0) {
            return 0;
        }

        // Recursive Case.
        return n + sumofNaturalNumbers_Recursive(n - 1);

    }

    public static void main(String[] args) {
        // taking the value of n.
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        System.out.println("(Using Formula (n * (n+1)/2), Sum of N Natural Number is " + sumofNaturalNumbers_Using_Formula(n));
        System.out.println("(Iterative Method), Sum of N Natural Number is " + sumofNaturalNumbers_Iterative(n));
        System.out.println("(Recursive Method), Sum of N Natural Number is " + sumofNaturalNumbers_Recursive(n));

        // closing the scanner object.
        sc.close();
    }
}
