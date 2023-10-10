// You are given an integer n and an object categoryHandler of class CategoryHandler.

// There are n elements, numbered from 0 to n - 1. Each element has a category, and your task is to find the number of unique categories.

// The class CategoryHandler contains the following function, which may help you:

// boolean haveSameCategory(integer a, integer b): Returns true if a and b are in the same category and false otherwise. Also, if either a or b is not a valid number (i.e. it's greater than or equal to nor less than 0), it returns false.
// Return the number of unique categories.

 

// Example 1:

// Input: n = 6, categoryHandler = [1,1,2,2,3,3]
// Output: 3
// Explanation: There are 6 elements in this example. The first two elements belong to category 1, the second two belong to category 2, and the last two elements belong to category 3. So there are 3 unique categories.
// Example 2:

// Input: n = 5, categoryHandler = [1,2,3,4,5]
// Output: 5
// Explanation: There are 5 elements in this example. Each element belongs to a unique category. So there are 5 unique categories.
// Example 3:

// Input: n = 3, categoryHandler = [1,1,1]
// Output: 1
// Explanation: There are 3 elements in this example. All of them belong to one category. So there is only 1 unique category.
 

// Constraints:

// 1 <= n <= 100

/*
Approach:
    This is an entry-level question using a union-find data structure. We consider two elements to have the same category if they are in the same set.
*/

/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
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
        return a == root[a] ? a : root[a] = find(root[a]);
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

    int setCount()
    {
        int res = 0;
        for (int i=0; i<root.size(); ++i)
        {
            if (root[i] == i)
            {
                res += 1;
            }
        }
        return res;
    }

private:
    vector<int> root {};

};

class Solution 
{
public:
    int numberOfCategories(int n, CategoryHandler* categoryHandler) 
    {
        UnionFind* obj = new UnionFind(n);
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<n; ++j)
            {
                if (categoryHandler->haveSameCategory(i, j))
                {
                    obj->join(i, j);
                }
            }
        }
        int result = obj->setCount();
        delete obj;
        return result;

    }
};