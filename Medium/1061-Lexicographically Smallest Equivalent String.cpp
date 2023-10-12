// You are given two strings of the same length s1 and s2 and a string baseStr.

// We say s1[i] and s2[i] are equivalent characters.

// For example, if s1 = "abc" and s2 = "cde", then we have 'a' == 'c', 'b' == 'd', and 'c' == 'e'.
// Equivalent characters follow the usual rules of any equivalence relation:

// Reflexivity: 'a' == 'a'.
// Symmetry: 'a' == 'b' implies 'b' == 'a'.
// Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'.
// For example, given the equivalency information from s1 = "abc" and s2 = "cde", "acd" and "aab" are equivalent strings of baseStr = "eed", and "aab" is the lexicographically smallest equivalent string of baseStr.

// Return the lexicographically smallest equivalent string of baseStr by using the equivalency information from s1 and s2.

 

// Example 1:

// Input: s1 = "parker", s2 = "morris", baseStr = "parser"
// Output: "makkek"
// Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [m,p], [a,o], [k,r,s], [e,i].
// The characters in each group are equivalent and sorted in lexicographical order.
// So the answer is "makkek".
// Example 2:

// Input: s1 = "hello", s2 = "world", baseStr = "hold"
// Output: "hdld"
// Explanation: Based on the equivalency information in s1 and s2, we can group their characters as [h,w], [d,e,o], [l,r].
// So only the second letter 'o' in baseStr is changed to 'd', the answer is "hdld".
// Example 3:

// Input: s1 = "leetcode", s2 = "programs", baseStr = "sourcecode"
// Output: "aauaaaaada"
// Explanation: We group the equivalent characters in s1 and s2 as [a,o,e,r,s,c], [l,p], [g,t] and [d,m], thus all letters in baseStr except 'u' and 'd' are transformed to 'a', the answer is "aauaaaaada".
 

// Constraints:

// 1 <= s1.length, s2.length, baseStr <= 1000
// s1.length == s2.length
// s1, s2, and baseStr consist of lowercase English letters.

/*
Approach:
    A boring question! We need to use a union-find data structure to gather equivalent letters into the same group and then replace each letter in 
the target string with the smallest equivalent letter.
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class UnionFind
{
public:
    explicit UnionFind(int n)
    {
        root = vector<int>(n, 0);
        init();
    }

    void init()
    {
        for (int i=0; i<root.size(); ++i)
        {
            root[i] = i;
        }
    }

    int find(int a)
    {
        return a == root[a] ? a : root[a] = find(root[a]);
    }

    bool isSame(int a, int b)
    {
        a = find(a);
        b = find(b);
        return a == b;
    }

    void join(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
        {
            return;
        }
        root[b] = a;
    }

private:
    vector<int> root {};
};

class Solution 
{
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        string result {};
        UnionFind* obj = new UnionFind(26);
        unordered_map<char, set<char>> map1 {};
        const int n = s1.length();
        for (int i=0; i<n; ++i)
        {
            obj->join(s1[i] - 'a', s2[i] - 'a');         
        }
        for (int i=0; i<n; ++i)
        {
            if (obj->isSame(s1[i] - 'a', s2[i] - 'a'))
            {
                int index = obj->find(s1[i] - 'a');
                map1[index + 'a'].insert(s2[i]);
                map1[index + 'a'].insert(s1[i]);
            }
        }

        
        for (const auto& ch: baseStr)
        {
            if (map1.find(ch) != map1.end())
            {
                result.push_back(std::min(*map1[ch].begin(), ch));
            }
            else
            {
                bool flag = false;
                for (const auto& [key, _set]: map1)
                {
                    if (_set.find(ch) != _set.end())
                    {
                        result.push_back(std::min(*_set.begin(), key));
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                {
                    result.push_back(ch);
                }
            }
        }

        delete obj;
        return result;
    }
};