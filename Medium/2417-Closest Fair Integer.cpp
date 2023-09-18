// You are given a positive integer n.

// We call an integer k fair if the number of even digits in k is equal to the number of odd digits in it.

// Return the smallest fair integer that is greater than or equal to n.

 

// Example 1:

// Input: n = 2
// Output: 10
// Explanation: The smallest fair integer that is greater than or equal to 2 is 10.
// 10 is fair because it has an equal number of even and odd digits (one odd digit and one even digit).
// Example 2:

// Input: n = 403
// Output: 1001
// Explanation: The smallest fair integer that is greater than or equal to 403 is 1001.
// 1001 is fair because it has an equal number of even and odd digits (two odd digits and two even digits).
 

// Constraints:

// 1 <= n <= 109

/*
Approach:
    This is a pretty difficult problem, you need to find some patterns from the description. First, if a number has the odd number of digits, it can never
be balanced, so we should consider a balanced number that has one more digits than it. For example, n=403, n can't be balanced no matter how we adjust it.
The first four-digit number greater than it is 1000, but it's not balanced, so let's make it plus one: and 1001 is balanced. So For every number with odd numbers of 
digits, we can use this similar way to find the first balanced number larger than it. We have solved the half of the question until now.
    Now, let us consider the second case: a number consisting of an even number of digits. Theoretically, we can use a brute force algorithm to judge 
all numbers from n to n*10 and find the first number that meets the conditions, but let's consider an extreme example: n=99998999. This number has the
following characteristics: 1. It is already very large; 2. n*10 cannot find the next balanced number, because there are already seven odd digits in n,
and n*10 can only have two even digits at most. In this case, the brute force algorithm can no longer meet the needs. At this time, we can directly 
construct a number that meets the conditions just like we did with odd-digit numbers before.
    The last is the most common situation, find the first number in the range n~n*10 that satisfies the condition.
*/


#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int closestFair(int n) 
    {
        string str = to_string(n);
        // Construct the number.
        string temp = string(1, '1') + string((1+str.length())/2, '0') + string((1+str.length())/2-1, '1');
        if (str.length() % 2 == 1)
        {
            return stoi(temp);
        }
        if (str.front() == '9' && str.find(string(str.length() / 2+1, '9')) != string::npos)
        {
            
            string temp = string(1, '1') + string((str.length()+2)/2, '0') + string((str.length()+2)/2-1, '1');
            return stoi(temp);
        }
        if (str.front() == '9' && str.find(string(str.length() / 2, '9')) != string::npos)
        {
            
            int total = count(str.cbegin(), str.cend(), '9');
            if (total > str.length() / 2)
            {
                string temp = string(1, '1') + string((str.length()+2)/2, '0') + string((str.length()+2)/2-1, '1');
                return stoi(temp);
            }
        }
        int result = 0;
        // It should be noted here that when i is close to INT_MAX, data may overflow, so the type of i must be set to long.
        for (long i=n*1l; i<=static_cast<long>(n*10l); ++i)
        {
            string s = to_string(i);
            int odds = count_if(s.cbegin(), s.cend(), [&](const char& ch) -> bool {
                return ch == '1' || ch == '3' || ch == '5' || ch == '7' || ch == '9';
            });
            int evens = count_if(s.cbegin(), s.cend(), [&](const char& ch) -> bool {
                return ch == '0' || ch == '2' || ch == '4' || ch == '6' || ch == '8';
            });
            if (odds == evens)
            {
                result = i;
                break;
            }
        }
        return result;
    }
};
