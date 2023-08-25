#include <bits/stdc++.h>
using namespace std;

class Solution
{

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