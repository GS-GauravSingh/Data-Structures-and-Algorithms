
public class ProductOfArrayExceptSelf {
    /* Approach 1:- Using prefix and suffix array. */
    // Time Complexity:- O(n), n is the size of vector.
    // Space Complexity:- O(n)
    static int[] productExceptSelf(int nums[]) {

        // size of array.
        int n = nums.length;

        // prefix array.
        int prefix[] = new int[n];
        int product = 1;
        int k = 0;
        for (int i = 0; i < prefix.length; i++) {
            product *= nums[i];
            prefix[k++] = product;
        }

        // suffix array.
        int suffix[] = new int[n];
        product = 1;
        k = nums.length - 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            product *= nums[i];
            suffix[k--] = product;
        }

        // answer array
        int ans[] = new int[n];

        // corner cases
        ans[0] = suffix[1];
        ans[n - 1] = prefix[n - 2];

        k = 1;
        for (int i = 1; i < nums.length - 1; i++) {
            ans[k++] = prefix[i - 1] * suffix[i + 1];
        }

        return ans;

    }

    /* Approach 2 (Optimized):- without using extra space. */
    // Time Complexity:- O(n), n is the size of vector.
    // Space Complexity:- O(1)
    static int[] productExceptSelf_Optimized(int nums[]) {

        // size of array.
        int n = nums.length;

        // prefix array.
        int prefix[] = new int[n];
        int product = 1;
        int k = 0;
        for (int i = 0; i < prefix.length; i++) {
            product *= nums[i];
            prefix[k++] = product;
        }

        product = 1;
        for (int i = n - 1; i > 0; i--) {
            prefix[i] = (prefix[i - 1] * product);
            product *= nums[i];
        }
        prefix[0] = product;

        return prefix;
    }

    public static void main(String[] args) {
        int arr[] = { 1, 2, 3, 4 };

        // int ans[] = productExceptSelf(arr);
        int ans[] = productExceptSelf_Optimized(arr);

        for (int x : ans) {
            System.out.print(x + " ");
        }
    }
}
