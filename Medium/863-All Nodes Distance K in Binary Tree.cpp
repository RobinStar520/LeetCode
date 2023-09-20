// Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

// You can return the answer in any order.

 

// Example 1:


// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
// Output: [7,4,1]
// Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
// Example 2:

// Input: root = [1], target = 1, k = 3
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [1, 500].
// 0 <= Node.val <= 500
// All the values Node.val are unique.
// target is the value of one of the nodes in the tree.
// 0 <= k <= 1000

/*
Approach:
    We cannot go back in a tree, but we can go anywhere in a graph. If we construct a graph from the tree, that would be much easier to handle. So, first,
try to construct a tree; Second, use a BFS algorithm to find all the path from the start point.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        unordered_map<int, vector<int>> _map {};
        vector<int> result {};
        dfs(root, _map);
        if (_map.empty())
        {
            return result;
        }

        queue<pair<int, int>> bfsQueue {};  
        unordered_set<int> visited {};
        bfsQueue.push({target->val, 0});
        visited.insert(target->val);

        while (!bfsQueue.empty())
        {
            int nodeVal = bfsQueue.front().first;
            int distance = bfsQueue.front().second;
            bfsQueue.pop();

            if (distance == k)
            {
                result.push_back(nodeVal);
            }
            else if (distance < k)
            {
                for (int neighbor : _map[nodeVal])
                {
                    if (visited.find(neighbor) == visited.end())
                    {
                        bfsQueue.push({neighbor, distance + 1});
                        visited.insert(neighbor);
                    }
                }
            }
        }
        
        return result;
    }

private:
    // This function is to cnstruct a tree.
    void dfs(struct TreeNode* node, unordered_map<int, vector<int>>& _map)
    {
        if (nullptr == node)
        {
            return;
        }
        if (node->left != nullptr)
        {
            _map[node->val].push_back(node->left->val);
            _map[node->left->val].push_back(node->val);
        }
        if (node->right != nullptr)
        {
            _map[node->val].push_back(node->right->val);
            _map[node->right->val].push_back(node->val);
        }
        dfs(node->left, _map);
        dfs(node->right, _map);
        return;
    }

    
};