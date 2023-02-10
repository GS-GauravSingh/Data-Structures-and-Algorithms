

public class RemoveDuplicatesFromSortedArray {
    // Time Complexity:- O(n), n is the size of vector.
    // Space Complexity:- O(1)
    static int removeDuplicates(int nums[])
    {
        int n = nums.length;

        int i = 0;
        for (int j = 1; j < n; j++) {
            if(nums[i] != nums[j])
            {
                // move "i" one step.
                i++;

                // swap nums[i], nums[j].
                nums[i] = nums[i] ^ nums[j];
                nums[j] = nums[i] ^ nums[j];
                nums[i] = nums[i] ^ nums[j];

            }
        }

        return (i+1);

    }
    public static void main(String[] args) {
        int arr[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

        int idx = removeDuplicates(arr);
        for (int i = 0; i < idx; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
