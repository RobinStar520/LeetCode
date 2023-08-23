// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.

 

// Example 1:

// Input: s = "aab"
// Output: "aba"
// Example 2:

// Input: s = "aaab"
// Output: ""
 

// Constraints:

// 1 <= s.length <= 500
// s consists of lowercase English letters.

/*
Approach:
    Obviously, this is a heap relative question. First we use a hash table to count the occurrence of each word, and then we maintain a maximum heap, 
every time we just the element that has the maximum occurrence, until the size of the heap becomes one. Pay attention to the last element in the heap.
*/

#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

// Define the comparision function. The existance of this function depends on how to use the key-value relationship. If you set the occurrence of 
// each element as the key, ignore this step.
struct Comp
{
public:
    bool operator()(const pair<char, int>& p1, const pair<char, int>& p2) const
    {
        return p1.second < p2.second;
    }
};
class Solution 
{
public:
    string reorganizeString(string s) 
    {
        // Use a unordered_map instead of a map since for this question, it's unnecessary for us to sort the elements in the hash table.
        unordered_map<char, int> _map {};
        for (const auto& ch: s)
        {
            _map[ch] ++;
        }
        string result {};
        priority_queue<pair<char, int>, vector<pair<char, int>>, Comp> pq(_map.begin(), _map.end());
        // Be aware of the loop end condition
        while (pq.size() > 1)
        {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            result.push_back(p1.first);
            result.push_back(p2.first);
            if (p1.second > 1)
            {
                p1.second -= 1;
                pq.push(p1);
            }
            if (p2.second > 1)
            {
                p2.second -= 1;
                pq.push(p2);
            }
        }
        // Don't forget the last element in the heap.
        // There are three different situations.
        if (!pq.empty() && pq.top().second == 1)
        {
            result.push_back(pq.top().first);
        }
        if (pq.top().second > 1)
        {
            result = {};
        }
        return result;
    }
};