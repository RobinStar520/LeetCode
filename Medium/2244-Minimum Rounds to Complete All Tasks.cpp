// You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.

// Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

 

// Example 1:

// Input: tasks = [2,2,3,3,2,4,4,4,4,4]
// Output: 4
// Explanation: To complete all the tasks, a possible plan is:
// - In the first round, you complete 3 tasks of difficulty level 2. 
// - In the second round, you complete 2 tasks of difficulty level 3. 
// - In the third round, you complete 3 tasks of difficulty level 4. 
// - In the fourth round, you complete 2 tasks of difficulty level 4.  
// It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.
// Example 2:

// Input: tasks = [2,3,3]
// Output: -1
// Explanation: There is only 1 task of difficulty level 2, but in each round, you can only complete either 2 or 3 tasks of the same difficulty level. Hence, you cannot complete all the tasks, and the answer is -1.
 

// Constraints:

// 1 <= tasks.length <= 105
// 1 <= tasks[i] <= 109

/*
Approach:
    Actually, this is a simple mathematical question. We need to check whether an integer can be written as 2x + 3y. If an integer mod 3 isn't zero, 
the only thing we can do is divide it by three and then add one.
*/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int minimumRounds(vector<int>& tasks) 
    {
        unordered_map<int, int> _map {};
        int result = 0;
        for (const auto& i: tasks)
        {
            _map[i] += 1;
        }
        for (const auto& [num, count]: _map)
        {
            if (count == 1)
            {
                return -1;
            }
            if (count % 3 == 0)
            {
                result += count / 3;
            }
            else
            {
                result += count / 3 + 1;
            }
        }

        return result;
    }
};