static const auto fast_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define all(x) x.begin(), x.end()

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;

        sort(all(nums));  // Step 1: sort the array

        for (int i = 0; i < n - 2; i++) {
            int newTarget = target - nums[i];  // reduce to 2Sum smaller

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                if (nums[l] + nums[r] < newTarget) {
                    cnt += (r - l);  // count all valid pairs
                    l++;             // move left pointer forward
                } else {
                    r--;             // reduce sum
                }
            }
        }

        return cnt;
    }
};