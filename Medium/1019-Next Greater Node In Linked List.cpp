// You are given the head of a linked list with n nodes.

// For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

// Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

 

// Example 1:


// Input: head = [2,1,5]
// Output: [5,5,0]
// Example 2:


// Input: head = [2,7,4,3,5]
// Output: [7,0,5,5,0]
 

// Constraints:

// The number of nodes in the list is n.
// 1 <= n <= 104
// 1 <= Node.val <= 109

/*
Approach:
    We can use a stack to store the elements we have traversed.(so called monotonic stack)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>
#include <stack>

using namespace std;

class Solution 
{
public:
    vector<int> nextLargerNodes(ListNode* head) 
    {
        vector<int> vct {};
        struct ListNode* pcur = head;
        while (pcur != nullptr)
        {
            vct.push_back(pcur->val);
            pcur = pcur->next;
        }
        stack<int> _stack {};
        const int n = vct.size();
        vector<int> result(n, 0);
        for (int i=0; i<n; ++i)
        {
            while (!_stack.empty() && vct[i] > vct[_stack.top()])
            {
                int index = _stack.top();
                _stack.pop();
                result[index] = vct[i];
            }
            _stack.push(i);
        }
        return result;
    }
};