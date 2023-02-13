import java.util.Arrays;

public class Kth_max_and_min_element {
    /*
     * Function to find kth minimum Element of the Array. Tc:- O(n log(n)), SC:-
     * O(1).
     */
    static int findKthMinimum(int arr[], int k) {
        Arrays.sort(arr);
        return arr[k - 1];
    }

    /*
     * Function to find kth maximum Element of the Array. Tc:- O(n log(n)), SC:-
     * O(1).
     */
    static int findKthMaximum(int arr[], int k) {
        Arrays.sort(arr);
        return arr[arr.length - k];
    }

    public static void main(String[] args) {
        int[] arr = { 10, 20, 3, 2, 6, 59, 87, 1 };
        int k = 2;

        System.out.println("Kth Maximum Element is " + findKthMaximum(arr, k));
        System.out.println("Kth Minimum Element is " + findKthMinimum(arr, k));
    }
}
