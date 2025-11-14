#include <bits/stdc++.h>
using namespace std;

class Twitter
{
public:
    int count = 0;
    unordered_map<int, vector<pair<int, int>>> tweet;
    unordered_map<int, unordered_set<int>> following;
    Twitter() {}

    void postTweet(int userId, int tweetId)
    {
        count += 1;
        tweet[userId].push_back({count, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<pair<int, int>> userPost = tweet[userId];
        for (auto it : userPost)
        {
            // cout<<it.first<<" "<<it.second<<endl;;
            pq.push(it);
            if (pq.size() > 10)
                pq.pop();
        }

        for (auto it : following[userId])
        {
            userPost = tweet[it];
            for (auto its : userPost)
            {
                // cout<<its.first<<" "<<its.second<<endl;
                pq.push(its);
                if (pq.size() > 10)
                    pq.pop();
            }
        }
        while (!pq.empty())
        {
            auto it = pq.top();
            cout << it.first << " " << it.second << endl;
            ;
            pq.pop();
            ans.push_back(it.second);
        }
        reverse(begin(ans), end(ans));
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        following[followerId].erase(followeeId);
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