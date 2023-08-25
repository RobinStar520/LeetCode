// Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

// Implement the AllOne class:

// AllOne() Initializes the object of the data structure.
// inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
// dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
// getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
// getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
// Note that each function must run in O(1) average time complexity.

 

// Example 1:

// Input
// ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
// [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
// Output
// [null, null, null, "hello", "hello", null, "hello", "leet"]

// Explanation
// AllOne allOne = new AllOne();
// allOne.inc("hello");
// allOne.inc("hello");
// allOne.getMaxKey(); // return "hello"
// allOne.getMinKey(); // return "hello"
// allOne.inc("leet");
// allOne.getMaxKey(); // return "hello"
// allOne.getMinKey(); // return "leet"
 

// Constraints:

// 1 <= key.length <= 10
// key consists of lowercase English letters.
// It is guaranteed that for each call to dec, key is existing in the data structure.
// At most 5 * 104 calls will be made to inc, dec, getMaxKey, and getMinKey.

/*
Approach:
    For this question, we can use two hash table, one is a hash set, and another one is a hash table. The set stores a key-value liked structure, set the
occurrence of each element as the key, string as the value to get the string with maximum occurrence quickly. For the hash map, I chose to use "unordered_map"
since it's unnecessary to sort the key. This choice can help us reduce the time waste.
*/

#include <string>
#include <set>
#include <unordered_map>

using namespace std;

class AllOne 
{
public:
    AllOne() 
    {
        
    }
    
    void inc(string key) 
    {
        if (_map.find(key) != _map.end())
        {
            auto p = make_pair(_map[key], key);
            _set.erase(p);
            _map[key] ++;
            p.first += 1;
            _set.insert(p);
        }
        else
        {
            _map[key] ++;
            // If the map doesn't find the key, ensure you create a new pair and insert it to the set.
            _set.insert({1, key});
        }
        return;
    }
    
    void dec(string key) 
    {
        auto p = make_pair(_map[key], key);
        _map[key] --;
        _set.erase(p);
        if (_map[key] <= 0)
        {
            _map.erase(key);
            
        }
        else
        {
            p.first --;
            _set.insert(p);
        }
        return;
    }
    
    string getMaxKey() 
    {
        // Be aware of the statement: "If no element exists, return an empty string """.
        if (!_set.empty()) 
        {
            auto iter = std::prev(_set.end());
            return iter->second;
        }
        return {};
    }
    
    string getMinKey() 
    {
        // Ditto
        if (!_set.empty()) 
        {
            auto iter = _set.begin();
            return iter->second;
        }
        return {};
    }

private:

    unordered_map<string, int> _map {};

    set<pair<int, string>> _set {};
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */