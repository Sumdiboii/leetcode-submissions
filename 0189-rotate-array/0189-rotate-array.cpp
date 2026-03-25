class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int rot = k % n;
    reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + rot);
        reverse(nums.begin() + rot, nums.end());
        

    }
};