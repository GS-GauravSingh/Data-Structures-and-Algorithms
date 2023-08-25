#include <bits/stdc++.h>
using namespace std;

class Solution
{

    /* ----------------------------- All About Prime and How to check a number is prime or not --------------- */
    /*

    Question 1: What is a Prime Number?
    Answer: A prime number is a natural number greater than 1 and a number is considered prime, if and only if that number has only 2 factors, first is 1, and second is the number itself.

    Important Points:
    1. It's important to note that every integer has at least two divisors: 1 and itself.
    2. If a number has more divisors than just 1 and itself, it's called a "composite" number.   => Composite Number.
    3. If a number has only two divisors (1 and itself), it's called a "prime" number.      => Prime Number.
    */

    // Below are the 3 methods (Brute - Better - Optimal) to check whether the given number is prime or not.

    /* Method to check if a given number is prime or not. */
    // Time Complexity: O(n), where 'n' is the given number.
    // Space Complexity: O(1).
    bool isPrime_BruteForce(int num)
    {
        // Base Case
        // 0 and 1 are not a prime numbers. Prime Numbers are greater than 1.
        if (num <= 1)
        {
            return 0;
        }

        // A prime number is a natural number greater than 1 and a number is considered prime, if and only if that number has only 2 factors, first is 1, and second is the number itself.

        // So, to check whether a given 'num' is prime or not, we just need to find if there is any number that exists in the range of [2, num-1] that is a divisor of num. If we found such a number that divides 'num', it means 'num' is not a prime number, otherwise 'num' is a prime number.

        // In Simple Words, If a number has only two divisors (1 and itself), it's called a "prime" number and If a number has more divisors than just 1 and itself, then it is not a prime number it's a composite number.

        // So to check whether a given number is prime or not, you just need to identify If a number has more divisors than just 1 and itself.
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
        // 0 and 1 are not a prime numbers. Prime Numbers are greater than 1.
        if (num <= 1)
        {
            return 0;
        }

        /* Property: There is one property about factors and that property is: If a number is prime, then it only has 2 factors, first is 1, and second is the number itself and if the number has more than 2 factors, then that number is not a prime number, Okay!.

        Now, The property states that, all the factors or divisors of a given number exist in the range of [1, n/2], where 'n' is the given number.

        Example 1: Number = 6, and all the factors of 6 are: 1, 2, 3, and 6. Now, if you carefully observe, these 2 divisors "1 and a number itself" are common divisors of all the numbers. So, for now ignore these 2 factor (1 and 6). Other then these factors, there are 2 more factors, that is 2 and 3, and if you observe, before 6, 3 is the last factor of 6, which is basically (n/2). See, all the factors of 6 are in the range of [1, n/2].

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

        Now, square root of 36 is 6, and if you observe carefull in the above pairs, after the sqrt(6), all the pairs are just reverse repetitions of the pairs that appear before the square root. This property is true for all numbers, not just for 36.

        So, to check whether a given number 'n' is a prime number, you only need to iterate from 2 to the square root of 'n' (inclusive) and check if any of these numbers divides 'n' or not.
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

    /* ------------------------------------- How to find Prime Factorization of a given number --------------------------------- */
    /*

    Property 1: The smallest divisor of any number is always a prime number, except for 1. Since 1 does not have any prime divisors, it is a special case.

    Example 1: Let's consider the number 15. The smallest divisor of 15 is 3, which is a prime number. So, the concept holds true for this case.

    Example 2: Take the number 28. The smallest divisor of 28 is 2, which is also a prime number.

    Example 3: Consider the number 33. The smallest divisor of 33 is 3, which is a prime number.

    Example 4: Now, let's take the number 9. The smallest divisor of 9 is 3, which is, again, a prime number.

    Property 2: One of the key properties in number theory is that every composite number has at least one prime factor that is less than or equal to its square root.

    For example, let's consider the number 36. Its square root is approximately 6. In the prime factorization of 36, you have 2 * 2 * 3 * 3. Notice that all the prime factors (2 and 3) are less than the square root of 36. This holds true for most composite numbers.
    */
    void primeFactorization_BruteForce(int n)
    {
        cout << "Prime Factorization of " << n << ": ";
        for (int i = 2; i <= n; i++)
        {
            while (n % i == 0)
            {
                cout << i << " ";
                n = n / i;
            }
        }
        cout << endl;
    }
    void primeFactorization_Optimized(int n)
    {
        cout << "Prime Factorization of " << n << ": ";
        for (int i = 2; i <= sqrt(n); i++)
        {
            while (n % i == 0)
            {
                cout << i << " ";
                n = n / i;
            }
        }

        if (n > 1)
            cout << n;
            
        cout << endl;
    }

public:
    int isPrime(int n)
    {
        // Prime Factorization.
        primeFactorization_BruteForce(n);
        primeFactorization_Optimized(n);

        // // Brute Force Solution.
        // return isPrime_BruteForce(n);

        // // Better Approach.
        // return isPrime_Better(n);

        // Optimized Approach.
        return isPrime_Optimized(n);
    }
};

int main(void)
{

    Solution obj;
    int num = 36;
    if (obj.isPrime(num))
    {
        cout << num << " is a Prime Number.";
    }
    else
    {
        cout << num << " is not a Prime Number.";
    }
    return 0;
}