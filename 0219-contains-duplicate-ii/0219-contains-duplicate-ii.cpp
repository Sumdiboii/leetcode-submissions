class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        unordered_set<int> window;

        int left = 0;

        for(int right = 0; right < nums.size(); right++) {

            // If duplicate found inside window
            if(window.count(nums[right])) {
                return true;
            }

            // Add current element
            window.insert(nums[right]);

            // Shrink window if size exceeds k
            if(right - left >= k) {
                window.erase(nums[left]);
                left++;
            }
        }

        return false;
    }
};
