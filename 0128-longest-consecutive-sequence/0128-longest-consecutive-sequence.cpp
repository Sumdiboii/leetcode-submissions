class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        sort(nums.begin(), nums.end());
        
        int longest = 1;
        int current = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue; // Skip duplicates
            } else if (nums[i] == nums[i - 1] + 1) {
                current++; // Consecutive element found
            } else {
                
                current = 1; // Reset to 1 for a new sequence
            }
            longest = max(longest, current);
        }
        
        return max(longest, current); // Catch the last streak
    }
};
