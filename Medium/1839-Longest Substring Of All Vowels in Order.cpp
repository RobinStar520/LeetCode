// A string is considered beautiful if it satisfies the following conditions:

// Each of the 5 English vowels ('a', 'e', 'i', 'o', 'u') must appear at least once in it.
// The letters must be sorted in alphabetical order (i.e. all 'a's before 'e's, all 'e's before 'i's, etc.).
// For example, strings "aeiou" and "aaaaaaeiiiioou" are considered beautiful, but "uaeio", "aeoiu", and "aaaeeeooo" are not beautiful.

// Given a string word consisting of English vowels, return the length of the longest beautiful substring of word. If no such substring exists, return 0.

// A substring is a contiguous sequence of characters in a string.

 

// Example 1:

// Input: word = "aeiaaioaaaaeiiiiouuuooaauuaeiu"
// Output: 13
// Explanation: The longest beautiful substring in word is "aaaaeiiiiouuu" of length 13.
// Example 2:

// Input: word = "aeeeiiiioooauuuaeiou"
// Output: 5
// Explanation: The longest beautiful substring in word is "aeiou" of length 5.
// Example 3:

// Input: word = "a"
// Output: 0
// Explanation: There is no beautiful substring, so return 0.
 

// Constraints:

// 1 <= word.length <= 5 * 105
// word consists of characters 'a', 'e', 'i', 'o', and 'u'.

/*
Approach:
    Recently, I learned something about NFA and DFA, so I tried to use the relative theories here.
*/

#include <string>
#include <algorithm>

using namespace std;

// Define BFA class.
class DFA
{
public:
    DFA() : currentState(q0)
    {
        
    }

    int getCurrentState()
    {
        return this->currentState;
    }

    
    void setState(int state)
    {
        this->currentState = static_cast<State>(state);
    }

    void transform(char ch) 
    {
        switch (ch) 
        {
            case 'a':
                if (currentState == q0 || currentState == q1) 
                {
                    currentState = q1;
                } 
                else 
                {
                    currentState = DEAD;
                }
                break;
            case 'e':
                if (currentState == q1 || currentState == q2) 
                {
                    currentState = q2;
                } 
                else 
                {
                    currentState = DEAD;
                }
                break;
            case 'i':
                if (currentState == q2 || currentState == q3) 
                {
                    currentState = q3;
                } 
                else 
                {
                    currentState = DEAD;
                }
                break;
            case 'o':
                if (currentState == q3 || currentState == q4) 
                {
                    currentState = q4;
                } 
                else 
                {
                    currentState = DEAD;
                }
                break;
            case 'u':
                if (currentState == q4 || currentState == q5) 
                {
                    currentState = q5;
                } 
                else 
                {
                    currentState = DEAD;
                }
                break;
            
            default:
                break;
        }
    }

private:
    enum State {
        q0, q1, q2, q3, q4, q5, DEAD
    };

    State currentState;
};

class Solution 
{
public:
    int longestBeautifulSubstring(string word) 
    {
        DFA dfa {};
        const int n = word.length();
        int result = 0;
        int start = 0;
        bool flag = false;
        for (int i=0; i<n; ++i)
        {
            dfa.transform(word[i]);
            auto state = dfa.getCurrentState();
            if (word[i] == 'a' && !flag)
            {
                start = i;
                flag = true;
            }
            if (state == 6)
            {
                if (word[i] == 'a')
                {
                    dfa.setState(1);
                    start = i;
                    flag = true;
                }
                else
                {
                    dfa.setState(0);
                    flag = false;
                }

            }
            else if (state == 5)
            {
                result = std::max(result, i - start + 1);
                
                flag = false;
                // cout << start << "," << i << endl;
            }
            else
            {
                continue;
            }
            
        }
        
        return result;
    }
};