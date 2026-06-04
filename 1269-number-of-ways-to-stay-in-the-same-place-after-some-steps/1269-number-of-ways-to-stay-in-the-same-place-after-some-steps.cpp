class Solution {
public:
    int numWays(int steps, int arrLen) {
        int MOD = 1e9 + 7;
        int max_pos = min(arrLen - 1, steps / 2);
        
        vector<int> dp(max_pos + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= steps; ++i) {
            vector<int> next_dp(max_pos + 1, 0);
            for (int j = 0; j <= max_pos; ++j) {
                long long ans = dp[j]; // Stay
                if (j > 0) {
                    ans = (ans + dp[j - 1]) % MOD; // Move Right
                }
                if (j < max_pos) {
                    ans = (ans + dp[j + 1]) % MOD; // Move Left
                }
                next_dp[j] = ans;
            }
            dp = next_dp;
        }
        
        return dp[0];
    }
};