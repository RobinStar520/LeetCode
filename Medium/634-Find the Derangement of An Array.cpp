// In combinatorial mathematics, a derangement is a permutation of the elements of a set, such that no element appears in its original position.

// You are given an integer n. There is originally an array consisting of n integers from 1 to n in ascending order, return the number of derangements it can generate. Since the answer may be huge, return it modulo 109 + 7.

 

// Example 1:

// Input: n = 3
// Output: 2
// Explanation: The original array is [1,2,3]. The two derangements are [2,3,1] and [3,1,2].
// Example 2:

// Input: n = 2
// Output: 1
 

// Constraints:

// 1 <= n <= 106

/*
Approach:
    This is a dynamic programming problem. The transition formula is dp(n)=(n−1)*[d(n−1)+d(n−2)].
*/

#include <vector>

using namespace std;

class Solution 
{
public:
    int findDerangement(int n) 
    {
        int MOD = 1e9 + 7;
        vector<int> dp(n+1, 0);
        if (n == 0)
        {
            return 1;
        }
        else if (n == 1)
        {
            return 0;
        }

        dp[0] = 1;
        dp[1] = 0;
        for (int i=2; i<=n; ++i)
        {
            dp[i] = static_cast<int>((i * 1ll - 1) * (dp[i - 1] + dp[i - 2]) % MOD);
        }

        return dp[n];
    }
};