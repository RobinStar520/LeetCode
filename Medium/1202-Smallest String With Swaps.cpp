// You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

// You can swap the characters at any pair of indices in the given pairs any number of times.

// Return the lexicographically smallest string that s can be changed to after using the swaps.

 

// Example 1:

// Input: s = "dcab", pairs = [[0,3],[1,2]]
// Output: "bacd"
// Explaination: 
// Swap s[0] and s[3], s = "bcad"
// Swap s[1] and s[2], s = "bacd"
// Example 2:

// Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
// Output: "abcd"
// Explaination: 
// Swap s[0] and s[3], s = "bcad"
// Swap s[0] and s[2], s = "acbd"
// Swap s[1] and s[2], s = "abcd"
// Example 3:

// Input: s = "cba", pairs = [[0,1],[1,2]]
// Output: "abc"
// Explaination: 
// Swap s[0] and s[1], s = "bca"
// Swap s[1] and s[2], s = "bac"
// Swap s[0] and s[1], s = "abc"
 

// Constraints:

// 1 <= s.length <= 10^5
// 0 <= pairs.length <= 10^5
// 0 <= pairs[i][0], pairs[i][1] < s.length
// s only contains lower case English letters.

/*
Approach:
    We can use a greedy approach and a union-find data structure. The main point is splitting the characters in the string into different sets and sort
them individually.
*/

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <functional>

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
        return;
    }

    vector<int> getRoot()
    {
        return root;
    }

private:
    vector<int> root {};
};

class Solution 
{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        const int n = s.length();
        UnionFind* obj = new UnionFind(n);
        for (const auto& v: pairs)
        {
            obj->join(v[0], v[1]);
        }
        auto root = obj->getRoot();
        unordered_map<int, priority_queue<char, vector<char>, greater<char>>> _map {};
        for (int i = 0; i < n; ++i) 
        {
            int rootIndex = obj->find(i);
            _map[rootIndex].push(s[i]);
        }

        string result(n, ' ');
        for (int i = 0; i < n; ++i) 
        {
            int rootIndex = obj->find(i);
            result[i] = _map[rootIndex].top();
            _map[rootIndex].pop();
        }

        delete obj;
        return result;
    }
};