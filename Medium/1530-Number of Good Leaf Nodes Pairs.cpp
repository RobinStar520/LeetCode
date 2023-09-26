// You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

// Return the number of good leaf node pairs in the tree.

 

// Example 1:


// Input: root = [1,2,3,null,4], distance = 3
// Output: 1
// Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
// Example 2:


// Input: root = [1,2,3,4,5,6,7], distance = 3
// Output: 2
// Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
// Example 3:

// Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
// Output: 1
// Explanation: The only good pair is [2,5].
 

// Constraints:

// The number of nodes in the tree is in the range [1, 210].
// 1 <= Node.val <= 100
// 1 <= distance <= 10

/*
Approach:
    This is a simple question, but you have to do many things. First, you need to get the common ancestor of two nodes; Second, find all the leaf nodes;
Third, calculate the distance from one leaf node to another. Last, get the final result.
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

/*
Approach:
    We can use a standard solution for this question: divide the question into three parts: 1. Find all leaf nodes; 2. Find the lowest common ancestor of 
two leaf nodes; 3. Calculate their distance. This solution is unacceptable for this question due to the large constraints. So, we can build a directed
graph to find the shortest path between two leaf nodes.
*/

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

class Solution 
{
public:
    int countPairs(TreeNode* root, int distance) 
    {
        if (nullptr == root)
        {
            return 0;
        }
        unordered_map<struct TreeNode*, vector<struct TreeNode*>> _map {};
        vector<struct TreeNode*> leaves {};
        dfs(root, _map, leaves);
        int result = 0;
        for (int i=0; i<leaves.size(); ++i)
        {
            bfs(leaves[i], _map, distance, result);
        }
        return result / 2;
    }

private:
    // Build a directed graph.
    void dfs(struct TreeNode* root, unordered_map<struct TreeNode*, vector<struct TreeNode*>>& _map,
        vector<struct TreeNode*>& leaves
    )
    {
        if (nullptr == root)
        {
            return;
        }
        dfs(root->left, _map, leaves);
        if (nullptr == root->left && nullptr == root->right)
        {
            leaves.push_back(root);
        }
        if (nullptr != root->left)
        {
            _map[root].push_back(root->left);
            _map[root->left].push_back(root);
        }
        if (nullptr != root->right)
        {
            _map[root].push_back(root->right);
            _map[root->right].push_back(root);
        }
        dfs(root->right, _map, leaves);
        return;
    }

    void bfs(struct TreeNode* root, unordered_map<struct TreeNode*, vector<struct TreeNode*>>& _map, int distance, int& result)
    {
        int dis = 0;
        queue<struct TreeNode*> q {};
        q.push(root);
        unordered_set<struct TreeNode*> visited {};
        while (!q.empty())
        {
            int n = q.size();
            while (n --)
            {
                struct TreeNode* node = q.front();
                q.pop();
                
                if (visited.find(node) != visited.end())
                {
                    continue;
                }
                if (root != node && node->left == nullptr && node->right == nullptr)
                {
                    result += 1;
                }
                visited.insert(node);
                for (int i=0; i<_map[node].size(); ++i)
                {
                    q.push(_map[node][i]);
                }
            }
            dis += 1;
            if (dis > distance)
            {
                return;
            }
        }
        return;
    }   
};