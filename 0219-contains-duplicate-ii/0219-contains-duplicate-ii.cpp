class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> window;

        for(int i = 0; i < nums.size(); i++) {

            // remove element outside window
            if(i > k) {
                window.erase(nums[i - k - 1]);
            }

            // check duplicate
            if(window.count(nums[i])) {
                return true;
            }

            // add element
            window.insert(nums[i]);
        }

        return false;
    }
};
