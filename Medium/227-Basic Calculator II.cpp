// Given a string s which represents an expression, evaluate this expression and return its value. 

// The integer division should truncate toward zero.

// You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

// Example 1:

// Input: s = "3+2*2"
// Output: 7
// Example 2:

// Input: s = " 3/2 "
// Output: 1
// Example 3:

// Input: s = " 3+5 / 2 "
// Output: 5
 

// Constraints:

// 1 <= s.length <= 3 * 105
// s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
// s represents a valid expression.
// All the integers in the expression are non-negative integers in the range [0, 231 - 1].
// The answer is guaranteed to fit in a 32-bit integer.

/*
Approach:
   This kind of problem has a fixed method to solve: First, parse the expression, separate the numbers and operators from the expression; Second, 
convert the string(or the list) to suffix form; Last, calculate the suffix expression using a stack.
*/

#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <cctype>

using namespace std;

class Solution 
{
public:
    int calculate(string s) 
    {
        auto v = toArray(s);
        v = toSuffix(v);
        // for (const auto& str: v)
        // {
        //     cout << str << " ";
        // }
        stack<int> _stack {};
        for (const auto& str: v)
        {
            if (std::isdigit(str.front()))
            {
                _stack.push(stoi(str));
            }
            else
            {
                int a = _stack.top();
                _stack.pop();
                int b = _stack.top();
                _stack.pop();
                if (str == "+")
                {
                    _stack.push(a + b);
                }
                else if (str == "-")
                {
                    _stack.push(b - a);
                }
                else if (str == "*")
                {
                    _stack.push(a * b);
                }
                else
                {
                    _stack.push(b / a);
                }
            }
        }

        return _stack.top();
    }

private:
    unordered_map<string, int> _map{
        {"+", 0}, {"-", 0}, {"*", 1}, {"/", 1}
    };
    // First step: parse the expression.
    vector<string> toArray(string& expression)
    {
        vector<string> result {};
        string curTokens {};
        for (const char& ch: expression)
        {
            if (std::isdigit(ch) || (curTokens.empty() && ch == '-'))
            {
                curTokens.push_back(ch);
            }
            else if (isOperator(ch))
            {
                if (!curTokens.empty())
                {
                    result.push_back(curTokens);
                    curTokens.clear();
                }
                result.push_back(string(1, ch));
            }
            else
            {
                continue;
            }
        }
        if (!curTokens.empty())
        {
            result.push_back(curTokens);
        }
        return result;
    }

    bool isOperator(char ch)
    {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

    // Overload the function since after parsing the expression, the operators will become strings.
    bool isOperator(const string& str)
    {
        char ch = str.front();
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }
    // Second step: convert the infix-expression to suffix-expression.
    vector<string> toSuffix(vector<string>& vct)
    {
        stack<string> operators_stack {};
        vector<string> result {};
        for (const auto& part: vct)
        {
            if (std::isdigit(part.front()))
            {
                result.push_back(part);
            }
            else if (isOperator(part)) 
            {
            while (!operators_stack.empty() &&_map[part] <= _map[operators_stack.top()]) 
            {
                result.push_back(operators_stack.top());
                operators_stack.pop();
            }
            operators_stack.push(part);
        }
        }
        while (!operators_stack.empty())
        {
            result.push_back(operators_stack.top());
            operators_stack.pop();
        }
        return result;
    }
    
};