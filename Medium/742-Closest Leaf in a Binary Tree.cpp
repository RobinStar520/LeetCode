// Given the root of a binary tree where every node has a unique value and a target integer k, return the value of the nearest leaf node to the target k in the tree.

// Nearest to a leaf means the least number of edges traveled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.

 

// Example 1:


// Input: root = [1,3,2], k = 1
// Output: 2
// Explanation: Either 2 or 3 is the nearest leaf node to the target of 1.
// Example 2:


// Input: root = [1], k = 1
// Output: 1
// Explanation: The nearest leaf node is the root node itself.
// Example 3:


// Input: root = [1,2,3,4,null,null,null,5,null,6], k = 2
// Output: 3
// Explanation: The leaf node with value 3 (and not the leaf node with value 6) is nearest to the node with value 2.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// 1 <= Node.val <= 1000
// All the values of the tree are unique.
// There exist some node in the tree where Node.val == k.

/*
Approach:
    Let's divide the solution into three steps: First, find all the leaf nodes and use a hashmap to recode the reflection of the node value and its
memory address; Second, write a function to find the lowest common ancestor of two nodes; Third, use a loop to calculate the distance from every leaf
node to the target node. Note that the target node we can get from the hashmap.
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
#include <vector>
#include <limits>

using namespace std;

class Solution 
{
public:
    int findClosestLeaf(TreeNode* root, int k) 
    {
        unordered_map<int, struct TreeNode*> _map {};
        int result = 0;
        int distance = 999999;
        vector<struct TreeNode*> vct {};
        dfs(root, _map, vct);
        for (auto node: vct)
        {
            struct TreeNode* ancestor = lowestCommonAncestor(root, _map[k], node);
            int dis = findDistance(ancestor, _map[k], node);
            if (dis < distance)
            {
                distance = dis;
                result = node->val;
            }
        }
        return result;
    }

private:
    void dfs(struct TreeNode* root, unordered_map<int, struct TreeNode*>& _map, vector<struct TreeNode*>& vct)
    {
        if (nullptr ==  root)
        {
            return;
        }
        _map[root->val] = root;
        if (nullptr == root->left && nullptr == root->right)
        {
            vct.push_back(root);
        }
        dfs(root->left, _map, vct);
        dfs(root->right, _map, vct);
        return;
    }

    struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* node1, struct TreeNode* node2)
    {
        if (nullptr == root || root == node1 || root == node2)
        {
            return root;
        }
        struct TreeNode* left = lowestCommonAncestor(root->left, node1, node2);
        struct TreeNode* right = lowestCommonAncestor(root->right, node1, node2);
        if (nullptr != left && nullptr != right)
        {
            return root;
        }
        return left == nullptr ? right : left;
    }

    int getDistance(struct TreeNode* root, struct TreeNode* node)
    {
        if (nullptr == root)
        {
            return -1;
        }
        if (root == node)
        {
            return 0;
        }
        int left = getDistance(root->left, node);
        int right = getDistance(root->right, node);
        int result = -1;
        if (left >= 0)
        {
            result = left + 1;
        }
        else if (right >= 0)
        {
            result = right + 1;
        }
        return result;
    }

    int findDistance(struct TreeNode* ancestor, struct TreeNode* node1, struct TreeNode* node2)
    {
        int distance1 = getDistance(ancestor, node1);
        int distance2 = getDistance(ancestor, node2);
        if (distance1 == -1 || distance2 == -1)
        {
            return -1;
        }
        return distance1 + distance2;
    }
};