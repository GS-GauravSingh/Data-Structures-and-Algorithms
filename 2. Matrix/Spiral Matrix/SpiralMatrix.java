
public class SpiralMatrix {
    // Time Complexity:- O(m*n).
    // Space Complexity:- O(1).
    static int[] spiralOrder(int[][] matrix) {
        // row and column in matrix.
        int matrixRow = matrix.length;
        int matrixCol = matrix[0].length;

        // total element in matrix.
        int totalElements = matrixRow * matrixCol;
        int count = 0; // used while traversing the matrix.

        // needed variables.
        int upperRow = 0;
        int bottomRow = matrixRow - 1;

        int leftCol = 0;
        int rightCol = matrixCol - 1;

        // array to store answer.
        int ans[] = new int[totalElements];
        int k = 0; // used to store element in ans array.

        while (count < totalElements) {
            // traversing upper row.
            for (int row = leftCol; count < totalElements && row <= rightCol; row++) {
                ans[k++] = matrix[upperRow][row];
                count++;
            }
            upperRow++;

            // traversing right column.
            for (int col = upperRow; count < totalElements && col <= bottomRow; col++) {
                ans[k++] = matrix[col][rightCol];
                count++;
            }
            rightCol--;

            // traversing bottom row.
            for (int row = rightCol; count < totalElements && row >= leftCol; row--) {
                ans[k++] = matrix[bottomRow][row];
                count++;
            }
            bottomRow--;

            // traversing left column.
            for (int col = bottomRow; count < totalElements && col >= upperRow; col--) {
                ans[k++] = matrix[col][leftCol];
                count++;
            }
            leftCol++;
        }

        return ans;

    }

    public static void main(String[] args) {
        int[][] matrix = {
                { 1, 2, 3 },
                { 4, 5, 6 },
                { 7, 8, 9 },
        };

        int ans[] = spiralOrder(matrix);

        for (int x : ans) {
            System.out.print(x + " ");
        }
    }
}
