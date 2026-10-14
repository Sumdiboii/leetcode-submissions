class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minn = INT_MAX; // Start with max value so min() works properly
        int sum = 0;        // Start window sum at 0
        int l = 0;          // Left pointer

        for (int r = 0; r < n; r++) {
            sum += nums[r]; // Expand the window by adding the right element

            // Shrink the window as long as the sum meets or exceeds the target
            while (l<= r && sum >= target) {
                minn = min(minn, r - l + 1); // Track the minimum length
                sum -= nums[l];              // Subtract the element leaving the window
                l++;                         // Move left pointer forward
            }
        }

        // If minn was never updated, it means no valid subarray was found
        return (minn == INT_MAX) ? 0 : minn;
    }
};
