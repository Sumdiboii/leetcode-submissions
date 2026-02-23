class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int sum = 0;
        int minlen = INT_MAX;

        for(int r = 0; r < n; r++) {
            sum += nums[r];  // add current element

            // shrink window as much as possible while sum >= target
            while(sum >= target) {
                minlen = min(minlen, r - l + 1); // current window length
                sum -= nums[l];                  // remove leftmost element
                l++;
            }
        }

        // If no valid subarray found
        return minlen == INT_MAX ? 0 : minlen;
    }
};