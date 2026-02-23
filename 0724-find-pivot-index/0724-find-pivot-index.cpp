class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();

        if (n == 0) return -1;
        if (n == 1) return 0;

        // Step 1: Build prefix sum in-place
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }

        int total = nums[n - 1];

        // Step 2: Check pivot index
        for (int i = 0; i < n; i++) {

            int leftSum;
            if (i == 0)
                leftSum = 0;
            else
                leftSum = nums[i - 1];

            int rightSum = total - nums[i];

            if (leftSum == rightSum)
                return i;
        }

        return -1;
    }
};