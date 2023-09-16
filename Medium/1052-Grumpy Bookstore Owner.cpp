// There is a bookstore owner that has a store open for n minutes. Every minute, some number of customers enter the store. You are given an integer array customers of length n where customers[i] is the number of the customer that enters the store at the start of the ith minute and all those customers leave after the end of that minute.

// On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

// When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise, they are satisfied.

// The bookstore owner knows a secret technique to keep themselves not grumpy for minutes consecutive minutes, but can only use it once.

// Return the maximum number of customers that can be satisfied throughout the day.

 

// Example 1:

// Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
// Output: 16
// Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes. 
// The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.
// Example 2:

// Input: customers = [1], grumpy = [0], minutes = 1
// Output: 1
 

// Constraints:

// n == customers.length == grumpy.length
// 1 <= minutes <= n <= 2 * 104
// 0 <= customers[i] <= 1000
// grumpy[i] is either 0 or 1.

/*
Approach:
    For this problem, we should maximize profits. The question gives a range, so we need to separately calculate the number of customers who are not 
affected by the bookstore owner and the number of affected customers within this range, and calculate the difference between them. When this value is 
the largest, it means that we need to prevent customers within this range from being affected by the bookstore owner.
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {
        int result = 0;
        const int n = customers.size();
        int normal = 0, affected = 0;
        int left = -1, right = -1;
        for (int i=0; i<minutes; ++i)
        {
            normal += customers[i];
            if (grumpy[i] == 0)
            {
                affected += customers[i];
            }
        }

        // The current difference.
        int gap = normal - affected;
        if (gap > 0)
        {
            left = 0;
            right = minutes - 1;
        }
        for (int i=1; i<n-minutes+1; ++i)
        {
            int prevGap = gap;
            normal += customers[i + minutes - 1];
            normal -= customers[i - 1];
            if (grumpy[i - 1] == 0)
            {
                affected -= customers[i - 1];
            }
            if (grumpy[i + minutes - 1] == 0)
            {
                affected += customers[i + minutes - 1];
            }
            int curGap = normal - affected;
            if (curGap > prevGap)
            {
                gap = curGap;
                left = i;
                right = i + minutes - 1;
            }
        }
        if (left != -1 && right != -1)
        {
            for (int i=left; i<=right; ++i)
            {
                grumpy[i] = 0;
            }
        }
        for (int i=0; i<n; ++i)
        {
            if (grumpy[i] == 0)
            {
                result += customers[i];
            }
        }
        return result;
    }
};