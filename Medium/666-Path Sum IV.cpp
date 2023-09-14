// If the depth of a tree is smaller than 5, then this tree can be represented by an array of three-digit integers. For each integer in this array:

// The hundreds digit represents the depth d of this node where 1 <= d <= 4.
// The tens digit represents the position p of this node in the level it belongs to where 1 <= p <= 8. The position is the same as that in a full binary tree.
// The units digit represents the value v of this node where 0 <= v <= 9.
// Given an array of ascending three-digit integers nums representing a binary tree with a depth smaller than 5, return the sum of all paths from the root towards the leaves.

// It is guaranteed that the given array represents a valid connected binary tree.

 

// Example 1:


// Input: nums = [113,215,221]
// Output: 12
// Explanation: The tree that the list represents is shown.
// The path sum is (3 + 5) + (3 + 1) = 12.
// Example 2:


// Input: nums = [113,221]
// Output: 4
// Explanation: The tree that the list represents is shown. 
// The path sum is (3 + 1) = 4.
 

// Constraints:

// 1 <= nums.length <= 15
// 110 <= nums[i] <= 489
// nums represents a valid binary tree with depth less than 5.

/*
Approach:
    I provide a easy solution: Construct a binary tree step by step following the rules, and try to get the sum of each path that from the root to every
leaf nodes.
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

struct TNode
{
public:
    int val;

    struct TNode* left;

    struct TNode* right;

    explicit TNode(int val) : val(val), left(nullptr), right(nullptr) {}    
};

class Solution 
{
public:
    int pathSum(vector<int>& nums) 
    {
        unordered_map<string, struct TNode*> _map {};
        struct TNode* root = new struct TNode(to_string(nums[0]).back() - '0');
        const int n = nums.size();
        string rootStr = to_string(nums[0]).substr(0, 2);
        _map[rootStr] = root;
        // cout << rootStr << endl;
        for (int i=1; i<n; ++i)
        {
            string str = to_string(nums[i]);
            int level = str[0] - '0';
            int index = str[1] - '0';
            int value = str[2] - '0';
            struct TNode* node = new struct TNode(value);
            _map[str.substr(0, 2)] = node;
            if (index % 2 == 0)
            {
                int parent_index = index / 2;
                string temp = to_string(level - 1) + to_string(parent_index);
                _map[temp]->right = node;
                // cout << temp << endl;
            }
            else
            {
                int parent_index = (1 + index) / 2;
                string temp = to_string(level - 1) + to_string(parent_index);
                _map[temp]->left = node;
                // cout << temp << endl;
            }
        }

        int pathSum = 0, result = 0;
        dfs(root, pathSum, result);
        return result;
    }

private:
    // This function is to test whether build the binary tree sucessfully.
    void bfs(struct TNode* root)
    {
        if (nullptr == root)
        {
            return;
        }
        queue<struct TNode*> q {};
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            while (n --)
            {
                struct TNode* node = q.front();
                q.pop();
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }

        }
    }

    void dfs(struct TNode* root, int& pathSum, int& result)
    {
        if (nullptr == root)
        {
            return;
        }
        pathSum += root->val;
        if (nullptr == root->left && nullptr == root->right)
        {
            result += pathSum;
        }
        else
        {
            dfs(root->left, pathSum, result);
            dfs(root->right, pathSum, result);
        }
        pathSum -= root->val;
        return;
    }


};