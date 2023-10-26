// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.
// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
 

// Constraints:

// 1 <= n <= 104

/*
Approach:
    The first impression is to use a dynamic programming approach. However, we can use a BFS method to solve it. For a given number "n", we can easily
find all the perfect square numbers from 1 to n. So this question can be regarded as a graph problem.
*/

#include <unordered_set>
#include <queue>

using namespace std;

class Solution 
{
public:
    int numSquares(int n) 
    {
        unordered_set<int> visited {};
        queue<int> q {};
        int result = 1;
        for (int i=1; i*i<=n; ++i)
        {
            visited.insert(i * i);
            q.push(i * i);
        }
        // Use BFS to find the shortest path from 1 to n.
        while (!q.empty())
        {
            int size = q.size();
            while (size --)
            {
                auto node = q.front();
                q.pop();
                if (node == n)
                {
                    return result;
                }

                for (int i=1; i*i<=n; ++i)
                {
                    int val = node + i * i;
                    if (val <= n && visited.find(val) == visited.end())
                    {
                        q.push(val);
                        visited.insert(val);
                    }
                }
            }
            result += 1;
        }
        
        
        return result;
    }
};