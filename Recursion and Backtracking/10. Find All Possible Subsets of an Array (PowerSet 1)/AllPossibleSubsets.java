import java.util.ArrayList;
import java.util.List;

public class AllPossibleSubsets {
    // Time Complexity :- O(n* 2^n), n is the size of array.
    // Space Complexity :- O(n), recursive stack space.
    static void generateAllSubsets(int i, int n, int arr[], List<Integer> subSet, List<List<Integer>> powerset) {
        // Base Case.
        if (i >= n) {
            powerset.add(new ArrayList<>(subSet));
            return;
        }

        // Recursive Case.

        // picking the ith element.
        subSet.add(arr[i]);
        generateAllSubsets(i + 1, n, arr, subSet, powerset);

        // Backtracking step.
        // remove the picked element.
        subSet.remove(subSet.size() - 1);

        // not picking the ith element.
        generateAllSubsets(i + 1, n, arr, subSet, powerset);
    }

    static List<List<Integer>> subsets(int[] nums) {
        List<Integer> subSet = new ArrayList<>();
        List<List<Integer>> powerSet = new ArrayList<>();

        generateAllSubsets(0, nums.length, nums, subSet, powerSet);
        return powerSet;
    }
 
    /* Method to print 2D List.  */
    static void print2D(List<List<Integer>> arr) {
        for (int i = 0; i < arr.size(); i++) {
            if (arr.get(i).size() == 0) {
                System.out.println("{}");
                continue;
            }

            for (int j = 0; j < arr.get(i).size(); j++) {
                System.out.print(arr.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int nums[] = { 1, 2, 3 };

        List<List<Integer>> powerSet = subsets(nums);

        print2D(powerSet);
    }
}