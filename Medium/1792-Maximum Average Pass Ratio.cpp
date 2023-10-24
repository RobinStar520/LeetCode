// There is a school that has classes of students and each class will be having a final exam. You are given a 2D integer array classes, where classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.

// You are also given an integer extraStudents. There are another extraStudents brilliant students that are guaranteed to pass the exam of any class they are assigned to. You want to assign each of the extraStudents students to a class in a way that maximizes the average pass ratio across all the classes.

// The pass ratio of a class is equal to the number of students of the class that will pass the exam divided by the total number of students of the class. The average pass ratio is the sum of pass ratios of all the classes divided by the number of the classes.

// Return the maximum possible average pass ratio after assigning the extraStudents students. Answers within 10-5 of the actual answer will be accepted.

 

// Example 1:

// Input: classes = [[1,2],[3,5],[2,2]], extraStudents = 2
// Output: 0.78333
// Explanation: You can assign the two extra students to the first class. The average pass ratio will be equal to (3/4 + 3/5 + 2/2) / 3 = 0.78333.
// Example 2:

// Input: classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4
// Output: 0.53485
 

// Constraints:

// 1 <= classes.length <= 105
// classes[i].length == 2
// 1 <= passi <= totali <= 105
// 1 <= extraStudents <= 105

/*
Approach:
    Pay attention to how much the pass ratio changes when you add a student to the class. If you keep adding students, what happens to the change in 
pass ratio? The more students you add to a class, the smaller the change in pass ratio becomes. Since the change in the pass ratio is always decreasing
with the more students you add, then the very first student you add to each class is the one that makes the biggest change in the pass ratio. Because
each class's pass ratio is weighted equally, it's always optimal to put the student in the class that makes the biggest change among all the other classes.
Keep a max heap of the current class sizes and order them by the change in pass ratio. For each extra student, take the top of the heap, update the class size, 
and put it back in the heap.
*/

#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

struct Comp
{
public:
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const
    {
        double a = (p1.first + 1) * 1.00000 / (p1.second + 1) - (p1.first) * 1.00000 / p1.second;
        double b = (p2.first + 1) * 1.00000 / (p2.second + 1) - (p2.first) * 1.00000 / p2.second;
        return a < b;
    }
};

class Solution 
{
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) 
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comp> pq {};
        const int n = classes.size();
        for (const auto& v: classes)
        {
            pq.push(make_pair(v[0], v[1]));
        }

        double result = 0.00000;
        while (extraStudents --)
        {
            auto [a, b] = pq.top();
            pq.pop();
            pq.push(make_pair(a + 1, b + 1));
        }

        while (!pq.empty())
        {
            auto [a, b] = pq.top();
            pq.pop();
            result += a * 1.0000 / b;
        }
        return result / n;
    }
};

// 0.5(0.666), 0.33(0.53846), 0.8(0.8888), 0.2(0.42857)
// 0.5(0.75), 0.6(0.85714)