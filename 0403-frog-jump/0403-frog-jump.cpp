class Solution {
private:
    unordered_map<long long, bool> memo;

    bool solve(int k, int ind, vector<int>& stones) {
        if (ind == stones.size() - 1) return true;

        long long key = ((long long)ind << 32) | (unsigned int)k;
        if (memo.count(key)) return memo[key];

        bool take = false;
        for (int i = -1; i <= 1; i++) {
            int next_jump = k + i;
            if (next_jump <= 0) continue;

            int curr = stones[ind] + next_jump;
            auto it = lower_bound(stones.begin() + ind + 1, stones.end(), curr);

            if (it != stones.end() && *it == curr) {
                int ind1 = it - stones.begin();
                if (solve(next_jump, ind1, stones)) {
                    return memo[key] = true;
                }
            }
        }

        return memo[key] = false;
    }

public:
    bool canCross(vector<int>& stones) {
        if (stones.size() < 2 || stones[1] != 1) return false;
        return solve(1, 1, stones);
    }
};