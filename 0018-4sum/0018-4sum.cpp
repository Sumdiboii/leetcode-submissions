static const auto fast_io = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define all(n) nums.begin(), nums.end()

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;

        sort(all(n));

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n; j++) {
                if (j > i+1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                int l = j + 1;
                int r = n - 1;

                while (l < r) {

                    long long sum  = 1LL * nums[l] + nums[r] + nums[i] + nums[j];
                    if ( sum == target) {
                        result.push_back({nums[i], nums[j], nums[l], nums[r]});

                        while(l<r && nums[l] == nums[l+1]){
                            l++;
                        }

                        while(l<r && nums[r] == nums[r-1]){
                            r--;
                        }

                        l++;
                        r--;
                    }

                    else if(sum < target){
                        l++;
                    }
                    else{
                        r--;
                    }
                }


            }
        }
        return result;
    }
};