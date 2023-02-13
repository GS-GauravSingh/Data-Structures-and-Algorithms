import java.util.ArrayList;
import java.util.Arrays;

public class MergeIntervals {

    static int[][] merge(int[][] intervals) {

        // sort the intervals array.
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        // aray list to store answers.
        ArrayList<int[]> merged = new ArrayList<>();

        // adding first interval into merged array.
        int newInterval[] = intervals[0];
        merged.add(newInterval);


        for (int[] interval : intervals) {
			if (interval[0] <= newInterval[1]) // Overlapping intervals, move the end if needed
				newInterval[1] = Math.max(newInterval[1], interval[1]);
			else {                             // Disjoint intervals, add the new interval to the list
				newInterval = interval;
				merged.add(newInterval);
			}
		}

        return merged.toArray(new int[merged.size()][]);

    }

    public static void main(String[] args) {
        int[][] intervals = {
                { 1, 3 },
                { 2, 6 },
                { 8, 10 },
                { 15, 18 },
        };

        int[][] ans = merge(intervals);

        for (int i = 0; i < ans.length; i++) {
            for (int j = 0; j < ans[i].length; j++) {
                System.out.print(ans[i][j] + " ");
            }
            System.out.println();
        }
    }
}
