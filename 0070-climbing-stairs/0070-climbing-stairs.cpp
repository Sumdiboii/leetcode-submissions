class Solution {
public:
    int climbStairs(int n) {
        // We need size n+3 to safely hold dp[n+1] and dp[n+2] base cases
        vector<int> dp(n + 3); 

        // Base cases at the TOP of the stairs
        dp[n] = 1;     // There is 1 way to finish if you are already at the top (do nothing)
        dp[n+1] = 0;   // 0 ways to finish if you stepped past the roof
        dp[n+2] = 0;   

        // Loop backwards from the top down to 0
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i+1] + dp[i+2];
        }

        // The answer is the number of ways to finish starting from step 0
        return dp[0]; 
    }
};