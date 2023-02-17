
public class Search_in_a_Infinite_Sorted_Array {

     /* Binary Search Algorithm */
    // Time Complexity :- O(log(n)).
    // Space Complexity :- O(1).
    static int binarySearch(int arr[], int l,int h, int key)
    {

        // low and high pointers.
        int low = l;
        int high = h;

        // loop (low <= high)
        while (low <= high)
        {
            // calculating mid.
            int mid = low + (high - low) / 2;

            if (arr[mid] == key)
            {
                return mid;
            }
            else if (arr[mid] > key)
            {
                high = mid - 1;
            }
            else
            {
                // arr[mid] < key.
                low = mid + 1;
            }
        }

        // return -1 is key not found.
        return -1;
    }

    static int findPos(int arr[], int key)
    {
        int low = 0;
        int high = 1;

        while (key > arr[high])
        {
            low = high;
            high = high * 2;
        }

        return binarySearch(arr, low, high, key);
    }
    public static void main(String[] args) {

        int arr[] = { 1, 2, 3, 4, 5, 6, 8, 9, 10, 14, 16, 18, 19, 20, 25, 28, 30, 35, 38, 39, 40, 41, 42, 43, 45, 46,
                47, 48, 49, 50,51,52,53,54 };
        int target = 47;

        int idx = findPos(arr, target);

        if (idx != -1) {

            System.out.println(target + " is present at index " + idx + ".");
        } else {
            System.out.println(target + " not found.");

        }
    }
}
