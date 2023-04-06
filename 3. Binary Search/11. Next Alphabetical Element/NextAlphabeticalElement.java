/*
Question :-
Given an array of letters sorted in ascending order, find the smallest letter in the the array which is greater than a given key letter.
*/
public class NextAlphabeticalElement {
    /* Binary Search Algorithm */
    // Time Complexity :- O(log(n)).
    // Space Complexity :- O(1).
    static int binarySearch(char[] arr, int x) {
        // size of array.
        int n = arr.length;

        // low and high pointers.
        int low = 0;
        int high = n - 1;

        // we have to return the next character after x in alphabetical order.
        int ans = -1;

        // loop (low <= high)
        while (low <= high) {
            // calculating mid.
            int mid = low + (high - low) / 2;

            // if x is found, then simply return the index of x.
            if (arr[mid] == x) {
                return (mid + 1 < n) ? mid + 1 : mid;
            } else if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            } else {
                // arr[mid] < x.
                low = mid + 1;
            }
        }

        // return ans;
        return ans;
    }

    public static void main(String[] args) {
        char arr[] = { 'a', 'c', 'e', 'f' };
        char key = 'a';

        int idx = binarySearch(arr, key);
        System.out.println("Next Character after " + key + " is present at index " + idx);
    }
}
