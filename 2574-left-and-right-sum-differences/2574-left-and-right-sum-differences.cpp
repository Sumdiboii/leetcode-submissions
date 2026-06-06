class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n, 0);
        vector<int> rightSum(n, 0);
        vector<int> ans(n);
        
        // Build the leftSum array (Prefix sum)
        for (int i = 1; i < n; i++) {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
        }
        
        // Build the rightSum array (Suffix sum)
        for (int i = n - 2; i >= 0; i--) {
            rightSum[i] = rightSum[i + 1] + nums[i + 1];
        }
        
        // Calculate the absolute difference
        for (int i = 0; i < n; i++) {
            ans[i] = abs(leftSum[i] - rightSum[i]);
        }
        
        return ans;
    }
};