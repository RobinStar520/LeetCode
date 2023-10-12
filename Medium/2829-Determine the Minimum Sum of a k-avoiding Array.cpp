// You are given two integers, n and k.

// An array of distinct positive integers is called a k-avoiding array if there does not exist any pair of distinct elements that sum to k.

// Return the minimum possible sum of a k-avoiding array of length n.

 

// Example 1:

// Input: n = 5, k = 4
// Output: 18
// Explanation: Consider the k-avoiding array [1,2,4,5,6], which has a sum of 18.
// It can be proven that there is no k-avoiding array with a sum less than 18.
// Example 2:

// Input: n = 2, k = 6
// Output: 3
// Explanation: We can construct the array [1,2], which has a sum of 3.
// It can be proven that there is no k-avoiding array with a sum less than 3.
 

// Constraints:

// 1 <= n, k <= 50

/*
Approach:
    This is very straightforward question. We just need an ordered set and simulate the process until the size of the set equals k. Finallly, Find the
sum of all elements in a set.
*/

#include <set>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;


class Solution 
{
public:
    int minimumSum(int n, int k) 
    {
        set<int> _set {};
        int current = 1;
        while (_set.size() < n)
        {
            _set.insert(current);
            for (const auto& i: _set)
            {
                if (_set.find(k - i) != _set.end() && k != 2 * i)
                {
                    _set.erase(std::max(i, k - i));
                }
            }
            current += 1;
        }
        int result = accumulate(_set.cbegin(), _set.cend(), 0, plus<int> {});
        
        return result;
    }
};