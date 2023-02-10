import java.util.ArrayList;
import java.util.List;

public class Pascals_Triangle {

    static List<List<Integer>> generate(int numRows) {
        List<List<Integer>> triangle = new ArrayList<List<Integer>>();
        if (numRows <= 0) {
            return triangle;
        }
        for (int i = 0; i < numRows; i++) {
            List<Integer> row = new ArrayList<Integer>();
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) {
                    row.add(1);
                } else {
                    row.add(triangle.get(i - 1).get(j - 1) + triangle.get(i - 1).get(j));
                }
            }
            triangle.add(row);
        }
        return triangle;
    }

    public static void main(String[] args) {

        int numRows = 5;

        List<List<Integer>> pascalTriangle = new ArrayList<List<Integer>>();
        pascalTriangle = generate(numRows);

        for (int i = 0; i < pascalTriangle.size(); i++) {
            for (int j = 0; j < pascalTriangle.get(i).size(); j++) {
                System.out.print(pascalTriangle.get(i).get(j) + " ");
            }
            System.out.println();
        }

    }
}
