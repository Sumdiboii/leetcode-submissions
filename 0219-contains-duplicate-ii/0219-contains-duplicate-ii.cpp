class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> uset;

        int l = 0;
        for (int r = 0; r < nums.size(); r++) {

            if (r - l > k) {
                uset.erase(nums[l]);
                l++;
            }

            if (uset.contains(nums[r])) {
                return true;
            }

            uset.insert(nums[r]);
        }

        return false;
    }
};