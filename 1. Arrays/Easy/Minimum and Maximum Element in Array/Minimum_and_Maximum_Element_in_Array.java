

public class Minimum_and_Maximum_Element_in_Array {

    /* Function to find minimum Element of the Array. Tc:- O(n), SC:- O(1).  */
    static int findMinimum(int arr[])
    {
        int minn = Integer.MAX_VALUE;
        for (int i = 0; i < arr.length; i++)
        {
            minn = Integer.min(arr[i], minn);
        }
        return minn;
    }

    /* Function to find maximum Element of the Array. Tc:- O(n), SC:- O(1).  */
    static int findMaximum(int arr[])
    {
        int maxx = Integer.MIN_VALUE;
        for (int i = 0; i < arr.length; i++)
        {
            maxx = Integer.max(arr[i], maxx);
        }
        return maxx;
    }
    public static void main(String[] args) {
        int arr[] = {10, 20, 3, 2, 6, 59, 87, -1, -100};

        System.out.println("Maximum element is : " + findMaximum(arr) );
        System.out.println("Minimum element is : " + findMinimum(arr) );
    }
}
