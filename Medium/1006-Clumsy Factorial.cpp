// The factorial of a positive integer n is the product of all positive integers less than or equal to n.

// For example, factorial(10) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1.
// We make a clumsy factorial using the integers in decreasing order by swapping out the multiply operations for a fixed rotation of operations with multiply '*', divide '/', add '+', and subtract '-' in this order.

// For example, clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1.
// However, these operations are still applied using the usual order of operations of arithmetic. We do all multiplication and division steps before any addition or subtraction steps, and multiplication and division steps are processed left to right.

// Additionally, the division that we use is floor division such that 10 * 9 / 8 = 90 / 8 = 11.

// Given an integer n, return the clumsy factorial of n.

 

// Example 1:

// Input: n = 4
// Output: 7
// Explanation: 7 = 4 * 3 / 2 + 1
// Example 2:

// Input: n = 10
// Output: 12
// Explanation: 12 = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1
 

// Constraints:

// 1 <= n <= 104

/*
Approach:
    This is an expression evalution problem. Refer to the solution to the question "227-Basic Calculator II".
*/

#include <vector>
#include <string>
#include <cctype>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int clumsy(int n) 
    {
        auto vct = toArray(n);
        vct = toSuffix(vct);
        stack<int> _stack {};
        for (const auto& str: vct)
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

    bool isOperator(const char& ch)
    {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

    bool isOperator(const string& str)
    {
        char ch = str.front();
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

    vector<string> toArray(int n)
    {
        vector<string> result {};
        string cur = "*";
       
        while (n > 0)
        {
            result.push_back(to_string(n));
            result.push_back(cur);
            if ("*" == cur)
            {
                cur = "/";
            }
            else if ("/" == cur)
            {
                cur = "+";
            }
            else if ("+" == cur)
            {
                cur = "-";
            }
            else if ("-" == cur)
            {
                cur = "*";
            }
            n -= 1;

        }
        result.pop_back();
        return result;
        
    }

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