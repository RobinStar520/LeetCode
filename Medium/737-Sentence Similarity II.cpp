// We can represent a sentence as an array of words, for example, the sentence "I am happy with leetcode" can be represented as arr = ["I","am",happy","with","leetcode"].

// Given two sentences sentence1 and sentence2 each represented as a string array and given an array of string pairs similarPairs where similarPairs[i] = [xi, yi] indicates that the two words xi and yi are similar.

// Return true if sentence1 and sentence2 are similar, or false if they are not similar.

// Two sentences are similar if:

// They have the same length (i.e., the same number of words)
// sentence1[i] and sentence2[i] are similar.
// Notice that a word is always similar to itself, also notice that the similarity relation is transitive. For example, if the words a and b are similar, and the words b and c are similar, then a and c are similar.

 

// Example 1:

// Input: sentence1 = ["great","acting","skills"], sentence2 = ["fine","drama","talent"], similarPairs = [["great","good"],["fine","good"],["drama","acting"],["skills","talent"]]
// Output: true
// Explanation: The two sentences have the same length and each word i of sentence1 is also similar to the corresponding word in sentence2.
// Example 2:

// Input: sentence1 = ["I","love","leetcode"], sentence2 = ["I","love","onepiece"], similarPairs = [["manga","onepiece"],["platform","anime"],["leetcode","platform"],["anime","manga"]]
// Output: true
// Explanation: "leetcode" --> "platform" --> "anime" --> "manga" --> "onepiece".
// Since "leetcode is similar to "onepiece" and the first two words are the same, the two sentences are similar.
// Example 3:

// Input: sentence1 = ["I","love","leetcode"], sentence2 = ["I","love","onepiece"], similarPairs = [["manga","hunterXhunter"],["platform","anime"],["leetcode","platform"],["anime","manga"]]
// Output: false
// Explanation: "leetcode" is not similar to "onepiece".
 

// Constraints:

// 1 <= sentence1.length, sentence2.length <= 1000
// 1 <= sentence1[i].length, sentence2[i].length <= 20
// sentence1[i] and sentence2[i] consist of lower-case and upper-case English letters.
// 0 <= similarPairs.length <= 2000
// similarPairs[i].length == 2
// 1 <= xi.length, yi.length <= 20
// xi and yi consist of English letters.

/*
Approach:
    This is a typical graph problem that uses a union-find data structure. You can also use a BFS or DFS approach, but their efficiency is worse than
using a union-find data structure. We should use a promoted edition union-find structure to suit the string type.
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template <typename T>
class UnionFind
{
public:
    UnionFind(vector<T> elements)
    {
        for (const auto& element : elements) 
        {
            if (!elementToId.count(element)) 
            {
                elementToId[element] = element;
            }
        }
    }
    

    T find(T& element) 
    {
        if (element != elementToId[element]) 
        {
            elementToId[element] = find(elementToId[element]); // Path compression
        }
        return elementToId[element];
    }

    void unionElements(T a, T b) 
    {
        T rootA = find(a);
        T rootB = find(b);

        if (rootA != rootB) {
            elementToId[rootB] = rootA;
        }
    }

    bool isSame(T& a, T& b)
    {
        a = find(a);
        b = find(b);
        return a == b;
    }

private:
    unordered_map<T, T> elementToId;
};

class Solution 
{
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) 
    {
        if (sentence1.size() != sentence2.size())
        {
            return false;
        }
        if (sentence1 == sentence2)
        {
            return true;
        }
        if (similarPairs.empty())
        {
            return false;
        }
        const int n = sentence1.size();
        unordered_set<string> _set {};
        for(const auto& v: similarPairs)
        {
            _set.insert(v[0]);
            _set.insert(v[1]);
        }
        UnionFind<string>* obj = new UnionFind<string>(vector<string>(_set.begin(), _set.end()));
        for (const auto& v: similarPairs)
        {
            obj->unionElements(v[0], v[1]);
        }
        for (int i=0; i<n; ++i)
        {
            if (!obj->isSame(sentence1[i], sentence2[i]))
            {
                return false;
            }
        }
        delete obj;
        return true;

    }
};