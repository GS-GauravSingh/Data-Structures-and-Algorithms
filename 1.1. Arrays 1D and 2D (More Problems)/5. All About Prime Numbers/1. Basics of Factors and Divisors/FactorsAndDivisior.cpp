#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    /*

    ----------------------------------------- Question 1 --------------------------------------------------------------------
    Question 1: What are Divisors ?.
    Answer: Divisors, also known as factors, are numbers that completely divide another number without leaving any remainder.

    For example:  let's consider the number 12. The divisors of 12 are 1, 2, 3, 4, 6, and 12, because Each of these divisors can completely divide 12 and leave the remainder 0.

    => 12 ÷ 1 = 12 with remainder 0
    => 12 ÷ 2 = 6 with remainder 0
    => 12 ÷ 3 = 4 with remainder 0
    => 12 ÷ 4 = 3 with remainder 0
    => 12 ÷ 6 = 2 with remainder 0
    => 12 ÷ 12 = 1 with remainder 0

    When one number completely divides another number, the remainder of the division will be 0.

    Important Points:
    1. It's important to note that every integer has at least two divisors: 1 and itself.
    2. If a number has more divisors than just 1 and itself, it's called a "composite" number.
    3. If a number has only two divisors (1 and itself), it's called a "prime" number.

    Examples:
    Composite Number Example: Let's consider the number 15. The divisors of 15 are 1, 3, 5, and 15. It's not a prime number because it has divisors other than 1 and 15. Therefore, 15 is a composite number.

    Prime Number Example: 2, 3, 5, 7, 11 are prime numbers because they have no divisors other than 1 and themselves.
    */

    /*
    ----------------------------------------- Question 2 --------------------------------------------------------------------
    Question 2: How to find all the divisors of a given number 'n'.
    Answer: Start iterating through the numbers from 2 to n-1 and if each number in the range [2, n-1] divides 'n' without leaving a remainder. If it does, then that number is a divisor of 'n', otherwise not.

    Note: There is no need to check for 1 and n, because every integer has at least two divisors: 1 and itself.


    ----------------------------------------- Question 3 --------------------------------------------------------------------
    Question 3: Count the total number of divisors of a given number in Question 2 and also calculate the sum of divisors.

    */

    // Below is the code for question 2 and 3.
    int num = 24; // let's find all the diviors of 24.

    int cnt = 0; // variable to store the total number of divisors of given number.
    int sum = 0; // variable to store the sum of divisors of given number.

    cout << "Divisors of " << num << " are: ";
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            cout << i << " ";
            cnt++;
            sum += i;
        }
    }

    cout << "\nTotal number of Divisors: " << cnt << ". Sum of Divisors: " << sum << ".\n";

    /* Now, this is a Brute Force approach for finding all divisors of a given number. Time Complexity of this approach is O(n) and Space Complexity is O(1). Now, let's see how to optimize this Brute Force Approach. */

    /*
    ----------------------------------------- Question 4 --------------------------------------------------------------------
    Question 4: In the above questions the TC for finding all divisors of a given number is O(n), can we do something better than this ?
    Answer: Let's understand the Optimized approach with the help of example,

    Example: let's say we have a Number = 36 and we have to find all the divisors of 36,
    Now, if I write all the divisors of 36 in pairs,

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

    So, you can easily find all the divisors in the range of [2, sqrt(n)].

    Below is code for question 4.
    */

    num = 36; // lets find all the divisors of 36.

    cnt = 0; // variable to store the total number of divisors of given number.
    sum = 0; // variable to store the sum of divisors of given number.

    cout << "Divisors of " << num << " are: \n";

    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            // if i is a divisor of num, then (num/i) is also a divisor of num.
            // Example: 2 is a divisor of 36, so 36/2 i.e., 18 is also divisor of 36.
            cout << i << ", " << (num / i) << "\n";

            cnt+=2;
            sum += i;
            sum += (num/i);

            // In case of (6*6), in this case we count 6 two times and add this 6 two time in our sum.
            // and we have to count the only one time and add this only one time.
            if (i == (num / i))
            {
                sum -= i;
                cnt--;
            }
        }
    }
    cout << "Total number of Divisors: " << cnt << ". Sum of Divisors: " << sum << ".\n";

    /* Now, this is a Optimized approach for finding all divisors of a given number. Time Complexity of this approach is O(sqrt(n)) and Space Complexity is O(1). */

    return 0;
}