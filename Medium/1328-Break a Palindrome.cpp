// Given a palindromic string of lowercase English letters palindrome, replace exactly one character with any lowercase English letter so that the resulting string is not a palindrome and that it is the lexicographically smallest one possible.

// Return the resulting string. If there is no way to replace a character to make it not a palindrome, return an empty string.

// A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, a has a character strictly smaller than the corresponding character in b. For example, "abcc" is lexicographically smaller than "abcd" because the first position they differ is at the fourth character, and 'c' is smaller than 'd'.

 

// Example 1:

// Input: palindrome = "abccba"
// Output: "aaccba"
// Explanation: There are many ways to make "abccba" not a palindrome, such as "zbccba", "aaccba", and "abacba".
// Of all the ways, "aaccba" is the lexicographically smallest.
// Example 2:

// Input: palindrome = "a"
// Output: ""
// Explanation: There is no way to replace a single character to make "a" not a palindrome, so return an empty string.
 

// Constraints:

// 1 <= palindrome.length <= 1000
// palindrome consists of only lowercase English letters.

/*
Approach:
    For this question, we can use a greedy approach. The first and second letter in the alphabet is a and b, so we just use two of them to replace
the letter in the palindrome, and that's enough. Pay attention to some special test cases, like "aba". Changing the first 'b to 'a' will form
a new palindrome, so make sure you have the right checking condition.
*/

#include <string>

using namespace std;

class Solution 
{
public:
    string breakPalindrome(string palindrome) 
    {
        const int n = palindrome.length();
        // If there is a single letter in the palindrome, which means we can't break it via transform.
        if (n == 1)
        {
            return {};
        }
        int count = 0;
        for (const auto& ch: palindrome)
        {
            if (ch == 'a')
            {
                count += 1;
            }
        }
        // "n - 1" is to check some special test cases like "aba".
        if (count == n || count == n - 1)
        {
            palindrome[n - 1] = 'b';
        }

        else
        {
            for (int i=0; i<n; ++i)
            {
                if (palindrome[i] != 'a')
                {
                    palindrome[i] = 'a';
                    break;
                }
            }
        }
        return palindrome;
    }
};