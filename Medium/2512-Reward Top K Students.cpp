// You are given two string arrays positive_feedback and negative_feedback, containing the words denoting positive and negative feedback, respectively. Note that no word is both positive and negative.

// Initially every student has 0 points. Each positive word in a feedback report increases the points of a student by 3, whereas each negative word decreases the points by 1.

// You are given n feedback reports, represented by a 0-indexed string array report and a 0-indexed integer array student_id, where student_id[i] represents the ID of the student who has received the feedback report report[i]. The ID of each student is unique.

// Given an integer k, return the top k students after ranking them in non-increasing order by their points. In case more than one student has the same points, the one with the lower ID ranks higher.

 

// Example 1:

// Input: positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is studious","the student is smart"], student_id = [1,2], k = 2
// Output: [1,2]
// Explanation: 
// Both the students have 1 positive feedback and 3 points but since student 1 has a lower ID he ranks higher.
// Example 2:

// Input: positive_feedback = ["smart","brilliant","studious"], negative_feedback = ["not"], report = ["this student is not studious","the student is smart"], student_id = [1,2], k = 2
// Output: [2,1]
// Explanation: 
// - The student with ID 1 has 1 positive feedback and 1 negative feedback, so he has 3-1=2 points. 
// - The student with ID 2 has 1 positive feedback, so he has 3 points. 
// Since student 2 has more points, [2,1] is returned.
 

// Constraints:

// 1 <= positive_feedback.length, negative_feedback.length <= 104
// 1 <= positive_feedback[i].length, negative_feedback[j].length <= 100
// Both positive_feedback[i] and negative_feedback[j] consists of lowercase English letters.
// No word is present in both positive_feedback and negative_feedback.
// n == report.length == student_id.length
// 1 <= n <= 104
// report[i] consists of lowercase English letters and spaces ' '.
// There is a single space between consecutive words of report[i].
// 1 <= report[i].length <= 100
// 1 <= student_id[i] <= 109
// All the values of student_id[i] are unique.
// 1 <= k <= n

/*
Approach:
    There is a loophole in the description of the question. Some feedback may not appear in the positive feedback and the negative feedback. After explaining
the vulnerability, let's move on how to solve the question. First, we need to calculate the score of each student; Second, Sort the container and get the final 
result.
*/

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) 
    {
        // Here, we use two additional unordered sets to store the corresponding feedback to reduce the search time complexity.
        // If you use the function "find" or "find_if" defined in "algorithm" header, it will be time limit exceeded.
        unordered_set<string> positive(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> negative(negative_feedback.begin(), negative_feedback.end());
        vector<int> result {};
        const int n = student_id.size();
        unordered_map<int, int> _map {};
        for (const auto& i: student_id)
        {
            _map[i] = 0;
        }
        for (int i=0; i<n; ++i)
        {
            string feedback {};
            stringstream ss(report[i]);
            while (ss >> feedback)
            {
                // cout << feedback << " ";
                if (positive.find(feedback) != positive.end())
                {
                    _map[student_id[i]] += 3;
                }
                if (negative.find(feedback) != negative.end())
                {
                    _map[student_id[i]] -= 1;
                }
            }
        }
        
        sort(student_id.begin(), student_id.end());
        // Beware of the special case: the map is empty.
        if (_map.empty())
        {
            return vector<int>(student_id.begin(), student_id.begin()+k);
        }
        vector<pair<int, int>> temp(_map.begin(), _map.end());
        sort(temp.begin(), temp.end(), [&](pair<int, int>& p1, pair<int, int>& p2) -> bool {
            bool res {};
            if (p1.second == p2.second)
            {
                res = p1.first < p2.first;
            }
            else
            {
                res = p1.second > p2.second;
            }
            return res;
        });
        
        for (int i=0; i<k; ++i)
        {
            result.push_back(temp[i].first);
        }
        return result;
    }
};