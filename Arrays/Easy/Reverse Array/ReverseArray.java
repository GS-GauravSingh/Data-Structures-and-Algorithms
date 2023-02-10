
public class ReverseArray {
    // Approach 1 :- Using another array..
    // Time Complexity:- O(n), n is the size of vector.
    // Space Complexity:- O(n)
    static void reverse_Approach_1(int arr[]) {

        // size of array.
        int n = arr.length;

        // copy all the elements of arr into aux array in reverse order. 
        int aux[] = new int[n];
        int k = 0;
        for (int i = n-1; i >= 0 ; i--) {
            aux[k++] = arr[i];
        }

        // copy back all element of aux array into original array.
        for (int i = 0; i < n ; i++) {
            arr[i] = aux[i];
        }
    }

    // Approach 2 :- Using 2 pointers.
    // Time Complexity:- O(n), n is the size of vector.
    // Space Complexity:- O(1)
    static void reverse_Approach_2(int arr[]) {
        int start = 0;
        int end = arr.length - 1;

        while (start < end)
        {
            // swap arr[start], arr[end]
            arr[start] = arr[start] ^ arr[end];
            arr[end] = arr[start] ^ arr[end];
            arr[start] = arr[start] ^ arr[end];

            // update pointers
            start++;
            end--;
        }
    }

    public static void main(String[] args) {
        int arr[] = { 1, 2, 3, 4, 5};

        // reverse_Approach_1(arr);
        reverse_Approach_2(arr);
        for(int x : arr)
        {
            System.out.print(x + " ");
        }
    }
}
