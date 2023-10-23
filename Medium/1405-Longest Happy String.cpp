// A string s is called happy if it satisfies the following conditions:

// s only contains the letters 'a', 'b', and 'c'.
// s does not contain any of "aaa", "bbb", or "ccc" as a substring.
// s contains at most a occurrences of the letter 'a'.
// s contains at most b occurrences of the letter 'b'.
// s contains at most c occurrences of the letter 'c'.
// Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".

// A substring is a contiguous sequence of characters within a string.

 

// Example 1:

// Input: a = 1, b = 1, c = 7
// Output: "ccaccbcc"
// Explanation: "ccbccacc" would also be a correct answer.
// Example 2:

// Input: a = 7, b = 1, c = 0
// Output: "aabaa"
// Explanation: It is the only correct answer in this case.
 

// Constraints:

// 0 <= a, b, c <= 100
// a + b + c > 0

/*
Approach:
    We can use a greedy algorithm. We peek at the letter with the largest frequency and append it to the result each time.
*/

#include <string>
#include <algorithm>
#include <queue>

using namespace std;


class Solution 
{

public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pair<int,char>> pq {};
        if (a > 0)
        {
            pq.push({a,'a'});
        }
        if (b > 0)
        {
            pq.push({b,'b'});
        }
        if (c > 0)
        {
            pq.push({c,'c'});
        }
        
        string ans {};
        while(pq.size() > 1)
        {
            int topFreq1 =  pq.top().first;
            char topChar1 = pq.top().second;
            pq.pop();
            if (topFreq1 > 1)
            {
                ans += topChar1;
                ans += topChar1;
                topFreq1 -= 2;
            }
            else
            {
                ans += topChar1;
                topFreq1 -= 1;
            }
            int topFreq2 =  pq.top().first;
            char topChar2 = pq.top().second;
            pq.pop();
			
			
            if (topFreq2 > 1 and topFreq2 >= topFreq1)
            {
                ans += topChar2;
                ans += topChar2;
                topFreq2 -= 2;
            }
            else
            {
                ans += topChar2;
                topFreq2 -= 1;
            }
            if (topFreq1 > 0)
            {
                pq.push({topFreq1,topChar1});
            }
            if (topFreq2 > 0)
            {
                pq.push({topFreq2,topChar2});
            }
        }
        
        while(!pq.empty())
        {
            int leftFreq = pq.top().first;
            char leftChar = pq.top().second;
            pq.pop();
            
            if (leftFreq > 1)
            {
                ans += leftChar;
                ans += leftChar;
                leftFreq -= 2;
            }
            else
            {
                ans += leftChar;
                leftFreq -= 1;
            }
        }
        return ans;
    }
};
