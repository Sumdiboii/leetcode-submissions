class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        if (totalSum % 2 != 0) return false;

        int targetSum = totalSum / 2;
        vector<bool> dp(targetSum + 1, false);
        dp[0] = true;
        for (int n : nums) {
            for (int currSum = targetSum; currSum >= n; currSum--) {
                dp[currSum] = dp[currSum] || dp[currSum - n];
                if (dp[targetSum]) return true;
            }
        }
        return dp[targetSum];
    }
};