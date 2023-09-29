// You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.

// Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:

// 'L' means to go from a node to its left child node.
// 'R' means to go from a node to its right child node.
// 'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node t.

 

// Example 1:


// Input: root = [5,1,2,3,null,6,4], startValue = 3, destValue = 6
// Output: "UURL"
// Explanation: The shortest path is: 3 → 1 → 5 → 2 → 6.
// Example 2:


// Input: root = [2,1], startValue = 2, destValue = 1
// Output: "L"
// Explanation: The shortest path is: 2 → 1.
 

// Constraints:

// The number of nodes in the tree is n.
// 2 <= n <= 105
// 1 <= Node.val <= n
// All the values in the tree are unique.
// 1 <= startValue, destValue <= n
// startValue != destValue

/*
Approach:
    Three main steps: 1. Use a hashmap to store nodes in the binary tree; 2. Find the lowest common ancestor of two nodes; 3. Find the path from 
their lowest common ancestor to nodes individually.
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
#include <unordered_map>
#include <string>

using namespace std;

class Solution 
{
public:
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        unordered_map<struct TreeNode*, struct TreeNode*> child_to_parent {};
        unordered_map<int, struct TreeNode*> nodes {};
        dfs(root, nodes);
        struct TreeNode* ancestor = lowestCommonAncestors(root, nodes[startValue], nodes[destValue]);
        
        string result {};
        if (ancestor != nodes[startValue] && ancestor != nodes[destValue])
        {
            string left {}, right {}, temp {};
            dfs(ancestor, startValue, temp, left);
            temp.clear();
            int length = left.length();
            left = string(length, 'U');
            result += left;
            dfs(ancestor, destValue, temp, right);
            result += right;
        }
        else if (ancestor == nodes[startValue])
        {
            string down {}, temp {};
            dfs(ancestor, destValue, temp, down);
            result += down;
        }
        else if (ancestor == nodes[destValue])
        {
            string up {}, temp {};
            dfs(ancestor, startValue, temp, up);
            int length = up.length();
            up = string(length, 'U');
            result += up;
        }
        return result;
    }

private:
    void dfs(struct TreeNode* node, unordered_map<int, struct TreeNode*>& _map)
    {
        if (nullptr == node)
        {
            return;
        }
        _map[node->val] = node;
        dfs(node->left, _map);
        dfs(node->right, _map);
        return;
    }

    struct TreeNode* lowestCommonAncestors(struct TreeNode* root, struct TreeNode* t1, struct TreeNode* t2)
    {
        if (nullptr == root || t1 == root || t2 == root)
        {
            return root;
        }
        struct TreeNode* left = lowestCommonAncestors(root->left, t1, t2);
        struct TreeNode* right = lowestCommonAncestors(root->right, t1, t2);
        if (nullptr != left && nullptr != right)
        {
            return root;
        }
        return left == nullptr ? right : left;
    }

    void dfs(struct TreeNode* start, int target, string& path, string& result)
    {
        if (nullptr == start)
        {
            return;
        }
        if (start->val == target)
        {
            result = path;
            return;
        }
        path.push_back('L');
        if (start->left != nullptr)
        {
            dfs(start->left, target, path, result);
        }
        path.pop_back();
        path.push_back('R');
        if (start->right != nullptr)
        {
            dfs(start->right, target, path, result);
        }
        path.pop_back();
    }
};