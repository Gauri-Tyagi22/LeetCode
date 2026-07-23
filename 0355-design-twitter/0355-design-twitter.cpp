class Twitter {
public:
int timer;
unordered_map<int,vector<pair<int,int>>>tweets;
unordered_map<int,unordered_set<int>>followmap;
    Twitter() {
       timer=0; 
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId,timer++});
    }
    
    vector<int> getNewsFeed(int userId) {
        followmap[userId].insert(userId);
        priority_queue<vector<int>>pq;
         for (int followee : followmap[userId]) {
            if (tweets[followee].empty())
                continue;

            int idx = tweets[followee].size() - 1;

            pq.push({
                tweets[followee][idx].second, 
                tweets[followee][idx].first,  
                followee,
                idx
            });
        }

        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {

            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int tweetId = curr[1];
            int user = curr[2];
            int idx = curr[3];

            ans.push_back(tweetId);
            if (idx > 0) {
                idx--;

                pq.push({
                    tweets[user][idx].second,
                    tweets[user][idx].first,
                    user,
                    idx
                });
            }
        }

        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followmap[followerId].erase(followeeId);
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