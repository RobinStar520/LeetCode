// We run a preorder depth-first search (DFS) on the root of a binary tree.

// At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.

// If a node has only one child, that child is guaranteed to be the left child.

// Given the output traversal of this traversal, recover the tree and return its root.

 

// Example 1:


// Input: traversal = "1-2--3--4-5--6--7"
// Output: [1,2,5,3,4,6,7]
// Example 2:


// Input: traversal = "1-2--3---4-5--6---7"
// Output: [1,2,5,3,null,6,null,4,null,7]
// Example 3:


// Input: traversal = "1-401--349---90--88"
// Output: [1,401,null,349,88,90]
 

// Constraints:

// The number of nodes in the original tree is in the range [1, 1000].
// 1 <= Node.val <= 109

/*
Approach:
    We can use a hashmap to record the depth of a node. For example: "1-2--3--4-5--6--7", the root value is 1, and its depth is 0; There is only one '-
before the node, that value is 2, so the depth of the node is 1, and it should be one of the node's children whose height is 0, and so on.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <string>
#include <unordered_map>
#include <cctype>

using namespace std;

class Solution 
{
public:
    TreeNode* recoverFromPreorder(string traversal) 
    {
        unordered_map<int, struct TreeNode*> _map {};
        int index = traversal.find_first_of('-');
        struct TreeNode* root = new struct TreeNode(stoi(traversal.substr(0, index)));
        // Note the edge cases, like "2" without '-'.
        if (index == string::npos)
        {
            return root;
        }
        _map[0] = root;
        const int n = traversal.length();
        int level = 0;
        for (int i=index; i<n; ++i)
        {
            int j = i;
            if (isdigit(traversal[i]))
            {
                
                while (std::isdigit(traversal[j]))
                {
                    j ++;
                }
                struct TreeNode* node = new struct TreeNode(stoi(traversal.substr(i, j - i)));
                if (_map[level - 1]->left == nullptr)
                {
                    _map[level - 1]->left = node;
                }
                else if (_map[level - 1]->right == nullptr)
                {
                    _map[level - 1]->right = node;
                }
                _map[level] = node;
            }
            else 
            {
                while (traversal[j] == '-')
                {
                    j ++;
                }
                level = j - i;
                
            }
            i = j-1;
        }
        return root;
    }
};