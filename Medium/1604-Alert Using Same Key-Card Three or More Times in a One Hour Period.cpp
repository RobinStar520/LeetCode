// LeetCode company workers use key-cards to unlock office doors. Each time a worker uses their key-card, the security system saves the worker's name and the time when it was used. The system emits an alert if any worker uses the key-card three or more times in a one-hour period.

// You are given a list of strings keyName and keyTime where [keyName[i], keyTime[i]] corresponds to a person's name and the time when their key-card was used in a single day.

// Access times are given in the 24-hour time format "HH:MM", such as "23:51" and "09:49".

// Return a list of unique worker names who received an alert for frequent keycard use. Sort the names in ascending order alphabetically.

// Notice that "10:00" - "11:00" is considered to be within a one-hour period, while "22:51" - "23:52" is not considered to be within a one-hour period.

 

// Example 1:

// Input: keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"], keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
// Output: ["daniel"]
// Explanation: "daniel" used the keycard 3 times in a one-hour period ("10:00","10:40", "11:00").
// Example 2:

// Input: keyName = ["alice","alice","alice","bob","bob","bob","bob"], keyTime = ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
// Output: ["bob"]
// Explanation: "bob" used the keycard 3 times in a one-hour period ("21:00","21:20", "21:30").
 

// Constraints:

// 1 <= keyName.length, keyTime.length <= 105
// keyName.length == keyTime.length
// keyTime[i] is in the format "HH:MM".
// [keyName[i], keyTime[i]] is unique.
// 1 <= keyName[i].length <= 10
// keyName[i] contains only lowercase English letters.

/*
Approach:
    Use a hash map to store the name and their leaving times, then sort the leaving time list to judge whether a worker doesn't satisfy the conditions.
*/

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) 
    {
        vector<string> result {};
        unordered_map<string, vector<string>> _map {};
        const int n = keyName.size();
        for (int i=0; i<n; ++i)
        {
            _map[keyName[i]].push_back(keyTime[i]);
        }
        for (auto& [key, value]: _map)
        {
            sort(value.begin(), value.end());
            // cout << key << ": ";
            // for (const auto& time: value)
            // {
            //     cout << calculateTime(time) << " ";
            // }
            // cout << endl;
            int n = value.size();
            for (int i=0; i<n-2; ++i)
            {
                string next_time = this->calculateTime(value[i]);
                if (value[i + 2] <= next_time)
                {
                    result.push_back(key);
                    break;
                }
            }
        }
        sort(result.begin(), result.end());
        return result;

    }

private:
    string calculateTime(const string& time)
    {
        int hour = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        
        int new_minutes = (minutes + 60) % 60;
        int new_hour = hour + 1;

        string hh = new_hour >= 10 ? to_string(new_hour) : string(1, '0') + to_string(new_hour);
        string mm = new_minutes >= 10 ? to_string(new_minutes) : string(1, '0') + to_string(new_minutes);
        return hh + ":" + mm;
    }
};