//     Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8

/*
Approach:
    This question has small constraints, so consider using backtracking. It's a permutation problem since each parenthesis can be used only once 
and the final result should include all the parentheses.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution 
{
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string> result {};
        string str (n*2, ')');
        for (int i=0; i<n; ++i)
        {
            str[i] = '(';
        }

        do
        {
            // Validate the strings.
            if (valid(str))
            {
                result.push_back(str);
            }
        }
        while (next_permutation(str.begin(), str.end()));
        return result;

    }

private:
    
    bool valid(const string& pattern)
    {
        stack<char> _stack {};
        for (const auto& ch: pattern)
        {
            if (ch == '(')
            {
                _stack.push(ch);
            }
            else
            {
                if (_stack.empty() || _stack.top() != '(')
                {
                    return false;
                }
                _stack.pop();
            }
        }
        if (!_stack.empty())
        {
            return false;
        }
        return true;
    }
};