
public class Find_Floor_of_an_Element_in_a_Sorted_Array {
    /* Binary Search Algorithm */
    // Time Complexity :- O(log(n)).
    // Space Complexity :- O(1).
    static int binarySearch(int[] arr, int x) {
        // size of array.
        int n = arr.length;

        // low and high pointers.
        int low = 0;
        int high = n - 1;

        // if x is present in the array, then simply return the index of x.
        // But if it is not present, we have to return the value which is smaller that
        // or equal to x.

        // variable to store value which is smaller that or equal to x.
        int ans = -1;

        // loop (low <= high)
        while (low <= high) {
            // calculating mid.
            int mid = low + (high - low) / 2;

            // if x is found, then simply return the index of x.
            if (arr[mid] == x) {
                return mid;
            } else if (arr[mid] > x) {
                high = mid - 1;
            } else {
                // arr[mid] < x.
                // But if it is not present, we have to return the value which is smaller that
                // or equal to x.

                // store the smaller value.
                ans = mid;

                low = mid + 1;
            }
        }

        // return ans;
        return ans;
    }

    public static void main(String[] args) {
        int arr[] = { 1, 2, 3, 4, 8, 10, 12, 19 };
        int x = 19;

        int idx =  binarySearch(arr, x);
        System.out.println("Floor value of " + x + " is present at index " + idx);
    }
}
