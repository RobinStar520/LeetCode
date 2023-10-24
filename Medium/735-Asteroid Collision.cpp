// We are given an array asteroids of integers representing asteroids in a row.

// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

// Example 1:

// Input: asteroids = [5,10,-5]
// Output: [5,10]
// Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
// Example 2:

// Input: asteroids = [8,-8]
// Output: []
// Explanation: The 8 and -8 collide exploding each other.
// Example 3:

// Input: asteroids = [10,2,-5]
// Output: [10]
// Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 

// Constraints:

// 2 <= asteroids.length <= 104
// -1000 <= asteroids[i] <= 1000
// asteroids[i] != 0

/*
Approach:
    We can use a stack to store the asteroid we visited.
*/

#include <vector>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> _stack {};
        vector<int> result {};
        for (const auto& i: asteroids)
        {
            bool flag = true;
            while (!_stack.empty() && (_stack.top() > 0 && i < 0))
            {
                if (std::abs(_stack.top()) < std::abs(i))
                {
                    _stack.pop();
                    continue;
                }
                else if (std::abs(_stack.top()) == std::abs(i))
                {
                    _stack.pop();
                }
                flag = false;
                break;
            }
            if (flag)
            {
                _stack.push(i);
            }
        }

        while (!_stack.empty())
        {
            result.push_back(_stack.top());
            _stack.pop();
        }
        reverse(result.begin(), result.end());

        return result;

    }
};