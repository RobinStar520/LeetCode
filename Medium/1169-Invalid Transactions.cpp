// A transaction is possibly invalid if:

// the amount exceeds $1000, or;
// if it occurs within (and including) 60 minutes of another transaction with the same name in a different city.
// You are given an array of strings transaction where transactions[i] consists of comma-separated values representing the name, time (in minutes), amount, and city of the transaction.

// Return a list of transactions that are possibly invalid. You may return the answer in any order.

 

// Example 1:

// Input: transactions = ["alice,20,800,mtv","alice,50,100,beijing"]
// Output: ["alice,20,800,mtv","alice,50,100,beijing"]
// Explanation: The first transaction is invalid because the second transaction occurs within a difference of 60 minutes, have the same name and is in a different city. Similarly the second one is invalid too.
// Example 2:

// Input: transactions = ["alice,20,800,mtv","alice,50,1200,mtv"]
// Output: ["alice,50,1200,mtv"]
// Example 3:

// Input: transactions = ["alice,20,800,mtv","bob,50,1200,mtv"]
// Output: ["bob,50,1200,mtv"]
 

// Constraints:

// transactions.length <= 1000
// Each transactions[i] takes the form "{name},{time},{amount},{city}"
// Each {name} and {city} consist of lowercase English letters, and have lengths between 1 and 10.
// Each {time} consist of digits, and represent an integer between 0 and 1000.
// Each {amount} consist of digits, and represent an integer between 0 and 2000.


/*
Approach:
    A very tedious question with some low constraints. First, you need to split the string to get the four attributes: name, time, amount and city. You can
use the string splitting methods or a "stringstream" object to divide the string. Then, judge the two conditions using two for loops.
*/
#include <vector>
#include <string>

using namespace std;

class Solution 
{
public:
    vector<string> invalidTransactions(vector<string>& transactions) 
    {
        vector<string> result {};
        const int n = transactions.size();
        for (int i=0; i<n; ++i)
        {
            bool flag = false;
            int first = transactions[i].find_first_of(',');
            int second = transactions[i].find(',', first + 1);
            int third = transactions[i].find(',', second + 1);
            int forth = transactions[i].find(',', third + 1);
            int time1 = stoi(transactions[i].substr(first + 1, second - first));
            int amount1 = stoi(transactions[i].substr(second + 1, third - second));
            string name1 = transactions[i].substr(0, first);
            string city1 = transactions[i].substr(third + 1, forth - third);
            // cout << first << "," << second << endl;
            // cout << time1 << "," << name1 << "," << amount1 << "," << city1 << endl;
            if (amount1 > 1000)
            {
                result.push_back(transactions[i]);
                continue;
            }
            for (int j=0; j<n; ++j)
            {
                int first = transactions[j].find_first_of(',');
                int second = transactions[j].find(',', first + 1);
                int time2 = stoi(transactions[j].substr(first + 1, second - first));
                string name2 = transactions[j].substr(0, first);
                int third = transactions[j].find(',', second + 1);
                int forth = transactions[i].find(',', third + 1);
                int amount2 = stoi(transactions[j].substr(second + 1, third - second));
                string city2 = transactions[j].substr(third + 1, forth - third);
                if (name1 == name2 && std::abs(time1 - time2) <= 60 && city1 != city2)
                {
                    flag = true;
                    break;
                }
                
            }
            if (flag)
            {
                result.push_back(transactions[i]);
            }
        }
        return result;
    }
};