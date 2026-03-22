class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                result.push_back(i);
            }
        }

        if (result.empty()) {
            return {-1, -1};
        }

        return {result.front(), result.back()};
    }
};