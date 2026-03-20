class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 1;

        vector<int> vect;

        while (l <= r) {
            if (abs(nums[l]) < abs(nums[r])) {
                vect.push_back(nums[r] * nums[r]);
                r--;
            } else {
                vect.push_back(nums[l] * nums[l]);
                l++;
            }
        }

        reverse(vect.begin(), vect.end());

        return vect;
    }
};