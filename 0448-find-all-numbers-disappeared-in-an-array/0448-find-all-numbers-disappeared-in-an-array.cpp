class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;

        int expected = 1;
        int i = 0;
        int n = nums.size();

        while (expected <= n) {
            while (i < n && nums[i] < expected) {
                i++;
            }

            if (i < n && nums[i] == expected) {
                expected++;
                i++;
            } else {
                ans.push_back(expected);
                expected++;
            }
        }

        return ans;
    }
};