class Solution {
public:
    int solve(int n, vector<int>& memo) {
        // Base Cases: 1 way for step 1, 2 ways for step 2
        if (n <= 2) return n;
        
        // Check the notepad: If we already calculated step n, return it instantly
        if (memo[n] != -1) return memo[n];
        
        // Otherwise, calculate it recursively and save the result in the notepad
        memo[n] = solve(n - 1, memo) + solve(n - 2, memo);
        
        return memo[n];
    }

    int climbStairs(int n) {
        // Create a memoization array filled with -1 (meaning "uncalculated")
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
};