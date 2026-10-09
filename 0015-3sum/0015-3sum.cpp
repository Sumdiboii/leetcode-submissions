#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        
        // 1. Sort the array
        sort(nums.begin(), nums.end()); //
        
        for (int i = 0; i < n - 2; i++) {
            // Early termination: if the smallest number is > 0, sum cannot be 0
            if (nums[i] > 0) break;
            
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int l = i + 1;
            int r = n - 1;
            
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    // Skip duplicate values for the left pointer
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    // Skip duplicate values for the right pointer
                    while (l < r && nums[r] == nums[r + 1]) r--;
                } else if (sum > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return res;
    }
};
