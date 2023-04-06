import java.util.HashMap;

public class TwoSum {
    /* Brute Force Approach:- Using nested loops. */
    // Time Complexity:- O(n^2), n is the size of array.
    // Space Complexity:- O(1)
    static int[] twoSum_Approach_1(int arr[], int target) {

        // array to store answer.
        int ans[] = new int[2];
        ans[0] = -1;
        ans[1] = -1;

        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length; j++) {

                int sum = arr[i] + arr[j];
                if (sum == target) {
                    ans[0] = i;
                    ans[1] = j;
                    return ans;
                }
            }
        }

        return ans;
    }

    /* Approach 2:- Using hashmap. */
    // Time Complexity:- O(n), n is the size of array.
    // Space Complexity:- O(n)
    static int[] twoSum_Approach_2(int arr[], int target) {

        // hashmap
        HashMap<Integer, Integer> mpp = new HashMap<>();

        // array to store answer.
        int ans[] = new int[2];
        ans[0] = -1;
        ans[1] = -1;

        for (int i = 0; i < arr.length; i++) {
            
            int value = target - arr[i];

            if(mpp.containsKey(value) == true){
                ans[0] = i; 
                ans[1] = mpp.get(value);
                return ans; 
            }
            else{
                mpp.put(arr[i], i);
            }
        }

        return ans;
    }

    public static void main(String[] args) {
        int arr[] = { 2, 7, 11, 15 };
        int target = 9;

        // int ans1[] = twoSum_Approach_1(arr, target);
        int ans2[] = twoSum_Approach_2(arr, target);

        for(int x : ans2)
        {
            System.out.print(x + " ");
        }
    }
}
