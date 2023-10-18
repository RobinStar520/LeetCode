// Given an integer k, return the minimum number of Fibonacci numbers whose sum is equal to k. The same Fibonacci number can be used multiple times.

// The Fibonacci numbers are defined as:

// F1 = 1
// F2 = 1
// Fn = Fn-1 + Fn-2 for n > 2.
// It is guaranteed that for the given constraints we can always find such Fibonacci numbers that sum up to k.
 

// Example 1:

// Input: k = 7
// Output: 2 
// Explanation: The Fibonacci numbers are: 1, 1, 2, 3, 5, 8, 13, ... 
// For k = 7 we can use 2 + 5 = 7.
// Example 2:

// Input: k = 10
// Output: 2 
// Explanation: For k = 10 we can use 2 + 8 = 10.
// Example 3:

// Input: k = 19
// Output: 3 
// Explanation: For k = 19 we can use 1 + 5 + 13 = 19.
 

// Constraints:

// 1 <= k <= 109

/*
Approach:
    Generate all Fibonacci numbers up to the limit (they are few). Note how many numbers you should generate. Then use greedy solution, taking at 
every time the greatest Fibonacci number which is smaller than or equal to the current number. Subtract this Fibonacci number from the current number
and repeat again the process.
*/

#include <vector>
#include <algorithm>
 
using namespace std;

class Solution 
{
public:
    int findMinFibonacciNumbers(int k) 
    {
        vector<int> dp(45, 0);
        dp[0] = dp[1] = 1;
        int result = 0;
        for (int i=2; i<45; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        while (k != 0)
        {
            auto iter = lower_bound(dp.cbegin(), dp.cend(), k);
            int val = *iter == k ? k : *(iter - 1);
            k -= val;
            result += 1;
        }
        return result;
    }
};