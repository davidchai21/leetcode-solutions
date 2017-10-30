struct news {
        int time;
        int userId;
        int newsId;
        news(int t, int user, int id): time(t), newsId(id), userId(user) {}
    };

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        time=0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        news t(time,userId,tweetId);
        time++;
        m[userId].push_back(t);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<news> res;
        fetchdata(userId,res);
        for (auto p:f[userId]) {
            if (p!=userId) fetchdata(p,res);
        }
        sort(res.begin(),res.end(),[](news a, news b){return a.time>b.time;});
        vector<int> t;
        for (int i=0;i<10 && i<res.size();i++) {
            t.push_back(res[i].newsId);
        }
        return t;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        f[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        f[followerId].erase(followeeId);
    }
    
    void fetchdata(int userId, vector<news>& res) {
        int k=max((int)m[userId].size()-10,0);
        for (int i=m[userId].size()-1;i>=k;i--) {
            res.push_back(m[userId][i]);
        }
    }
private:
    unordered_map<int,unordered_set<int> > f;
    unordered_map<int,vector<news> > m;
    int time;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */