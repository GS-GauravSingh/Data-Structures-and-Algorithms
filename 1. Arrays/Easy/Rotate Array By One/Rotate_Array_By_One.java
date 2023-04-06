
public class Rotate_Array_By_One {
    /* Method to print array. */
    static void print(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println(); // new line
    }

    /* Method to rotate array by one element to the right. */
    // Time Complexity :- O(n)
    // Space Complexity :- O(1)
    static void rotateByOne(int arr[]) {
        // size of array.
        int n = arr.length;

        // storing last element.
        int lastElement = arr[n - 1];

        // shif all elements to the right by one place.
        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = lastElement;
    }

    public static void main(String[] args) {

        int arr[] = { 1, 2, 3, 4, 5 };

        System.out.println("Before Rotation :- ");
        print(arr);

        System.out.println("After Rotation :- ");
        rotateByOne(arr);
        print(arr);
    }
}
