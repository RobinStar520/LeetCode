// You have a keypad with 9 buttons, numbered from 1 to 9, each mapped to lowercase English letters. You can choose which characters each button is matched to as long as:

// All 26 lowercase English letters are mapped to.
// Each character is mapped to by exactly 1 button.
// Each button maps to at most 3 characters.
// To type the first character matched to a button, you press the button once. To type the second character, you press the button twice, and so on.

// Given a string s, return the minimum number of keypresses needed to type s using your keypad.

// Note that the characters mapped to by each button, and the order they are mapped in cannot be changed.

 

// Example 1:


// Input: s = "apple"
// Output: 5
// Explanation: One optimal way to setup your keypad is shown above.
// Type 'a' by pressing button 1 once.
// Type 'p' by pressing button 6 once.
// Type 'p' by pressing button 6 once.
// Type 'l' by pressing button 5 once.
// Type 'e' by pressing button 3 once.
// A total of 5 button presses are needed, so return 5.
// Example 2:


// Input: s = "abcdefghijkl"
// Output: 15
// Explanation: One optimal way to setup your keypad is shown above.
// The letters 'a' to 'i' can each be typed by pressing a button once.
// Type 'j' by pressing button 1 twice.
// Type 'k' by pressing button 2 twice.
// Type 'l' by pressing button 3 twice.
// A total of 15 button presses are needed, so return 15.
 

// Constraints:

// 1 <= s.length <= 105
// s consists of lowercase English letters.

/*
Approach:
    It's unnecessary to build a real keyboard. We need to count the frequency of each work. For those letters that we will use the most times, 
we should press them the least times, which means we need to place them at the front.
*/

#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution 
{
public:
    int minimumKeypresses(string s) 
    {
        unordered_map<char, int> _map {};
        unordered_map<char, int> keyMap {};
        // Denote the current total number of the letter at position(first, second, third)
        int first = 0, second = 0, third = 0;
        int result = 0;
        for (const auto& ch: s)
        {
            _map[ch] ++;
        }
        vector<pair<char, int>> temp(_map.begin(), _map.end());
        // Sort the vector based on the frequency of each letter.
        sort(temp.begin(), temp.end(), [&](pair<char, int>& p1, pair<char, int>& p2) -> bool {
            return p1.second > p2.second;
        });
        for (const auto& [ch, count]: temp)
        {
            if (first < 9)
            {
                keyMap[ch] = 1;
                first += 1;
                continue;
            }
            else if (second < 9)
            {
                keyMap[ch] = 2;
                second += 1;
                continue;
            }
            else
            {
                keyMap[ch] = 3;
                third += 1;
                continue;
            }
        }

        for (const auto& ch: s)
        {
            result += keyMap[ch];
        }
        return result;
    }
};