class Solution {
public:
    int climbStairs(int n) {
        // Handle the edge case where n = 1 (or 0)
        if (n <= 1) return 1;

        int prev1 = 1; // Represents dp[i-1]
        int prev2 = 1; // Represents dp[i-2]
        int res = 0;

        for(int i = 2; i <= n; i++){
            res = prev1 + prev2; // 1. Calculate the current step
            prev2 = prev1;       // 2. Shift prev2 forward
            prev1 = res;         // 3. Shift prev1 forward to the new result
        } 

        return res;
    }
};