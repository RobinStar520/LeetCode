// Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

// The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

// The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

// Return an array of the k parts.

 

// Example 1:


// Input: head = [1,2,3], k = 5
// Output: [[1],[2],[3],[],[]]
// Explanation:
// The first element output[0] has output[0].val = 1, output[0].next = null.
// The last element output[4] is null, but its string representation as a ListNode is [].
// Example 2:


// Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
// Output: [[1,2,3,4],[5,6,7],[8,9,10]]
// Explanation:
// The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
 

// Constraints:

// The number of nodes in the list is in the range [0, 1000].
// 0 <= Node.val <= 1000
// 1 <= k <= 50

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

/*
Approach:
    For this question, the most standard approach is to use a two-pointer technique, but it's hard to come up with especially when you are in an 
interview. So, I used an extra auxiliary vector to help me finish the question: Simulate the process based on the description of the question, and 
that's enough.
*/
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        vector<int> nodes {};
        vector<struct ListNode*> result {};
        struct ListNode* pcur = head;
        while (pcur != nullptr)
        {
            nodes.push_back(pcur->val);
            pcur = pcur->next;
        }
        if (k >= nodes.size())
        {
            for (int i=0; i<nodes.size(); ++i)
            {
                vector<int> item = vector<int>(nodes.begin()+i, nodes.begin()+i+1);
                createList(item, result);
            }
            for (int i=nodes.size(); i<k; ++i)
            {
                result.push_back(nullptr);
            }
            return result;
        }
        int gap = (nodes.size() - nodes.size() % k) / k;
        int left = (1 + gap) * (nodes.size() % k);
        vector<vector<int>> lists {};
        for (int i=0; i<left; i += (1 + gap))
        {
            vector<int> item = vector<int>(nodes.begin()+i,nodes.begin()+i+gap+1);
            lists.push_back(item);
        }
        for (int i=left; i<nodes.size(); i+=gap)
        {
            vector<int> item = vector<int>(nodes.begin()+i, nodes.begin()+i+gap);
            lists.push_back(item);
        }

        for (const auto& v: lists)
        {
            createList(v, result);
        }
        return result;
    }

private:
    void createList(const vector<int>& nums, vector<struct ListNode*>& result)
    {
        int n = nums.size();
        struct ListNode* head = new struct ListNode(nums[0], nullptr);
        struct ListNode* pcur = head;
        for (int i=1; i<n; ++i)
        {
            struct ListNode* newNode = new struct ListNode(nums[i], nullptr);
            pcur->next = newNode;
            pcur = newNode;
        }
        result.push_back(head);
        return;
    }
};




