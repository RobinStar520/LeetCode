// Given a url startUrl and an interface HtmlParser, implement a web crawler to crawl all links that are under the same hostname as startUrl. 

// Return all urls obtained by your web crawler in any order.

// Your crawler should:

// Start from the page: startUrl
// Call HtmlParser.getUrls(url) to get all urls from a webpage of given url.
// Do not crawl the same link twice.
// Explore only the links that are under the same hostname as startUrl.


// As shown in the example url above, the hostname is example.org. For simplicity sake, you may assume all urls use http protocol without any port specified. For example, the urls http://leetcode.com/problems and http://leetcode.com/contest are under the same hostname, while urls http://example.org/test and http://example.com/abc are not under the same hostname.

// The HtmlParser interface is defined as such: 

// interface HtmlParser {
//   // Return a list of all urls from a webpage of given url.
//   public List<String> getUrls(String url);
// }
// Below are two examples explaining the functionality of the problem, for custom testing purposes you'll have three variables urls, edges and startUrl. Notice that you will only have access to startUrl in your code, while urls and edges are not directly accessible to you in code.

// Note: Consider the same URL with the trailing slash "/" as a different URL. For example, "http://news.yahoo.com", and "http://news.yahoo.com/" are different urls.

 

// Example 1:



// Input:
// urls = [
//   "http://news.yahoo.com",
//   "http://news.yahoo.com/news",
//   "http://news.yahoo.com/news/topics/",
//   "http://news.google.com",
//   "http://news.yahoo.com/us"
// ]
// edges = [[2,0],[2,1],[3,2],[3,1],[0,4]]
// startUrl = "http://news.yahoo.com/news/topics/"
// Output: [
//   "http://news.yahoo.com",
//   "http://news.yahoo.com/news",
//   "http://news.yahoo.com/news/topics/",
//   "http://news.yahoo.com/us"
// ]
// Example 2:



// Input: 
// urls = [
//   "http://news.yahoo.com",
//   "http://news.yahoo.com/news",
//   "http://news.yahoo.com/news/topics/",
//   "http://news.google.com"
// ]
// edges = [[0,2],[2,1],[3,2],[3,1],[3,0]]
// startUrl = "http://news.google.com"
// Output: ["http://news.google.com"]
// Explanation: The startUrl links to all other pages that do not share the same hostname.
 

// Constraints:

// 1 <= urls.length <= 1000
// 1 <= urls[i].length <= 300
// startUrl is one of the urls.
// Hostname label must be from 1 to 63 characters long, including the dots, may contain only the ASCII letters from 'a' to 'z', digits  from '0' to '9' and the hyphen-minus character ('-').
// The hostname may not start or end with the hyphen-minus character ('-'). 
// See:  https://en.wikipedia.org/wiki/Hostname#Restrictions_on_valid_hostnames
// You may assume there're no duplicates in url library.

/*
Approach:
    You can choose BFS or DFS. Ensure you get the hostname of an address correctly.
*/

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
#include <string>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;
class Solution 
{
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) 
    {
        string hostname = extractHostname(startUrl);
        stack<string> _stack {};
        vector<string> result {};
        unordered_set<string> _set {};
        _stack.push(startUrl);
        while (!_stack.empty())
        {
            auto v = htmlParser.getUrls(_stack.top());
            result.push_back(_stack.top());
            _set.insert(_stack.top());
            _stack.pop();
            for (const auto& str: v)
            {
                if (hostname == extractHostname(str) && _set.find(str) == _set.end())
                {
                    _stack.push(str);
                    _set.insert(str);
                }
            }
            
        }
        return result;
    }

    string extractHostname(const std::string& url) 
    {
        string hostname {};

        if (url.find("http://") == 0) 
        {
            hostname = url.substr(7); 
        } 
        else if (url.find("https://") == 0) 
        {
            hostname = url.substr(8); 
        } 
        else 
        {
            hostname = url; 
        }

        int slashPos = hostname.find("/");
        if (slashPos != std::string::npos) 
        {
            hostname = hostname.substr(0, slashPos);
        }

        return hostname;
    }
};