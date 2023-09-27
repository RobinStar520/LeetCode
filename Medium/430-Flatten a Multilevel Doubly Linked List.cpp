// You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.

// Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.

// Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.

 

// Example 1:


// Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
// Output: [1,2,3,7,8,11,12,9,10,4,5,6]
// Explanation: The multilevel linked list in the input is shown.
// After flattening the multilevel linked list it becomes:

// Example 2:


// Input: head = [1,2,null,3]
// Output: [1,3,2]
// Explanation: The multilevel linked list in the input is shown.
// After flattening the multilevel linked list it becomes:

// Example 3:

// Input: head = []
// Output: []
// Explanation: There could be empty list in the input.
 

// Constraints:

// The number of Nodes will not exceed 1000.
// 1 <= Node.val <= 105

/*
Approach:
    For this question, we can use a DFS-like approach to collect nodes as many as possible. The key point is dealing with the node with a next
node and a child node. Using a stack is a good choice.  
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
#include <vector>
#include <stack>

using namespace std;

class Solution 
{
public:
    Node* flatten(Node* head) 
    {
        if (nullptr == head)
        {
            return nullptr;
        }
        stack<Node*> _stack {};
        vector<Node*> nodes {};
        Node* pcur = head;
        while (pcur != nullptr)
        {
            nodes.push_back(pcur);
            if (pcur->child != nullptr && pcur->next != nullptr)
            {
                _stack.push(pcur->next);
            }
            pcur->child == nullptr ? pcur = pcur->next : pcur = pcur->child;
        }
        // store the next nodes that its previous node both has a child node and a next node.
        while (!_stack.empty())
        {
            Node* pcur = _stack.top();
            _stack.pop();
            while (pcur != nullptr)
            {
                nodes.push_back(pcur);
                pcur = pcur->next;
            }
        }
        const int n = nodes.size();

        // Don't forget to modify the first node and the last node in the vector.
        nodes.back()->child = nullptr;
        nodes.back()->next = nullptr;
        nodes.front()->prev = nullptr;
        for (int i=0; i<n-1; ++i)
        {
            nodes[i]->child = nullptr;
            nodes[i]->next = nodes[i + 1];
            nodes[i + 1]->prev = nodes[i];
        }
        return nodes.front();
    }
};