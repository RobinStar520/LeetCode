// Given an integer n, return the number of prime numbers that are strictly less than n.

 

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
// Example 2:

// Input: n = 0
// Output: 0
// Example 3:

// Input: n = 1
// Output: 0
 

// Constraints:

// 0 <= n <= 5 * 106

/*
Approach:
    For this question, we can't use a traditional method to find the primes due to the large constraints. We need to use Sieve of Eratosthenes algorithm.
The Sieve of Eratosthenes is a classic and efficient algorithm used to find all prime numbers up to a given limit or to determine if a specific number is 
prime. The algorithm works by iteratively marking the multiples of each prime number, starting from 2, as composite (non-prime). Here's a step-by-step 
explanation of how the Sieve of Eratosthenes works:
    1.Create a list or an array of numbers from 2 to the desired limit (or n if you want to find primes up to n).
    2.Start with the first number in the list, which is 2, and mark it as prime.
    3.Iterate through the list of numbers, starting from the next unmarked number (2 in this case), and mark all multiples of that number as composite. 
    For example, when working with the number 2, you would mark 4, 6, 8, 10, and so on, as composite.
    4.Move to the next unmarked number in the list (3 in this case), and mark its multiples as composite.
    5.Repeat this process for each unmarked number in the list until you have processed all numbers up to the square root of the limit. This is because, 
    for any non-prime number greater than the square root of the limit, all of its multiples less than the limit will have already been marked as composite.
    6.Once you've completed the iterations, the unmarked numbers that remain in the list are prime numbers.
    7.You can then use the list of prime numbers for various purposes, such as counting the number of primes, finding specific prime numbers, or solving 
    related mathematical problems.
*/


#include <bitset>
#include <cmath>

using namespace std;

class Solution 
{
public:
    int countPrimes(int n) 
    {
        if (n < 2)
        {
            return 0;
        }
        // Note: the number 5000001 is not fixed, you should adjust it based on the constraint.
        bitset<5000001> bits {};
        // Be aware of the loop-ending condition.
        for (int i=2; i<=sqrt(n); i++)
        {
            if (!bits[i])
            {
                for (int j=i*i; j<=n; j+=i)
                {
                    bits[j] = 1;
                }
            }
        }
        int result = 0;
        for (int i=2; i<n; ++i)
        {
            if (bits[i] == 0)
            {
                result += 1;
            }
        }
        return result;

    }
    
};