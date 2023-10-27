// Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

// Example 1:

// Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
// Explanation:
// The first and second John's are the same person as they have the common email "johnsmith@mail.com".
// The third John and Mary are different people as none of their email addresses are used by other accounts.
// We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
// ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
// Example 2:

// Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
// Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
 

// Constraints:

// 1 <= accounts.length <= 1000
// 2 <= accounts[i].length <= 10
// 1 <= accounts[i][j].length <= 30
// accounts[i][0] consists of English letters.
// accounts[i][j] (for j > 0) is a valid email.

/*
Approach:
    This is a graph algorithm, and we can use a union-find data structure to solve it. Note that the namee of the accounts
maybe multiple, so we need to find a way to hash the name to an integer to avoid duplication.
    More: Although this approach can pass all the test cases, it's not an effective method. The total runtime is 881ms.
*/

#include <vector>
#include <string>
#include <unordered_map>    
#include <unordered_set>
#include <algorithm>

using namespace std;

class UnionFind
{
public:
    explicit UnionFind(int n)
    {
        root.resize(n);
        for (int i=0; i<n; ++i)
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

    vector<int>& getroot()
    {
        return this->root;
    }

private:
    vector<int> root {};
};

class Solution 
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        const int n = accounts.size();
        unordered_map<string, vector<int>> _map {};
        unordered_map<int, vector<string>> resMap {};
        vector<vector<string>> result {};
        for (int i=0; i<n; ++i)
        {
            for (int j=1; j<accounts[i].size(); ++j)
            {
                _map[accounts[i][j]].push_back(i);
            }
        }
        UnionFind uf(n);
        for (const auto& [key, value]: _map)
        {
            if (value.size() == 1)
            {
                uf.join(value[0], value[0]);
            }
            else
            {
                for (int i=0; i<value.size()-1; ++i)
                {
                    uf.join(value[i], value[i+1]);
                }
            }
        }

        for (int i=0; i<uf.getroot().size(); ++i)
        {
            int index = uf.find(i);;
            for (int j=0; j<accounts[i].size(); ++j)
            {
                if (find(resMap[index].cbegin(), resMap[index].cend(), accounts[i][j]) == resMap[index].cend())
                {
                    resMap[index].push_back(accounts[i][j]);
                }
            }
        }

        for (auto& [key, value]: resMap)
        {
            sort(value.begin()+1, value.end());
            result.push_back(value);
        }

        return result;
    }
};