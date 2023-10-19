// Given a list of phrases, generate a list of Before and After puzzles.

// A phrase is a string that consists of lowercase English letters and spaces only. No space appears in the start or the end of a phrase. There are no consecutive spaces in a phrase.

// Before and After puzzles are phrases that are formed by merging two phrases where the last word of the first phrase is the same as the first word of the second phrase.

// Return the Before and After puzzles that can be formed by every two phrases phrases[i] and phrases[j] where i != j. Note that the order of matching two phrases matters, we want to consider both orders.

// You should return a list of distinct strings sorted lexicographically.

 

// Example 1:

// Input: phrases = ["writing code","code rocks"]
// Output: ["writing code rocks"]
// Example 2:

// Input: phrases = ["mission statement",
//                   "a quick bite to eat",
//                   "a chip off the old block",
//                   "chocolate bar",
//                   "mission impossible",
//                   "a man on a mission",
//                   "block party",
//                   "eat my words",
//                   "bar of soap"]
// Output: ["a chip off the old block party",
//          "a man on a mission impossible",
//          "a man on a mission statement",
//          "a quick bite to eat my words",
//          "chocolate bar of soap"]
// Example 3:

// Input: phrases = ["a","b","a"]
// Output: ["a"]
 

// Constraints:

// 1 <= phrases.length <= 100
// 1 <= phrases[i].length <= 100

/*
Approach:
    The constraints are too small, so we can use a brute force algorithm.
*/

#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) 
    {
        set<string> result {};

        for (int i = 0; i < phrases.size(); ++i) 
        {
            for (int j = 0; j < phrases.size(); ++j) 
            {
                if (i != j) 
                {
                    vector<string> first = splitPhrase(phrases[i]);
                    vector<string> second = splitPhrase(phrases[j]);

                    if (first.back() == second.front()) 
                    {
                        string combined = combinePhrases(first, second, i, j);
                        result.insert(combined);
                    }
                }
            }
        }

        return vector<string>(result.begin(), result.end());
    }

private:
    vector<string> splitPhrase(const string& phrase) 
    {
        vector<string> words {};
        string word {};
        for (char c : phrase) 
        {
            if (c == ' ') 
            {
                words.push_back(word);
                word.clear();
            } 
            else 
            {
                word += c;
            }
        }
        words.push_back(word);
        return words;
    }

    string combinePhrases(const vector<string>& first, const vector<string>& second, int i, int j) {
        string combined {};
        for (int k = 0; k < first.size(); ++k) 
        {
            if (k < first.size() - 1)
            {
                combined += first[k] + " ";
            } 
            else 
            {
                combined += first[k];
            }
        }
        if (second.size() > 1) 
        {
            for (int k = 1; k < second.size(); ++k) 
            {
                combined += " " + second[k];
            }
        }
        return combined;
    }
};
