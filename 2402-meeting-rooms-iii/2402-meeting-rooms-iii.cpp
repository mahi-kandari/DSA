class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> free;
        for (int i = 0; i < n; i++) {
            free.push(i);
        }

        priority_queue<pair<long long, long long>, 
                       vector<pair<long long, long long>>, 
                       greater<pair<long long, long long>>> busy;

        vector<int> ans(n, 0);

        for (int i = 0; i < meetings.size(); i++) {
            long long start = meetings[i][0];
            long long end = meetings[i][1];
            long long duration = end - start;

            while (!busy.empty() && busy.top().first <= start) {
                free.push(busy.top().second);
                busy.pop();
            }

            if (!free.empty()) {
                int room = free.top();
                free.pop();
                busy.push({end, room});
                ans[room]++;
            } else {
                auto [earliest_end, room] = busy.top();
                busy.pop();
                busy.push({earliest_end + duration, room});
                ans[room]++;
            }
        }

        int max_meetings = 0;
        int result_room = 0;
        for (int i = 0; i < n; i++) {
            if (ans[i] > max_meetings) {
                max_meetings = ans[i];
                result_room = i;
            }
        }

        return result_room;
    }
};