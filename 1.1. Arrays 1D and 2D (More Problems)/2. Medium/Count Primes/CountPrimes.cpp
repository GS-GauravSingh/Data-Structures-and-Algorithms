#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Below are the 3 methods (Brute - Better - Optimal) to check whether the given number is prime or not.

    /* Method to check if a given number is prime or not. */
    // Time Complexity: O(n), where 'n' is the given number.
    // Space Complexity: O(1).
    bool isPrime(int num)
    {
        // Base Case
        // 0 and 1 are not a prime numbers.
        if (num <= 1)
        {
            return 0;
        }

        // A prime number is a natural number greater than 1 and a number is considered prime, if and only if that number has only 2 factors, first is 1, and second is the number itself.

        // So, to check whether a given 'num' is prime or not, we just need to find if there is any number that exists in the range of [2, num-1] that is a divisor of num. If we found such a number that divides 'num', it means 'num' is not a prime number, otherwise 'num' is a prime number.
        for (int divisor = 2; divisor < num; divisor++)
        {
            // If we found such a number that divides 'num', it means 'num' is not a prime number, so return false from here.
            if (num % divisor == 0)
            {
                return false;
            }
        }

        // If the above loop does not return false, it means 'num' is a prime number. So, return true.
        return true;
    }

    /* Method to check if a given number is prime or not - BETTER VERSION. */
    // Time Complexity: O(n / 2) ~ O(n), where 'n' is the given number.
    // Space Complexity: O(1).
    bool isPrime_Better(int num)
    {
        // Base Case
        // 0 and 1 are not a prime numbers.
        if (num <= 1)
        {
            return 0;
        }

        // A prime number is a natural number greater than 1 and a number is considered prime, if and only if that number has only 2 factors, first is 1, and second is the number itself.

        // So, to check whether a given 'num' is prime or not, we just need to find if there is any number that exists in the range of [2, num-1] that is a divisor of num. If we found such a number that divides 'num', it means 'num' is not a prime number, otherwise 'num' is a prime number.

        /* Property: There is one property about factors and that property is: If a number is prime, then it only has 2 factors, first is 1, and second is the number itself and if the number has more than 2 factors, then that number is not a prime number, Okay!. Now, The property states that, all the factors of a given number exist in the range of [1, n/2], where 'n' is the given number.

        Example 1: Number = 6, and all the factors of 6 are: 1, 2, 3, and 6. Now, if you carefully observe, these 2 divisors "1 and a number itself" are common divisors of all the numbers. So, for now ignore these 2 factor (1 and 6). Othere then these factors, there are 2 more factors, that is 2 and 3, and if you observe, before 6, 3 is the last factor of 6, which is basically (n/2). See, all the factors of 6 are in the range of [1, n/2].

        Example 2: Number = 36, and all the factors of 36 are: 1, 2, 3, 4, 6, 9, 12, and 36, except 1 and 36, all divisors of 36 are in the range of [1, n/2] => [1, 36/2] => [1, 18].

        So, we just need to iterate from 2 to n/2, to check whether the given number is prime or not.
        */
        for (int divisor = 2; divisor <= (num / 2); divisor++)
        {
            // If we found such a number that divides 'num', it means 'num' is not a prime number, so return false from here.
            if (num % divisor == 0)
            {
                return false;
            }
        }

        // If the above loop does not return false, it means 'num' is a prime number. So, return true.
        return true;
    }

    /* Method to check if a given number is prime or not - OPTIMIZED VERSION. */
    // Time Complexity: O(sqrt(n)), where 'n' is the given number.
    // Space Complexity: O(1).
    bool isPrime_Optimized(int num)
    {
        // Base Case
        // 0 and 1 are not a prime numbers.
        if (num <= 1)
        {
            return 0;
        }

        // A prime number is a natural number greater than 1 and a number is considered prime, if and only if that number has only 2 factors, first is 1, and second is the number itself.

        // So, to check whether a given 'num' is prime or not, we just need to find if there is any number that exists in the range of [2, num-1] that is a divisor of num. If we found such a number that divides 'num', it means 'num' is not a prime number, otherwise 'num' is a prime number.

        /*
        Now, if I say, we just need to iterate from 2 to square root of 'n' (sqrt(n)), to check whether the given number is prime or not.

        Example: Number = 36,

        Now, if I write all the divisors of 36 in pairs, As we know that, If we multiply any two divisors of a given number 'n', the result will always be equal to 'n'.

        Pairs are:
        (1 * 36) = 36, 1 and 36 both are divisors of 36.
        (2 * 18) = 36, 2 and 18 both are divisors of 36.
        (3 * 12) = 36, 3 and 12 both are divisors of 36.
        (4 * 9) = 36, 4 and 9 both are divisors of 36.

        (6 * 6) = 36, 6 is a divisor of 36. --------------------------------- Break Point.

        (9 * 4) = 36, 9 and 4 both are divisors of 36.
        (12 * 3) = 36, 12 and 3 both are divisors of 36.
        (18 * 2) = 36, 18 and 2 both are divisors of 36.
        (36 * 1) = 36, 36 and 1 both are divisors of 36.

        Now, square root of 36 is 6, and if you observe carefull in the above pairs, after the sqrt(6), all the pairs are just repetitions of the pairs that appear before the square root. This property is true for all numbers, not just for 36.

        So, to check whether a given number 'n' is a prime number, you only need to iterate from 2 to the square root of 'n' (inclusive) and check if any of these numbers divide 'n' evenly.
        */
        for (int divisor = 2; divisor <= sqrt(num); divisor++)
        {
            // If we found such a number that divides 'num', it means 'num' is not a prime number, so return false from here.
            if (num % divisor == 0)
            {
                return false;
            }
        }

        // If the above loop does not return false, it means 'num' is a prime number. So, return true.
        return true;
    }

    /* Brute Force Approach: To count the number of prime numbers that are strictly less than n. */
    // Time Complexity: O(n) * O(sqrt(n)), where 'n' is the given number.
    // Space Complexity: O(1).
    int countPrimes_BruteForce(int n)
    {
        // Base Case
        // 0 and 1 are not a prime numbers.
        if (n <= 1)
        {
            return 0;
        }

        // variable to store count of prime numbers that are strictly less than n.
        int cnt = 0;

        // Iterate from 2 to n-1.
        for (int num = 2; num < n; num++)
        {
            // check whether 'num' is prime or not, If yes, the increment the count, else move to next number.

            if (isPrime_Optimized(num))
            {
                cnt++;
            }
        }

        // return the count.
        return cnt;
    }

    /* Optimized Approach: Sieve of Eratosthenes. */
    // Time Complexity:  O(n * log(log(n))), where 'n' is the given number.
    // Space Complexity: O(n), space used by auxiliary 'isPrime' vector.
    int countPrimes_Optimized(int n)
    {
        // Base Case
        // 0 and 1 are not a prime numbers.
        if (n <= 1)
        {
            return 0;
        }

        // Boolean vector used in Sieve of Eratosthenes.
        vector<bool> isPrime(n, true);

        // 0 and 1 are not prime numbers, so mark these indices as false.
        isPrime[0] = isPrime[1] = false;

        // variable to store count of prime numbers that are strictly less than n.
        int cnt = 0;

        // Iterate from 2 to n-1.
        for (int num = 2; num < n; num++)
        {
            // Now, If a given number 'num' is prime, then start from the second multiple of given number (num * 2) and mark all the multiples of given number 'num' as false, because these multiples are not a prime number.
            if (isPrime[num] == true)
            {
                // Marking Multiples of 'num' as false.
                for (int multiples = num * 2; multiples < n; multiples = multiples + num)
                {
                    isPrime[multiples] = false;
                }
            }
        }

        // Now, traverse the 'isPrime' vector and the indices whic are marked as true are prime numbers.
        for (int i = 2; i < n; i++)
        {
            if (isPrime[i] == true)
            {
                cnt++;
            }
        }

        // return the count.
        return cnt;
    }

public:
    int countPrimes(int n)
    {

        // // Brute Force Solution.
        // return countPrimes_BruteForce(n);

        // Optimized Approach.
        return countPrimes_Optimized(n);
    }
};

int main(void)
{
    int n = 10;

    // Solution.
    Solution obj;
    cout << "There are total " << obj.countPrimes(n) << " Primes which are strictly less than " << n << ".";

    return 0;
}