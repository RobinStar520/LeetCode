// Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the answer in any order.

// Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.

 

// Example 1:

// Input: n = 3, k = 7
// Output: [181,292,707,818,929]
// Explanation: Note that 070 is not a valid number, because it has leading zeroes.
// Example 2:

// Input: n = 2, k = 1
// Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

// Constraints:

// 2 <= n <= 9
// 0 <= k <= 9

/*
Approach:
    Obviously, this is a backtracking problem due to the small constraints.
*/

#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> numsSameConsecDiff(int n, int k) 
    {
        vector<int> result {};
        for (int i=1; i<=9; ++i)
        {
            this->dfs(n, k, i, result);
        }
        return result;
    }

private:
    void dfs(int n, int k, int num, vector<int>& result)
    {
        if (1 == n)
        {
            result.push_back(num);
            return;
        }
        int back = num % 10;
        // Judge two situations simultaneously.
        if (back + k <= 9) 
        {
            dfs(n - 1, k, num * 10 + back + k, result);
        }
        if (k != 0 && back - k >= 0) 
        {
            dfs(n - 1, k, num * 10 + back - k, result);
        }
        return;
    }

};