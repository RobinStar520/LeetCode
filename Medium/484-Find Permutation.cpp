// A permutation perm of n integers of all the integers in the range [1, n] can be represented as a string s of length n - 1 where:

// s[i] == 'I' if perm[i] < perm[i + 1], and
// s[i] == 'D' if perm[i] > perm[i + 1].
// Given a string s, reconstruct the lexicographically smallest permutation perm and return it.

 

// Example 1:

// Input: s = "I"
// Output: [1,2]
// Explanation: [1,2] is the only legal permutation that can represented by s, where the number 1 and 2 construct an increasing relationship.
// Example 2:

// Input: s = "DI"
// Output: [2,1,3]
// Explanation: Both [2,1,3] and [3,1,2] can be represented as "DI", but since we want to find the smallest lexicographical permutation, you should return [2,1,3]

/*
Approach:
    We can use a stack to store the elements we have visited.
*/
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
    vector<int> findPermutation(string s) 
    {
        vector<int> result(s.length() + 1, 0);
        stack<int> _stack {};
        int index = 0;
        for (int i=1; i<=s.length(); ++i)
        {
            if (s[i - 1] == 'I')
            {
                _stack.push(i);
                while (!_stack.empty())
                {
                    result[index ++] = _stack.top();
                    _stack.pop();
                }
            }
            else
            {
                _stack.push(i);
            }
        }
        _stack.push(s.length() + 1);
        while (!_stack.empty())
        {
            result[index ++] = _stack.top();
            _stack.pop();
        }
        return result;
    }
};