// Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

// Implement the Twitter class:

// Twitter() Initializes your twitter object.
// void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
// List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
// void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
// void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
 

// Example 1:

// Input
// ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
// [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
// Output
// [null, null, [5], null, null, [6, 5], null, [5]]

// Explanation
// Twitter twitter = new Twitter();
// twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
// twitter.follow(1, 2);    // User 1 follows user 2.
// twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
// twitter.unfollow(1, 2);  // User 1 unfollows user 2.
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
 

// Constraints:

// 1 <= userId, followerId, followeeId <= 500
// 0 <= tweetId <= 104
// All the tweets have unique IDs.
// At most 3 * 104 calls will be made to postTweet, getNewsFeed, follow, and unfollow.

/*
Approach:
    It's easy to implement two functions: "follow" and "unfollw". An user probably follows many people, including him/herself(This is important since the question
never said a user can't follow him/herself). The most important part is how to deal with the function "getNewsFeed". My first idea was to use a heap, and then it's
easy to get the most recent tweets, but this would bring another problem: If one person has followed 5 people, and they posted 20 tweets total. Now, determining
the first 10th tweets sorted by time is difficult. So storing the tweets respectively isn't a good idea, and we should come up with another method to store them. Here
I used a deque containing the tweet ID and the poster first. Every time we call the function "postTweet", insert an item to its front. You can also insert the item to its end,
but you have to traverse the deque backwards. Now we can deal with the function "getNewsFeed": Traverse the whole list from front to back and search whether the owner of the 
tweets belongs to the user following list.
    We can optimise the function "getNewsFeed". Use a linked list instead of a deque. I tested the two edition codes and draw a conclusion: Using a linked list
has a faster speed and beats 100% of people! So here I provide the second edition code.
*/

#include <vector>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <utility>

using namespace std;

class Twitter 
{
public:
    Twitter() 
    {
        
    }
    
    void postTweet(int userId, int tweetId) 
    {
        _list.push_front(make_pair(userId, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        int count = 0;
        auto iter = _list.cbegin();
        vector<int> result {};
        // Check all the tweets
        while (count < 10 && iter != _list.cend())
        {
            // First condition: A user follows him/herself
            if (iter->first == userId)
            {
                result.push_back(iter->second);
                count ++;
            }
            // Second condition: Search the "userId" from the user following list.
            else if (_map[userId].find(iter->first) != _map[userId].end())
            {
                result.push_back(iter->second);
                count ++;
            }
            iter ++;
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) 
    {
        _map[followerId].insert(followeeId);
        return;
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        _map[followerId].erase(followeeId);
        return;
    }

private:
    unordered_map<int, unordered_set<int>> _map {};
    // Store the tweets
    list<pair<int, int>> _list {};
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */