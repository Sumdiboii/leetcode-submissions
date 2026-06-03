class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // Edge Cases:
        // 1. If the target is physically impossible to reach (bigger than total sum)
        // 2. If the (totalSum + target) is odd, we can't divide it into integers
        if (abs(target) > totalSum || (totalSum + target) % 2 != 0) {
            return 0;
        }

        // Calculate our new knapsack capacity
        int subsetTarget = (totalSum + target) / 2;

        // Our tally counter checklist. 
        // dp[i] represents "how many ways can I make the sum i?"
        vector<int> dp(subsetTarget + 1, 0);
        
        // Base case: There is exactly 1 way to make a sum of 0 (pick nothing)
        dp[0] = 1;

        // 0/1 Knapsack Logic
        for (int num : nums) {
            // Reverse loop to ensure we only use each number once
            for (int i = subsetTarget; i >= num; i--) {
                // The number of ways to make the current sum is:
                // (Ways to make it WITHOUT this number) + (Ways to make it WITH this number)
                dp[i] = dp[i] + dp[i - num];
            }
        }

        return dp[subsetTarget];
    }
};