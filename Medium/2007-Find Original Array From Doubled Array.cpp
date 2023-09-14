// An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.

// Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.

 

// Example 1:

// Input: changed = [1,3,4,2,6,8]
// Output: [1,3,4]
// Explanation: One possible original array could be [1,3,4]:
// - Twice the value of 1 is 1 * 2 = 2.
// - Twice the value of 3 is 3 * 2 = 6.
// - Twice the value of 4 is 4 * 2 = 8.
// Other original arrays could be [4,3,1] or [3,1,4].
// Example 2:

// Input: changed = [6,3,0,1]
// Output: []
// Explanation: changed is not a doubled array.
// Example 3:

// Input: changed = [1]
// Output: []
// Explanation: changed is not a doubled array.
 

// Constraints:

// 1 <= changed.length <= 105
// 0 <= changed[i] <= 105

/*
Approach:
    For this question, we need to use a greedy algorithm. First, count the frequency of each number. We should be aware of the zero because 0 * 2 = 0.
We must remove all the zeros from the original vector, and judge the zero individually. Second, sort the vector; Third, traverse the vector and inspect 
the container used to hold the frequency of numbers in the vector. Once we find a number and number * 2 simultaneously, remove it from the container 
and append it to the result vector; Last, check the result vector's length. If the length doesn't equal half of the original vector's length(removed 
zeros), return an empty vector; If it satisfies the previous condition, inspect whether the number of zeros is an even number. If it is. return the 
result vector, otherwise return an empty vector.
*/

#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<int> findOriginalArray(vector<int>& changed) 
    {
        vector<int> result {};
        // An auxiliary vector to contain numbers without 0.
        vector<int> vct {};
        
        if (changed.size() % 2 != 0)
        {
            return result;
        }
        unordered_map<int, int> _map {};
        for (const auto& i: changed)
        {
            if (i != 0)
            {
                vct.push_back(i);
            }
            _map[i] ++;
        }

        sort(vct.begin(), vct.end());
        int zeros = 0;
        // First, remove zero.
        if (_map.find(0) != _map.end())
        {
            zeros = _map[0];
            _map.erase(0);
        }
        if (zeros % 2 != 0)
        {
            return {};
        }
        for (const auto& num: vct)
        {
            if (_map.find(num * 2) != _map.end() && _map.find(num) != _map.end())
            {
                result.push_back(num);
                _map[num] --;
                _map[num * 2] --;
                if (_map[num] <= 0)
                {
                    _map.erase(num);
                }
                if (_map[num * 2] <= 0)
                {
                    _map.erase(num * 2);
                }
            }
        }
        // Inspect the number of zero.
        for (int i=0; i<zeros/2; ++i)
        {
            result.push_back(0);
        }
        return result.size() * 2 == changed.size() ? result : vector<int>();
    }
};