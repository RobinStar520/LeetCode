// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

 

// Example 1:


// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]
// Example 2:

// Input: head = [2,1], x = 2
// Output: [1,2]


/*
Approach:
    Use an extra linear data structure to store each node, like vector or deque. Here I choose to use a deque since it can push/pop values bilaterally.
And then simulate the process of the question.
    Note: If you choose real nodes in a linear data structure, don't forget to link them; If you just store the value of each node, you don't worry about it.
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

#include <deque>
#include <algorithm>

using namespace std;
class Solution 
{
public:
    ListNode* partition(ListNode* head, int x) 
    {
        if (nullptr == head)
        {
            return nullptr;
        }
        deque<int> dq {};
        int index = 0;
        struct ListNode* pcur = head;
        while (pcur != nullptr)
        {
            if (pcur->val >= x)
            {
                dq.push_back(pcur->val);
            }
            else
            {
                index ++;
                dq.push_front(pcur->val);
            }
            pcur = pcur->next;
        }

        reverse(dq.begin(), dq.begin()+index);

        pcur = head;
        int n = dq.size();
        for (int i=0; i<n; ++i)
        {
            pcur->val = dq[i];
            pcur = pcur->next;
        }
        return head;
    }
};
