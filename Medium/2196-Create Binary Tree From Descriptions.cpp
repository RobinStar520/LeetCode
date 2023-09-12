// You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

// If isLefti == 1, then childi is the left child of parenti.
// If isLefti == 0, then childi is the right child of parenti.
// Construct the binary tree described by descriptions and return its root.

// The test cases will be generated such that the binary tree is valid.

 

// Example 1:


// Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// Output: [50,20,80,15,17,19]
// Explanation: The root node is the node with value 50 since it has no parent.
// The resulting binary tree is shown in the diagram.
// Example 2:


// Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
// Output: [1,2,null,null,3,4]
// Explanation: The root node is the node with value 1 since it has no parent.
// The resulting binary tree is shown in the diagram.
 

// Constraints:

// 1 <= descriptions.length <= 104
// descriptions[i].length == 3
// 1 <= parenti, childi <= 105
// 0 <= isLefti <= 1
// The binary tree described by descriptions is valid.

/*
Approach:
    Use a hashmap to store the nodes by their child ID. Note: Although the description doesn't declare that the value of each node is unique, 
we still think so. Otherwise, a node probably has more than two nodes, which goes against the definition of a binary tree. There is another important 
part: How to determine the tree's root. We can use a hash set to store the children of each node, then traverse the whole description vector to find 
which node doesn't exist in the set. The principle of this step is a node with indegree 0 is the root.
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

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) 
    {
        unordered_map<int, struct TreeNode*> _map {};
        unordered_set<int> _set {};
        // There are four cases for this step: 
        // 1. Parent node and child node don't exist;
        // 2. Parent node doesn't exist, child node exist;
        // 3. Parent node exist, child node doesn't exist;
        // 4. Both parent node and child node exist.
        for (const auto& v: descriptions)
        {
            _set.insert(v[1]);
            if (_map.find(v[0]) == _map.end())
            {
                struct TreeNode* parent = new struct TreeNode(v[0]);
                _map[v[0]] = parent;
                if (_map.find(v[1]) == _map.end())
                {
                    struct TreeNode* child = new struct TreeNode(v[1]);
                    _map[v[1]] = child;
                    v[2] == 1 ? parent->left = child : parent->right = child;
                }
                else
                {
                    struct TreeNode* child = _map[v[1]];
                    v[2] == 1 ? parent->left = child : parent->right = child;
                }
            }
            else
            {
                struct TreeNode* parent = _map[v[0]];
                if (_map.find(v[1]) == _map.end())
                {
                    struct TreeNode* child = new struct TreeNode(v[1]);
                    _map[v[1]] = child;
                    v[2] == 1 ? parent->left = child : parent->right = child;
                }
                else
                {
                    struct TreeNode* child = _map[v[1]];
                    v[2] == 1 ? parent->left = child : parent->right = child;
                }
            }
        }
        // Find the root
        struct TreeNode* root = nullptr;
        for (const auto& v: descriptions)
        {
            if (_set.find(v[0]) == _set.end())
            {
                root = _map[v[0]];
                break;
            }
        }
        return root;
    }
};
