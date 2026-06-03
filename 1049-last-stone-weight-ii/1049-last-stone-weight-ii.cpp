class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = accumulate(stones.begin(), stones.end(), 0);
        
        // Our perfect ideal bucket weight
        int target = totalSum / 2;

        // Our boolean checklist
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        int maxReachableSum = 0; // To keep track of the heaviest bucket we can make

        // 0/1 Knapsack Logic
        for (int stone : stones) {
            for (int i = target; i >= stone; i--) {
                dp[i] = dp[i] || dp[i - stone];
                
                // If we successfully made this sum, track it!
                if (dp[i]) {
                    maxReachableSum = max(maxReachableSum, i);
                }
            }
        }

        // We found the heaviest possible Bucket 1 (maxReachableSum).
        // Bucket 2 is just whatever stones are left over (totalSum - maxReachableSum).
        // The final smashed stone is Bucket 2 - Bucket 1:
        // (totalSum - maxReachableSum) - maxReachableSum
        return totalSum - (2 * maxReachableSum);
    }
};