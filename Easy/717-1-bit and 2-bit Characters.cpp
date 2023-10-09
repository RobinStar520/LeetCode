// 717. 1-bit and 2-bit Characters
// Solved
// Easy
// Topics
// Companies
// Hint
// We have two special characters:

// The first character can be represented by one bit 0.
// The second character can be represented by two bits (10 or 11).
// Given a binary array bits that ends with 0, return true if the last character must be a one-bit character.

 

// Example 1:

// Input: bits = [1,0,0]
// Output: true
// Explanation: The only way to decode it is two-bit character and one-bit character.
// So the last character is one-bit character.
// Example 2:

// Input: bits = [1,1,1,0]
// Output: false
// Explanation: The only way to decode it is two-bit character and two-bit character.
// So the last character is not one-bit character.
 

// Constraints:

// 1 <= bits.length <= 1000
// bits[i] is either 0 or 1.

/*
Approach:
    For this question, as long as we can ensure the last number of the vector is zero after removing all the 1-bit and 2-bit characters. We can use an 
auxiliary queue to simulate the process.
*/

#include <vector>
#include <queue>

using namespace std;

class Solution 
{
public:
    bool isOneBitCharacter(vector<int>& bits) 
    {
        queue<int> q {};
        for (const auto& i: bits)
        {
            q.push(i);
        }
        while (!q.empty())
        {
            if (q.size() == 1 || q.empty())
            {
                break;
            }
            if (q.front() == 1)
            {
                q.pop();
                q.pop();
            }
            else
            {
                q.pop();
            }
        }

        return (q.empty() || q.front() != 0) ? false : true;
    }
};