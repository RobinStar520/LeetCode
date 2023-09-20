// Given a node in a binary search tree, return the in-order successor of that node in the BST. If that node has no in-order successor, return null.

// The successor of a node is the node with the smallest key greater than node.val.

// You will have direct access to the node but not to the root of the tree. Each node will have a reference to its parent node. Below is the definition for Node:

// class Node {
//     public int val;
//     public Node left;
//     public Node right;
//     public Node parent;
// }
 

// Example 1:


// Input: tree = [2,1,3], node = 1
// Output: 2
// Explanation: 1's in-order successor node is 2. Note that both the node and the return value is of Node type.
// Example 2:


// Input: tree = [5,3,6,2,4,null,null,1], node = 6
// Output: null
// Explanation: There is no in-order successor of the current node, so the answer is null.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -105 <= Node.val <= 105
// All Nodes will have unique values.

/*
Approach:
    This is an easy question. The root node of the tree is not allowed to access directly, but each node provides a pointer that points to its parent,
so we can use this pointer to find the root of the tree.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/
#include <vector>
#include <queue>

using namespace std;

struct Comp
{
public:
    bool operator()(Node* node1, Node* node2) const
    {
        return node1->val > node2->val;
    }
};

class Solution 
{
public:
    Node* inorderSuccessor(Node* node) 
    {
        Node* root = node;
        // Find the root of the tree.
        while (root->parent != nullptr)
        {
            root = root->parent;
        }
        priority_queue<Node*, vector<Node*>, Comp> pq {};
        dfs(root, pq);
        while (!pq.empty())
        {
            if (pq.top() == node)
            {
                break;
            }
            pq.pop();
        }
        pq.pop();
        return pq.empty() ? nullptr : pq.top();
    }

private:
    void dfs(Node* root, priority_queue<Node*, vector<Node*>, Comp>& pq)
    {
        if (nullptr == root)
        {
            return;
        }
        dfs(root->left, pq);
        pq.push(root);
        dfs(root->right, pq);
        return;
    }
};