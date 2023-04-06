/*
Question :-
An unsorted array of size n is given. write a program to find the median of an array. The median of array is the middle element of a sorted array in case of odd number of elements in an array and average of middle two elements when the number of elements in an array is even.
*/

import java.util.*;

public class Find_Median {

    // Time complexity :- O(n log(n))
    // Space complexity :- O(1)
    static int findMedian(int arr[]) {
        // size of array.
        int n = arr.length;

        // sort the given array.
        Arrays.sort(arr);

        // odd number of elements.
        int median = 0;
        if ((n & 1) == 1) {
            // median = (arr[n/2] + arr[n/2+1])/2;
            median = (arr[n / 2] + arr[n / 2 + 1]) / 2;
        } else {
            // even number of elements.
            // median = arr[n/2];
            median = arr[n / 2];
        }

        return median;
    }

    public static void main(String[] args) {

        int arr[] = { 1, 5, 2, 3, 9, 12, 6 };

        System.out.println("Median is : " + findMedian(arr));
    }
}
