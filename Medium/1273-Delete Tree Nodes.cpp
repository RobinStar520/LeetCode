// A tree rooted at node 0 is given as follows:

// The number of nodes is nodes;
// The value of the ith node is value[i];
// The parent of the ith node is parent[i].
// Remove every subtree whose sum of values of nodes is zero.

// Return the number of the remaining nodes in the tree.

 

// Example 1:


// Input: nodes = 7, parent = [-1,0,0,1,2,2,2], value = [1,-2,4,0,-2,-1,-1]
// Output: 2
// Example 2:

// Input: nodes = 7, parent = [-1,0,0,1,2,2,2], value = [1,-2,4,0,-2,-1,-2]
// Output: 6
 

// Constraints:

// 1 <= nodes <= 104
// parent.length == nodes
// 0 <= parent[i] <= nodes - 1
// parent[0] == -1 which indicates that 0 is the root.
// value.length == nodes
// -105 <= value[i] <= 105
// The given input is guaranteed to represent a valid tree.

/*
Approach:
    For this question, it will be solved as long as we convert the abstract vector to a common tree.
*/

#include <vector>
#include <unordered_map>

using namespace std;

// Define the tree node.
// Note: We can't use "TreeNode" as the tree's node since Leetcode has defined this variable.
struct Node
{
public:
    int val;

    vector<Node*> children {};

    explicit Node(int val) : val(val) {};
};

class Solution 
{
public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) 
    {
        unordered_map<int, Node*> _map {};
        Node* root = nullptr;
        for (int i=0; i<nodes; ++i)
        {
            _map[i] = new Node(value[i]);
        }
        for (int i=0; i<nodes; ++i)
        {
            if (parent[i] == -1)
            {
                root = _map[i];
                continue;
            }
            
            _map[parent[i]]->children.push_back(_map[i]);
        }
        
        auto [_, result] = dfs(root);
        return result;
    }

private:
    pair<int, int> dfs(Node*& node) 
    {
        if(!node)
        {
            return {0,0};
        }

        int val = node->val;
        int count = 1;
        for(auto& child: node->children) 
        {
            auto [v, c] = dfs(child);
            val += v;
            count += c;
        }

        if(val == 0) 
        {
            node = nullptr;
            count = 0;
        }

        return {val, count};
    }
};