// The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

 

// Example 1:

// Input: n = 2
// Output: 1
// Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
// Example 2:

// Input: n = 3
// Output: 2
// Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
// Example 3:

// Input: n = 4
// Output: 3
// Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 

// Constraints:

// 0 <= n <= 30

/*
Approach:
    This is an easy and entry-level dynamic programming problem. For this question, we use an extra vector to store the state. According to the definition
of the Fibonacci number, we can get the state transition equation: dp[i] = dp[i - 1] + dp[i - 2](i >= 2).
*/

#include <vector>

using namespace std;

class Solution
{
public:
    int fib(int n) 
    {
        if (n <= 1)
        {
            return n;
        }
        // This "dp" vector records the previous states of the current value.
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i=2; i<=n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};