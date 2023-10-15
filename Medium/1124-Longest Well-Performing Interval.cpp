// We are given hours, a list of the number of hours worked per day for a given employee.

// A day is considered to be a tiring day if and only if the number of hours worked is (strictly) greater than 8.

// A well-performing interval is an interval of days for which the number of tiring days is strictly larger than the number of non-tiring days.

// Return the length of the longest well-performing interval.

 

// Example 1:

// Input: hours = [9,9,6,0,6,6,9]
// Output: 3
// Explanation: The longest well-performing interval is [9,9,6].
// Example 2:

// Input: hours = [6,6,6]
// Output: 0
 

// Constraints:

// 1 <= hours.length <= 104
// 0 <= hours[i] <= 16

/*
Approach:
    For this question, we can make a new array A of +1/-1s corresponding to if hours[i] is > 8 or not. The goal is to find the longest subarray with 
positive sum. Use a hashmap to track the current sum.
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int longestWPI(vector<int>& hours) 
    {
        unordered_map<int, int> _map {};
        const int n = hours.size();
        int sum = 0;
        int result = 0;
        for (int i=0; i<n; ++i)
        {
            if (hours[i] > 8)
            {
                sum += 1;
            }
            else
            {
                sum -= 1;
            }
            if (sum > 0)
            {
                result = 1 + i;
            }
            else
            {
                if (_map.find(sum) == _map.end())
                {
                    _map[sum] = i;
                }
                if (_map.find(sum - 1) != _map.end())
                {
                    result = max(result, i - _map[sum - 1]);
                }
            }

        }

        return result;
    }
};