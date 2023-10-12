// You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, and you only have the observations of m rolls. Fortunately, you have also calculated the average value of the n + m rolls.

// You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the two integers mean and n.

// Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. If there are multiple valid answers, return any of them. If no such array exists, return an empty array.

// The average value of a set of k numbers is the sum of the numbers divided by k.

// Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.

 

// Example 1:

// Input: rolls = [3,2,4,3], mean = 4, n = 2
// Output: [6,6]
// Explanation: The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.
// Example 2:

// Input: rolls = [1,5,6], mean = 3, n = 4
// Output: [2,3,2,2]
// Explanation: The mean of all n + m rolls is (1 + 5 + 6 + 2 + 3 + 2 + 2) / 7 = 3.
// Example 3:

// Input: rolls = [1,2,3,4], mean = 6, n = 4
// Output: []
// Explanation: It is impossible for the mean to be 6 no matter what the 4 missing rolls are.
 

// Constraints:

// m == rolls.length
// 1 <= n, m <= 105
// 1 <= rolls[i], mean <= 6

/*
Approach:
    We can use a greedy approach since the question asks us to find a valid answer. So, first, initialise a vector with length n and fill it by one, 
then subtract the gap value until the gap value turns zero.
*/

#include <vector>
#include <numeric>
#include <functional>

using namespace std;

class Solution 
{
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        int sum = accumulate(rolls.cbegin(), rolls.cend(), 0, plus<int>());
        int gap = mean * (n + rolls.size()) - sum;
        if (gap > 6 * n || gap < 0)
        {
            return {};
        }
        vector<int> result(n, 1);
        gap -= n - 1;

        // Note: Here we need to inspect the gap value twice.
        if (gap < 0)
        {
            return {};
        }
        for (int i=0; i<n; ++i)
        {
            int minval = std::min(gap, 6);
            gap -= std::abs(minval - result[i]);
            result[i] = minval;
            if (gap == 0)
            {
                break;
            }
        }
        return result;
    }
};