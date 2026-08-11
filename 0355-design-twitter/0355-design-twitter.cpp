class Twitter {
private:
    int count;
    vector<set<int>> folow;
    vector<priority_queue<pair<int, int>>> feed;

public:
    Twitter() {
        count = 0;
        folow.resize(501);
        feed.resize(501);
    }

    void postTweet(int userId, int tweetId) {
        feed[userId].push({count, tweetId});
        count++;
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq = feed[userId];
        for (auto it : folow[userId]) {
            priority_queue<pair<int, int>> f = feed[it];

            while (!f.empty()) {
                pq.push(f.top());
                f.pop();
            }
        }
        vector<int> res;
        while (!pq.empty() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        folow[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        folow[followerId].erase(followeeId);
    }
};