// You have n binary tree nodes numbered from 0 to n - 1 where node i has two children leftChild[i] and rightChild[i], return true if and only if all the given nodes form exactly one valid binary tree.

// If node i has no left child then leftChild[i] will equal -1, similarly for the right child.

// Note that the nodes have no values and that we only use the node numbers in this problem.

 

// Example 1:


// Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,-1,-1,-1]
// Output: true
// Example 2:


// Input: n = 4, leftChild = [1,-1,3,-1], rightChild = [2,3,-1,-1]
// Output: false
// Example 3:


// Input: n = 2, leftChild = [1,0], rightChild = [-1,-1]
// Output: false
 

// Constraints:

// n == leftChild.length == rightChild.length
// 1 <= n <= 104
// -1 <= leftChild[i], rightChild[i] <= n - 1

/*
Approach:
    This quesiton's solution is similar to question 261-graph valid tree but needs some supplementary since the question provides a directed graph.
We need three steps: 1. Calculate the indegree of each node; 2. Calculate the number of edges; 3. Find whether there is only one root in the tree.
*/

#include <vector>

using namespace std;

class UnionFind
{
public:
    explicit UnionFind(int n)
    {
        root = vector<int>(n);
        init();
    }

    void init()
    {
        for (int i=0; i<root.size(); ++i)
        {
            root[i] = i;
        }
    }

    int find(int a)
    {
        return root[a] == a ? a : root[a] = find(root[a]);
    }

    bool isSame(int a, int b)
    {
        a = find(a);
        b = find(b);
        return a == b;
    }

    void join(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
        {
            return;
        }
        root[b] = a;
    }

    int getCount()
    {
        int result = 0;
        for (int i=0; i<root.size(); ++i)
        {
            if (root[i] == i)
            {
                result += 1;
            }
        }
        return result;
    }

private:
    vector<int> root;
};

class Solution 
{
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        UnionFind* obj = new UnionFind(n);
        vector<int> indegree(n);
        int edges = 0;
        for (int i=0; i<n; ++i)
        {
            if (leftChild[i] != -1)
            {
                edges += 1;
                indegree[leftChild[i]] += 1;
                obj->join(i, leftChild[i]);
            }
            if (rightChild[i] != -1)
            {
                edges += 1;
                indegree[rightChild[i]] += 1;
                obj->join(i, rightChild[i]);
            }
            if (leftChild[i] == -1 && rightChild[i] == -1)
            {
                obj->join(i, i);
            }
        }
        // Condition 1
        for (const auto& i: indegree)
        {
            if (i >= 2)
            {
                return false;
            }
        }
        // Condition 2
        if (edges != n - 1)
        {
            return false;
        }
        // Dondition 3
        bool result = obj->getCount() == 1;
        delete obj;
        
        return result;
    }
};