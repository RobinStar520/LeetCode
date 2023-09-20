// You have n processes forming a rooted tree structure. You are given two integer arrays pid and ppid, where pid[i] is the ID of the ith process and ppid[i] is the ID of the ith process's parent process.

// Each process has only one parent process but may have multiple children processes. Only one process has ppid[i] = 0, which means this process has no parent process (the root of the tree).

// When a process is killed, all of its children processes will also be killed.

// Given an integer kill representing the ID of a process you want to kill, return a list of the IDs of the processes that will be killed. You may return the answer in any order.

 

// Example 1:


// Input: pid = [1,3,10,5], ppid = [3,0,5,3], kill = 5
// Output: [5,10]
// Explanation: The processes colored in red are the processes that should be killed.
// Example 2:

// Input: pid = [1], ppid = [0], kill = 1
// Output: [1]
 

// Constraints:

// n == pid.length
// n == ppid.length
// 1 <= n <= 5 * 104
// 1 <= pid[i] <= 5 * 104
// 0 <= ppid[i] <= 5 * 104
// Only one process has no parent.
// All the values of pid are unique.
// kill is guaranteed to be in pid.

/*
Approach:
    For this question, we can build a tree. Note that when the question description can't provide enough information to help us choose the type of 
trees, we can choose to build a common tree. In addition, we can use a hashmap to store the reflection from the pid to the tree node to reduce the 
time complexity. Actually, if we ignore this step, our code won't pass all the test cases due to the time limit.
*/

#include <vector>
#include <unordered_map>

using namespace std;

struct Node
{
public:
    int val;

    vector<Node*> children {};

    explicit Node(int val): val(val) {}
};

class Solution 
{
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) 
    {
        vector<int> result {};
        // pid -> Node*
        unordered_map<int, Node*> _map {};
        const int n = pid.size();
        for (int i=0; i<n; ++i)
        {
            if (_map.find(pid[i]) == _map.end())
            {
                struct Node* node = new struct Node(pid[i]);
                if (_map.find(ppid[i]) == _map.end())
                {
                    struct Node* parent = new struct Node(ppid[i]);
                    parent->children.push_back(node);
                    _map[ppid[i]] = parent;
                }
                else
                {
                    struct Node* parent = _map[ppid[i]];
                    parent->children.push_back(node);
                }
                _map[pid[i]] = node;
            }
            else
            {
                struct Node* node = _map[pid[i]];
                if (_map.find(ppid[i]) == _map.end())
                {
                    struct Node* parent = new struct Node(ppid[i]);
                    parent->children.push_back(node);
                    _map[ppid[i]] = parent;
                }
                else
                {
                    struct Node* parent = _map[ppid[i]];
                    parent->children.push_back(node);
                }
            }
            
        }

        dfs(_map[kill], result);
        return result;

    }

private:
    void dfs(struct Node* node, vector<int>& result)
    {
        if (nullptr == node)
        {
            return;
        }
        result.push_back(node->val);
        for (const auto& p: node->children)
        {
            dfs(p, result);
        }
        return;
    }
};