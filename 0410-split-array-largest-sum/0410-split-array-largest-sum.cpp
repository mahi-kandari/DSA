class Solution {
public:
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INT_MAX));

        long long sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            sum += arr[i];
            dp[1][i] = sum;
        }

        for (int s = 2; s <= k; s++) {
            for (int i = 0; i <= n - s; i++) {
                long long currsum = 0;
                for (int j = i; j <= n - s; j++) {
                    currsum += arr[j];
                    long long remainingsum = dp[s - 1][j + 1];
                    long long a = max(currsum, remainingsum);
                    dp[s][i] = min(dp[s][i], a);
                }
            }
        }

        return dp[k][0];
    }
};