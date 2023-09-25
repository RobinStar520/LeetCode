// Given a root of an N-ary tree, you need to compute the length of the diameter of the tree.

// The diameter of an N-ary tree is the length of the longest path between any two nodes in the tree. This path may or may not pass through the root.

// (Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value.)

 

// Example 1:



// Input: root = [1,null,3,2,4,null,5,6]
// Output: 3
// Explanation: Diameter is shown in red color.
// Example 2:



// Input: root = [1,null,2,null,3,4,null,5,null,6]
// Output: 4
// Example 3:



// Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// Output: 7
 

// Constraints:

// The depth of the n-ary tree is less than or equal to 1000.
// The total number of nodes is between [1, 104].

/*
Approach:
    For this problem, we want to find the longest path of the tree. We can use DFS to find the maximum depth of two child nodes.
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int diameter(Node* root) 
    {
        int result = 0;
        dfs(root, result);
        return result;
    }

private:
    int dfs(Node* node, int& result)
    {
        if (node == nullptr) 
        {
            return 0;
        }

        // Calculate the depths of the two deepest children
        int maxDepth1 = 0;
        int maxDepth2 = 0;

        for (Node* child : node->children) 
        {
            int depth = dfs(child, result);

            if (depth > maxDepth1) 
            {
                maxDepth2 = maxDepth1;
                maxDepth1 = depth;
            } 
            else if (depth > maxDepth2) 
            {
                maxDepth2 = depth;
            }
        }

        result = max(result, maxDepth1 + maxDepth2);

        return 1 + maxDepth1;
    }
};