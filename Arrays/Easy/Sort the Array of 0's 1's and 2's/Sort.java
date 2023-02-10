import java.util.*;

public class Sort {
    /* Brute Force Approach:- Use Sorting. TC:- O(n log(n)), SC:- O(1) */
    static void sortArray_Approach_1(int arr[])
    {

        // using inbuild sort method.
        Arrays.sort(arr);
    }

    /* Better Approach:- use counting. TC:- O(n), SC:- O(1) */
    static void sortArray_Approach_2(int arr[])
    {

        // count the frequency of 0's, 1's and 2's.
        int zero = 0;
        int one = 0;
        int two = 0;

        for (int i = 0; i < arr.length; i++)
        {
            if (arr[i] == 0)
            {
                zero++;
            }
            else if (arr[i] == 1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }

        // In 2nd traversal of array, we will now over write the first ‘a’ indices / positions in array with ’0’, the next ‘b’ with ‘1’ and the remaining ‘c’ with ‘2’.
        for (int i = 0; i < arr.length; i++)
        {
            if (zero > 0)
            {
                arr[i] = 0;
                zero--;
            }
            else if (one > 0)
            {
                arr[i] = 1;
                one--;
            }
            else
            {
                arr[i] = 2;
                two--;
            }
        }
    }

    /*
     * Optimized Approach:- Using Dutch National Flag Algorithm.
     * Time Complexity:- O(n)
     * Space Complexity:- O(1)
     */
    static void sortArray_Approach_3(int arr[]) {

        int low = 0, mid = 0, high = arr.length - 1;
        while (mid < high) {
            if (arr[mid] == 0) {
                // swap arr[low], arr[mid].
                arr[low] = arr[low] ^ arr[mid];
                arr[mid] = arr[low] ^ arr[mid];
                arr[low] = arr[low] ^ arr[mid];

                // update pointers
                low++;
                mid++;
            } else if (arr[mid] == 1) {
                mid++;
            } else {
                // arr[mid] == 2.
                // swap(arr[mid], arr[high]);
                arr[mid] = arr[mid] ^ arr[high];
                arr[high] = arr[mid] ^ arr[high];
                arr[mid] = arr[mid] ^ arr[high];

                high--;
            }
        }
    }

    /* Method to print array. */
    static void print(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();

    }

    public static void main(String[] args) {
        int arr[] = { 0, 2, 1, 2, 0 };

        // sortArray_Approach_1(arr);
        // sortArray_Approach_2(arr);
        sortArray_Approach_3(arr);

        print(arr);


    }
}
