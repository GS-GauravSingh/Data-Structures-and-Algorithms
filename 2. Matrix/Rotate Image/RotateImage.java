
public class RotateImage {
    /*
     * Algorithm:-
     * 
     * Step 1:- first take the transpose of matrix.
     * // to transpose matrix,
     * //first travers in lower diagonal or upper diagonal and swap (matrix[i][j],
     * matrix[j][i]);
     * Step 2:- after transpose, reverse each row this will rotate your array by 90
     * degree.
     * 
     * Time Complexity:- O(n^2)
     * Space Complexity:- O(1)
     */

    static void reverse(int arr[]) {
        int start = 0, end = arr.length - 1;

        while (start < end) {

            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }
    }

    static void rotate(int[][] matrix) {
        // Step 1:- first take the transpose of matrix.
        // to transpose matrix,
        // first traverse in lower diagonal or upper diagonal and swap (matrix[i][j],
        // matrix[j][i]);

        int row = matrix.length;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j <= i; j++) {
                // swap matrix[i][j], matrix[j][i].
                int temp = 0;
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }

        }

        // Step 2:- after transpose, reverse each row this will rotate your array by 90
        // degree.
        for (int i = 0; i < matrix.length; i++) {
            reverse(matrix[i]);
        }
    }

    /* Method to print 2D array. */
    static void print2D(int arr[][]) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[i].length; j++) {
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int matrix[][] = {
                { 1, 2, 3 },
                { 4, 5, 6 },
                { 7, 8, 9 },
        };

        rotate(matrix);
        print2D(matrix);
    }
}
