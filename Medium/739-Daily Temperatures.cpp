// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]
 

// Constraints:

// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100

/*
Approach:
    This is a beginner-level question about using a monotonic stack. Formally, this question asks us to find the next element greater than the current element. For this kind
of question, the first impression of many people is to use the brute force algorithm, use two for-loops started from the current index to find the next greater element,
the time complexity is O(n ^ 2), and space complexity is O(1). This approach will cost a long time since the length of the temperature vector is too long, so it's not an 
efficient method.
    For this kind of question, using a monotonic stack is a good choice, which is an idea of exchanging sapce for time. We use a stack to record the elements we have visited,
This stack should be monotonic growth so that the top value of the stack represents the first greater value we need to find. Moreover, what we should store in the stack is also
a problem we should consider. Different questions have different situations, for this question, we should put the index of the elements in the temperatures vector to the 
stack since the question asks us to find the distance instead of the actual temperature.
    If we use a monotonic stack, the time complexity of our algorithm will reduce to O(n).
*/

#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution 
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        const int n = temperatures.size();
        vector<int> result(n, 0);
        // This stack only contains the index of the "temperatures" vector.
        stack<int> _stack {};
        for (int i=0; i<n; ++i)
        {
            // This while loop is important. First, ensure the stack is not empty; Second, because the stack contains the index of the value, we compare the value
            // via the index located on the top of the stack with the current value, if the current value is larger, we pop the top value of the stack until we can't
            // find such a value, or the stack becomes empty.
            while (!_stack.empty() && temperatures[i] > temperatures[_stack.top()])
            {
                // Remember to use an extra variable to store the top value of the stack.
                int index = _stack.top();
                _stack.pop();
                // Fill the result based on the index.
                result[index] = i - index;
            }
            _stack.push(i);
        }
        return result;
    }
};