// You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

// Each minute, a node becomes infected if:

// The node is currently uninfected.
// The node is adjacent to an infected node.
// Return the number of minutes needed for the entire tree to be infected.

 

// Example 1:


// Input: root = [1,5,3,null,4,10,6,9,2], start = 3
// Output: 4
// Explanation: The following nodes are infected during:
// - Minute 0: Node 3
// - Minute 1: Nodes 1, 10 and 6
// - Minute 2: Node 5
// - Minute 3: Node 4
// - Minute 4: Nodes 9 and 2
// It takes 4 minutes for the whole tree to be infected so we return 4.
// Example 2:


// Input: root = [1], start = 1
// Output: 0
// Explanation: At minute 0, the only node in the tree is infected so we return 0.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 105].
// 1 <= Node.val <= 105
// Each node has a unique value.
// A node with a value of start exists in the tree.

/*
Approach:
    Convert the binary tree to a graph, and then use DFS.
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
    int amountOfTime(TreeNode* root, int start) 
    {
        unordered_map<struct TreeNode*, vector<struct TreeNode*>> graph {};
        unordered_map<int, struct TreeNode*> nodeMap {};
        unordered_set<struct TreeNode*> visited {};
        dfs(root, graph, nodeMap);
        // Note the initialization value of the variable "result".
        int result = -1;
        bfs(nodeMap[start], graph, visited, result);
        return result;
    }

private:
    void dfs(struct TreeNode* node, unordered_map<struct TreeNode*, vector<struct TreeNode*>>& _map,
        unordered_map<int, struct TreeNode*>& nodeMap
    )
    {
        if (nullptr == node)
        {
            return;
        }
        nodeMap[node->val] = node;
        if (node->left != nullptr)
        {
            _map[node].push_back(node->left);
            _map[node->left].push_back(node);
        }
        if (node->right != nullptr)
        {
            _map[node].push_back(node->right);
            _map[node->right].push_back(node);
        }
        dfs(node->left, _map, nodeMap);
        dfs(node->right, _map, nodeMap);
        return;
    }

    void bfs(struct TreeNode* node, unordered_map<struct TreeNode*, vector<struct TreeNode*>>& graph, unordered_set<struct TreeNode*>& visited, int& result)
    {
        if (nullptr == node)
        {
            return;
        }
        queue<struct TreeNode*> q {};
        q.push(node);
        while (!q.empty())
        {
            int n = q.size();
            while (n --)
            {
                struct TreeNode* t = q.front();
                q.pop();
                visited.insert(t);
                for (int i=0; i<graph[t].size(); ++i)
                {
                    if (visited.find(graph[t][i]) != visited.end())
                    {
                        continue;
                    }
                    q.push(graph[t][i]);
                }
            }
            result += 1;
        }
        return;
    }
};