class Solution {
public:
    int solve(int n, vector<int>& memo) {
        if (n <= 2) return n;
        
        // If we have already calculated this step, return it immediately
        if (memo[n] != -1) return memo[n];
        
        // Otherwise, calculate it recursively and save the result
        return memo[n] = solve(n - 1, memo) + solve(n - 2, memo);
    }

    int climbStairs(int n) {
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
};