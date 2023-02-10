
public class MoveNegatives {
    /* Approach 1:- Using Extra space. TC:- O(n), SC:- O(n) */
    static void moveNegative_Approach_1(int arr[])
    {
        int ans[] = new int[arr.length];
        int k = 0;
        for (int i = 0; i < arr.length; i++)
        {
            // first push all negative elements.
            if (arr[i] < 0)
            {
                ans[k++] = arr[i];
            }
        }

        for (int i = 0; i < arr.length; i++)
        {
            // then push all non-negative elements.
            if (arr[i] >= 0)
            {
                ans[k++] = arr[i];
            }
        }

        // update answer
        for (int i = 0; i < arr.length; i++)
        {
            arr[i] = ans[i];
        }
    }

    /* Approach 2:- Using 2 pointer. TC:- O(n), SC:- O(1) */
    static void moveNegative_Approach_2(int arr[])
    {
        int low = 0, high = arr.length - 1;
        while (low < high)
        {
            if (arr[low] < 0)
            {
                low++;
            }
            else if (arr[high] > 0)
            {
                high--;
            }
            else
            {
                // swap arr[low], arr[high]
                arr[low] = arr[low] ^ arr[high];
                arr[high] = arr[low] ^ arr[high];
                arr[low] = arr[low] ^ arr[high];
            }
        }
    }

    public static void main(String[] args) {
        int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};

        // moveNegative_Approach_1(arr);
        moveNegative_Approach_2(arr);

        for(int x : arr)
        {
            System.out.print(x + " ");
        }
    }
}
