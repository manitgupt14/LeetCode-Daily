
class Twitter {
public:
    unordered_map<int,unordered_set<int>> mp;
    vector<pair<int,int>> newsfeed;
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        newsfeed.push_back({tweetId,userId});
        mp[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for(int i=newsfeed.size()-1;i>=0;i--)
        {
            if(mp[userId].find(newsfeed[i].second)!=mp[userId].end())
            {
                ans.push_back(newsfeed[i].first);
            }
            
            if(ans.size()==10)
                break;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it=mp[followerId].find(followeeId);
        if(it!=mp[followerId].end())
            mp[followerId].erase(it);
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