// You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

// Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

 

// Example 1:

// Input: equations = ["a==b","b!=a"]
// Output: false
// Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
// There is no way to assign the variables to satisfy both equations.
// Example 2:

// Input: equations = ["b==a","a==b"]
// Output: true
// Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
 

// Constraints:

// 1 <= equations.length <= 500
// equations[i].length == 4
// equations[i][0] is a lowercase letter.
// equations[i][1] is either '=' or '!'.
// equations[i][2] is '='.
// equations[i][3] is a lowercase letter.
// Accepted
// 117.7K
// Submissions
// 233.2K
// Acceptance Rate
// 50.5%

/*
Approach:
    We can use a union-find data structure to solve the problem effectively. Traverse the whole vector. If we find an equation, we append the two variables
to the union-find structure. Then, traverse the vector again, and check variables in an inequality whether have the same root.
*/

#include <vector>
#include <string>

using namespace std;

class UnionFind
{
public:
    explicit UnionFind(int n)
    {
        root = vector<int>(n);
        init();
    }

    void init()
    {
        for (int i=0; i<root.size(); ++i)
        {
            root[i] = i;
        }
    }

    int find(int a)
    {
        return a == root[a] ? a : root[a] = find(root[a]);
    }

    bool isSame(int a, int b)
    {
        a = find(a);
        b = find(b);
        return a == b;
    }

    void join(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
        {
            return;
        }
        root[b] = a;
    }

private:
    vector<int> root {};
};

class Solution 
{
public:
    bool equationsPossible(vector<string>& equations) 
    {
        UnionFind* obj = new UnionFind(26);
        for (const auto& equation: equations)
        {
            if (equation[1] == '=')
            {
                obj->join(equation.front() - 'a', equation.back() - 'a');
            }
        }
        bool result = true;
        for (const auto& equation: equations)
        {
            if (equation[1] != '!')
            {
                continue;
            }
            if (obj->isSame(equation.front() - 'a', equation.back() - 'a'))
            {
                result = false;
                break;
            }
        }
        delete obj;
        return result;
    }
};