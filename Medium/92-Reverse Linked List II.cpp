// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

// Example 1:


// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]
 

// Constraints:

// The number of nodes in the list is n.
// 1 <= n <= 500
// -500 <= Node.val <= 500
// 1 <= left <= right <= n
 

// Follow up: Could you do it in one pass?

/*
Approach:
    This is a series of problems using the two-pointer technique. To simplify the whole process, I used an auxiliary vector to help reverse the part 
of the linked list. 
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
#include <algorithm>

using namespace std;

class Solution 
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if (nullptr == head)
            return nullptr;
        vector<int> vct {};
        struct ListNode* cur = head;
        while (cur != nullptr)
        {
            vct.push_back(cur->val);
            cur = cur->next;
        }
        reverse(vct.begin()+left-1, vct.begin()+right);

        struct ListNode* _head = new struct ListNode(vct[0], nullptr);
        struct ListNode* pcur = _head;
        for (int i=1; i<vct.size(); ++i)
        {
            struct ListNode* newNode = new struct ListNode(vct[i], nullptr);
            pcur->next = newNode;
            pcur = newNode;
        }
        return _head;
    }
};