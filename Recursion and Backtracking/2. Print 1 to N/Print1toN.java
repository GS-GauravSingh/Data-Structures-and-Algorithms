
import java.util.Scanner;


public class Print1toN {
    /* Iterative Function to print natural numbers from 1 to n. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    public static void print1toN_Iterative(int n) {

        for (int i = 1; i <= n; i++) {
            System.out.print(i + " ");
        }
        System.out.println();

    }

    /* Recursive Function to print natural numbers from 1 to n. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n), recursive stack space.
    public static void print1toN_Recursive(int n) {

        // Base Condition.
        if (n == 0) {
            return;
        }

        // Recursive Case.
        // first we ge to the base case and while returning back from the base case,
        // we print the value of n.
        print1toN_Recursive(n - 1);

        // Backtracking Step (While returning back from the base case).
        System.out.print(n + " ");

    }

    public static void main(String[] args) {

        // taking the value of n.
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        System.out.print("Iteartive Method Output :- ");
        print1toN_Iterative(n);

        System.out.print("Recursive Method Output :- ");
        print1toN_Recursive(n);


        // closing the scanner object.
        sc.close();

    }
}
