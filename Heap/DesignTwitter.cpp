/* Leet code 355.
355. Design Twitter

Design a simplified version of Twitter where users can post tweets,
 follow/unfollow another user, and is able to see 
 the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
 

Example 1:
Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
 

Constraints:
1 <= userId, followerId, followeeId <= 500
0 <= tweetId <= 104
All the tweets have unique IDs.
At most 3 * 104 calls will be made to postTweet, getNewsFeed, follow, and unfollow.
A user cannot follow himself.
*/
#include<iostream>
#include<vector>
#include <unordered_set>
#include<queue>

using namespace std;

class Twitter {
    struct Tweet
    {
        int tweetId;
        int time;
        Tweet(int id, int t): tweetId(id), time(t){}
    };
    
    //global clock
    int time;
    //map, userId to Tweets posted by the user
    unordered_map<int, vector<Tweet>> m_tweets;

    //map, userID to unordered_set of followed userIDs
    unordered_map<int, unordered_set<int>> m_followed;

    class compare{
        public:
        bool operator()(const Tweet&a, const Tweet&b)
        {
            return a.time > b.time;
        }
    };
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // if(m_tweets.find(userId) == m_tweets.end())
        // {
        //    m_tweets.insert(userId,{Tweet(tweetId, time)});
        // }

        m_tweets[userId].push_back(Tweet(tweetId, time));
        time++;
    }
    
    //returning the tweetIds of 10 most recents tweets done by me OR by my followings.
    vector<int> getNewsFeed(int userId) {
        //minHeap, to keep track of top 10 tweets
        priority_queue<Tweet, vector<Tweet>, compare> minHeap;
        //add my tweets
        if(m_tweets.find(userId) != m_tweets.end())
        {
            for(auto tweet : m_tweets[userId])
            {
                minHeap.push(tweet);
                if(minHeap.size() > 10)
                {
                    minHeap.pop();//remove the oldest tweet
                }
            }
        }
        //add tweets from my folllowings
        if(m_followed.find(userId) != m_followed.end())
        {
            auto myfollowings = m_followed[userId];
            for(auto followeeId : myfollowings)
            {
                if(m_tweets.find(followeeId) != m_tweets.end())
                {
                    for(auto tweet : m_tweets[followeeId])
                    {
                        minHeap.push(tweet);
                        if(minHeap.size() > 10)
                        {
                            minHeap.pop();//remove the oldest tweet
                        }
                    }
                }
            }
        }
        vector<int> recentTweetsIds;
        //now I have top 10 most recent tweets
        while(!minHeap.empty())
        {
            //C++17 
            auto [tweetId, time] = minHeap.top();
            minHeap.pop();
            recentTweetsIds.push_back(tweetId);
        }
        reverse(recentTweetsIds.begin(), recentTweetsIds.end());
        return recentTweetsIds;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) return; //I can't follow myself
        m_followed[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(m_followed.find(followerId) != m_followed.end())
        {
            m_followed[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */