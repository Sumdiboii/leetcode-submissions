class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            // left vals will be even, right vals will be odd
            if (nums[left] % 2 == 0) {
                left += 1;
            } else if (nums[right] % 2 == 1) {
                right -= 1;
            } else {
                swap(nums[left], nums[right]);
                left += 1;
                right -= 1;
            }
        }
        return nums;
    }
};