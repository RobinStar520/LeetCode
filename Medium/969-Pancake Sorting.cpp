// Given an array of integers arr, sort the array by performing a series of pancake flips.

// In one pancake flip we do the following steps:

// Choose an integer k where 1 <= k <= arr.length.
// Reverse the sub-array arr[0...k-1] (0-indexed).
// For example, if arr = [3,2,1,4] and we performed a pancake flip choosing k = 3, we reverse the sub-array [3,2,1], so arr = [1,2,3,4] after the pancake flip at k = 3.

// Return an array of the k-values corresponding to a sequence of pancake flips that sort arr. Any valid answer that sorts the array within 10 * arr.length flips will be judged as correct.

 

// Example 1:

// Input: arr = [3,2,4,1]
// Output: [4,2,4,3]
// Explanation: 
// We perform 4 pancake flips, with k values 4, 2, 4, and 3.
// Starting state: arr = [3, 2, 4, 1]
// After 1st flip (k = 4): arr = [1, 4, 2, 3]
// After 2nd flip (k = 2): arr = [4, 1, 2, 3]
// After 3rd flip (k = 4): arr = [3, 2, 1, 4]
// After 4th flip (k = 3): arr = [1, 2, 3, 4], which is sorted.
// Example 2:

// Input: arr = [1,2,3]
// Output: []
// Explanation: The input is already sorted, so there is no need to flip anything.
// Note that other answers, such as [3, 3], would also be accepted.
 

// Constraints:

// 1 <= arr.length <= 100
// 1 <= arr[i] <= arr.length
// All integers in arr are unique (i.e. arr is a permutation of the integers from 1 to arr.length).

/*
Approach:
    This is a very funny question. The question doesn't ask us to find the optimal solution to sort the whole vector, as long as the length of the result 
is less than 10 * vector's size. We can use a greedy algorithm: First, find the maximum value of the vector, and then try to move it to the front(using reverse);
Second, reverse the whole vector to put the maximum value into the correct position. Until now, the last element has been in the correct position, to simplify the
process, we can pop it from the vector. Third, repeat the first and the second step until the vector becomes empty.
*/

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution 
{
public:
    vector<int> pancakeSort(vector<int>& arr) 
    {
        vector<int> result {};
        priority_queue<int, vector<int>> pq(arr.begin(), arr.end());
        
        while (arr.size() > 0)
        {
            
            int val = pq.top();
            pq.pop();
            auto iter = find(arr.begin(), arr.end(), val);
            int index = iter - arr.begin();
            result.push_back(index + 1);
            reverse(arr.begin(), iter + 1);
            result.push_back(static_cast<int>(arr.size()));
            reverse(arr.begin(), arr.end());
        
            arr.pop_back();
        }
        return result;
    }
};