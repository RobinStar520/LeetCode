// A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

// Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

// For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
// There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

// Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

// Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

// Example 1:

// Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
// Output: 1
// Example 2:

// Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
// Output: 2
 

// Constraints:

// 0 <= bank.length <= 10
// startGene.length == endGene.length == bank[i].length == 8
// startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].

/*
Approach:
    This is a graph problem. We need to find the shortest path from the "startGene" to the "endGene". We can use BFS to solve it.
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution 
{
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        string gene = "ACGT";
        unordered_set<string> _bank(bank.begin(), bank.end());
        unordered_set<string> visited {};
        queue<string> q {};
        int result = 0;
        q.push(startGene);
        visited.insert(startGene);
        // Start the BFS.
        while (!q.empty())
        {
            int n = q.size();
            while (n --)
            {
                string seq = q.front();
                q.pop();

                if (seq == endGene)
                {
                    return result;
                }

                for (const auto& ch: gene)
                {
                    for (int i=0; i<seq.length(); ++i)
                    {
                        string node = seq;
                        node[i] = ch;
                        if (visited.find(node) == visited.end() && _bank.find(node) != _bank.end())
                        {
                            q.push(node);
                            visited.insert(node);
                        }
                    }
                }
            }

            result += 1;
        }

        return -1;
    }
};