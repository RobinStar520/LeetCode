// Given head, the head of a linked list, determine if the linked list has a cycle in it.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

// Return true if there is a cycle in the linked list. Otherwise, return false.

 

// Example 1:


// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
// Example 2:


// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
// Example 3:


// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.
 

// Constraints:

// The number of the nodes in the list is in the range [0, 104].
// -105 <= Node.val <= 105
// pos is -1 or a valid index in the linked-list.
 

// Follow up: Can you solve it using O(1) (i.e. constant) memory?

/*
Approach:
    A traditional method for this kind of question is to use a two-pointer technique, use two pointers, one is called a slow pointer, and another 
one is called a fast pointer. Every time, move the two pointers simultaneously, if the two pointers meet with each other, we can draw a conclusion 
that the linked list has a ring. Actually, there is a simple enough approach to using a set: Use an extra set to store the node of the linked list.
(Notice: Store the node, not the value of the node), and then judge the addresses individually whether is exist in the set.
*/

#include <unordered_set>

using namespace std;

class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        // If the linked list doesn't have nodes or only has one node, we consider it doesn't have a ring.
        if (nullptr == head || nullptr == head->next)
        {
            return false;
        }
        
        unordered_set<struct ListNode*> _set {};
        struct ListNode* pCur = head;
        while (pCur != nullptr)
        {
            auto iter = _set.find(pCur);
            if (iter != _set.cend())
            {
                return true;
            }
            // If we don't find the node in the set, insert it.
            _set.insert(pCur);
            pCur = pCur->next;
        }
        return false;
    }
};