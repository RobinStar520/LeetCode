// Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

 

// Example 1:


// Input: n = 3
// Output: 5
// Example 2:

// Input: n = 1
// Output: 1
 

// Constraints:

// 1 <= n <= 19

/*
Approach:
    If you are new to this kind of problem, you may feel that you don’t know how to start. First, we should know that this question doesn't ask us to
get all the binary search tree structures, and we only need to get the number of different binary search trees. Let's try to analyse the question. 
First, a binary search tree with one node only has one probability; Second, a binary tree search tree with two nodes has two probabilities: The maximum 
value is the root, or the minimum value is the root. Third, a binary tree with nodes has five probabilities. For example, these three numbers can build a 
binary search tree: [1, 2, 3], and each number of the list can be set as the root. When the root's value is 1, it has two possibilities; When the root's value
is 2, it has one possibility... Until now, we can find that this question can be divided into some sub-questions, so thinking about dynamic programming.
let's use dp[i] denoting a binary search tree with i nodes. We can prove that dp[i] = dp[j - 1] * dp[i - j](i <= n && 1 <=j <= i).
*/

#include <vector>

using namespace std;


class Solution 
{
public:
    int numTrees(int n) 
    {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i=1; i<=n; ++i)
        {
            for (int j=1; j<=i; ++j)
            {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
    }
};