static const auto fast_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n;) {
                int start = j + 1, end = n - 1;

                while (start < end) {
                    long long sum = (long long)nums[i] + (long long)nums[j] +
                                    (long long)nums[start] +
                                    (long long)nums[end];
                    if (target == sum) {
                        ans.push_back(
                            {nums[i], nums[j], nums[start], nums[end]});
                        start++;
                        end--;
                        while (start < end && nums[start] == nums[start - 1])
                            start++;
                    } else if (sum < target)
                        start++;
                    else
                        end--;
                }
                j++;

                while (j < n && nums[j] == nums[j - 1])
                    j++;
            }
        }
        return ans;
    }
};