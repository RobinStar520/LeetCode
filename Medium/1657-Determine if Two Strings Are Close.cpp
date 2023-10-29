// Two strings are considered close if you can attain one from the other using the following operations:

// Operation 1: Swap any two existing characters.
// For example, abcde -> aecdb
// Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
// For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
// You can use the operations on either string as many times as necessary.

// Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.

 

// Example 1:

// Input: word1 = "abc", word2 = "bca"
// Output: true
// Explanation: You can attain word2 from word1 in 2 operations.
// Apply Operation 1: "abc" -> "acb"
// Apply Operation 1: "acb" -> "bca"
// Example 2:

// Input: word1 = "a", word2 = "aa"
// Output: false
// Explanation: It is impossible to attain word2 from word1, or vice versa, in any number of operations.
// Example 3:

// Input: word1 = "cabbba", word2 = "abbccc"
// Output: true
// Explanation: You can attain word2 from word1 in 3 operations.
// Apply Operation 1: "cabbba" -> "caabbb"
// Apply Operation 2: "caabbb" -> "baaccc"
// Apply Operation 2: "baaccc" -> "abbccc"
 

// Constraints:

// 1 <= word1.length, word2.length <= 105
// word1 and word2 contain only lowercase English letters.

/*
Approach:
    For this question, we should pay attention to these points: 1.The sets of letters that make up both strings should be exactly the same.
2. The frequency of each character of two strings should equal.
*/

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

class Solution 
{
public:
    bool closeStrings(string word1, string word2) 
    {
        if (word1.length() != word2.length()) 
         {
            return false;
        }

        unordered_map<char, int> map1 {}, map2 {};
        unordered_set<char> chars1(word1.begin(), word1.end());
        unordered_set<char> chars2(word2.begin(), word2.end());
        if (chars1 != chars2)
        {
            return false;
        }
        const int n = word1.length();
        for (int i = 0; i < n; ++i) 
        {
            map1[word1[i]]++;
            map2[word2[i]]++; 
        }

        vector<int> freq1 {}, freq2 {};

        for (const auto& item : map1) 
        {
            freq1.push_back(item.second);
        }

        for (const auto& item : map2) 
        {
            freq2.push_back(item.second);
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        return freq1 == freq2;
    }
};