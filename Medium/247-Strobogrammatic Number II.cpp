// Given an integer n, return all the strobogrammatic numbers that are of length n. You may return the answer in any order.

// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

 

// Example 1:

// Input: n = 2
// Output: ["11","69","88","96"]
// Example 2:

// Input: n = 1
// Output: ["0","1","8"]
 

// Constraints:

// 1 <= n <= 14

/*
Approach:
    This is a backtracking relative problem. It will lead to the time limit being exceeded if we generate all the possible cases using brute force. Actually, for
every valid strobogrammatic number must be centrosymmetric, so we need to develop half of the length of a good number and then attempt to add the last part.
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<string> findStrobogrammatic(int n) 
    {
        if (n == 1)
        {
            return {"0", "1", "8"};
        }
        unordered_map<char, char> _map {
            {'1', '1'}, {'0', '0'}, {'6', '9'}, {'8', '8'}, {'9', '6'}
        };
        vector<string> result {}, ans {};
        string digits = "01689";
        string odds = "018";
        string item {};
        backtracking(item, digits, result, n);
        for (const auto& str: result)
        {
            if (str.front() == 0)
            {
                continue;
            }
            if (n % 2 == 0)
            {
                string copy = str;
                if (copy.front() == '0')
                {
                    continue;
                }
                copy += _map[str.back()];
                for (int i=n / 2-2; i>=0; --i)
                {
                    copy.push_back(_map[str[i]]);
                }
                ans.push_back(copy);
            }
            else
            {
                if (str.front() == '0')
                {
                    continue;
                }
                
                for (const auto& ch: odds)
                {
                    string copy = str;
                    string right = copy;
                    reverse(right.begin(), right.end());
                    for (int j=0; j<right.length(); ++j)
                    {
                        right[j] = _map[right[j]];
                    }
                    copy.push_back(ch);
                    copy += right;
                    ans.push_back(copy);
                }
                
            }

        }
        return ans;
    }

private:
    void backtracking(string& item, string& digits, vector<string>& result, int n)
    {
        if (item.length() == n / 2)
        {
            result.push_back(item);
            return;
        }
        for (int i=0; i<5 && item.front() != '0'; ++i)
        {
            item.push_back(digits[i]);
            backtracking(item, digits, result, n);
            item.pop_back();
        }
        return;
    }
};