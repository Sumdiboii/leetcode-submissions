class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        for (int i = 0; i < n; i++) {
            int leftSum = 0;
            int rightSum = 0;
            
            // Calculate sum of elements to the left
            for (int j = 0; j < i; j++) {
                leftSum += nums[j];
            }
            
            // Calculate sum of elements to the right
            for (int j = i + 1; j < n; j++) {
                rightSum += nums[j];
            }
            
            // Store the absolute difference
            ans[i] = abs(leftSum - rightSum);
        }
        
        return ans;
    }
};