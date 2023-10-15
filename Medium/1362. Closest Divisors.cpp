// Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.

// Return the two integers in any order.

 

// Example 1:

// Input: num = 8
// Output: [3,3]
// Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.
// Example 2:

// Input: num = 123
// Output: [5,25]
// Example 3:

// Input: num = 999
// Output: [40,25]
 

// Constraints:

// 1 <= num <= 10^9/

/*
Approach:
    This is an easy question. Try to find all pairs of divisors that satifies the conditon.
*/

#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct Comp
{
public:
    bool operator()(const vector<int>& v1, const vector<int>& v2) const
    {
        return abs(v1.back() - v1.front()) > abs(v2.back() - v2.front());
    }
};

class Solution 
{
public:
    vector<int> closestDivisors(int num) 
    {
        priority_queue<vector<int>, vector<vector<int>>, Comp> pq{};
        num += 1;
        for (int i=1; i*i<=num; ++i)
        {
            if (num % i == 0)
            {
                pq.push({i, num / i});
            }
        }
        num += 1;
        for (int i=1; i*i<=num; ++i)
        {
            if (num % i == 0)
            {
                pq.push({i, num / i});
            }
        }

        return pq.top();
    }
};