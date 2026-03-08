class Solution {
    int dp[101][10001];
public:
    int superEggDrop(int k, int n) {
        memset(dp, -1, sizeof(dp));
        return solve(k, n);
    }
    
    int solve(int k, int n) {
        if (n <= 1 || k == 1) return n;
        if (dp[k][n] != -1) return dp[k][n];
        
        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int left = solve(k - 1, mid - 1);
            int right = solve(k, n - mid);
            
            ans = min(ans, 1 + max(left, right));
            if (left < right) low = mid + 1;
            else high = mid - 1;
        }
        return dp[k][n] = ans;
    }
};