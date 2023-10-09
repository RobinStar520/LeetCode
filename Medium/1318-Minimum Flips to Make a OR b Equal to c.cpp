// Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
// Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

 

// Example 1:



// Input: a = 2, b = 6, c = 5
// Output: 3
// Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)
// Example 2:

// Input: a = 4, b = 2, c = 7
// Output: 1
// Example 3:

// Input: a = 1, b = 2, c = 3
// Output: 0
 

// Constraints:

// 1 <= a <= 10^9
// 1 <= b <= 10^9
// 1 <= c <= 10^9

/*
Approach:
    This is a very easy question. We just need to check the bits individually based on bitwise or operation.
*/

#include <string>
#include <bitset>

using namespace std;

class Solution 
{
public:
    int minFlips(int a, int b, int c) 
    {
        int result = 0;
        string str_a = convert_to_string(a);
        string str_b = convert_to_string(b);
        string str_c = convert_to_string(c);

        for (int i=0; i<32; ++i)
        {
            if (str_c[i] == '0')
            {
                if ((str_a[i] != '0' && str_b[i] == '0') || (str_a[i] == '0' && str_b[i] != '0'))
                {
                    result += 1;
                }
                else if (str_a[i] == '1' && str_b[i] == '1')
                {
                    result += 2;
                }
            }
            else
            {
                if (str_a[i] == '0' && str_b[i] == '0')
                {
                    result += 1;
                }
            }
        }
        
        return result;
    }

private:
    string convert_to_string(int num)
    {
        bitset<32> bits(num);
        string str = bits.to_string();
        return str;
    }
};