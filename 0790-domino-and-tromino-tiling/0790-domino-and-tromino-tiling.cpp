class Solution {
public:
    int numTilings(int n) {
        // Base cases for small values of n
        if (n == 1) return 1;
        if (n == 2) return 2;

        int MOD = 1e9 + 7;

        // Set up our sliding window (just like Climbing Stairs)
        int prev3 = 1; // Represents dp[i-3] (starts as dp[0])
        int prev2 = 1; // Represents dp[i-2] (starts as dp[1])
        int prev1 = 2; // Represents dp[i-1] (starts as dp[2])
        int current = 0;

        // Build up from step 3 to n
        for (int i = 3; i <= n; i++) {
            
            // The recurrence relation: dp[i] = 2 * dp[i-1] + dp[i-3]
            // We use 2LL to cast to long long to prevent addition overflow before modulo
            current = (2LL * prev1 + prev3) % MOD;

            // Shift our window forward for the next step
            prev3 = prev2;
            prev2 = prev1;
            prev1 = current;
        }

        return current;
    }
};