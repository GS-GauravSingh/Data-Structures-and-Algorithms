
import java.util.Scanner;

public class PrintNto1 {
    /* Iterative Function to print natural numbers from n to 1. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    public static void printNto1_Iterative(int n) {

        for (int i = n; i >= 1; i--) {
            System.out.print(i + " ");
        }
        System.out.println();

    }

    /* Recursive Function to print natural numbers from n to 1. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(n), recursive stack space.
    public static void printNto1_Recursive(int n) {

        // Base Condition.
        if (n == 0) {
            return;
        }

        // Recursive Case.
        // print the value of n and move forward towards the base case.
        System.out.print(n + " ");

        // recursive call.
        printNto1_Recursive(n - 1);

    }

    public static void main(String[] args) {

        // taking the value of n.
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        System.out.print("Iteartive Method Output :- ");
        printNto1_Iterative(n);

        System.out.print("Recursive Method Output :- ");
        printNto1_Recursive(n);
        
        // closing the scanner object.
        sc.close();

    }
}
