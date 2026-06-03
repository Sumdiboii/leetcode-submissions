class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // Use unsigned int to prevent C++ runtime overflow errors on intermediate steps
        vector<unsigned int> dp(target + 1, 0);
        
        // Base case: There is 1 way to reach target 0 (choose nothing)
        dp[0] = 1;
        
        // Build up the DP array from 1 to the target
        for (int i = 1; i <= target; i++) {
            // Try every possible "step size" from the nums array
            for (int num : nums) {
                if (i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
        }
        
        return dp[target];
    }
};