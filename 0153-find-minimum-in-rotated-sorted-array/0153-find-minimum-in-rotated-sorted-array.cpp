class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int res = *min_element(nums.begin(), nums.end());

        return res;
    }
};