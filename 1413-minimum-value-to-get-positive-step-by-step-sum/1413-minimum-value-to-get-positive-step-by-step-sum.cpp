class Solution {
public:
    int minStartValue(vector<int>& nums) {

        int n = nums.size();

        // Build prefix sum
        for(int i = 1; i < n; i++){
            nums[i] += nums[i-1];
        }

        int minPrefix = *min_element(nums.begin(), nums.end());

        if(minPrefix >= 1)
            return 1;

        return abs(minPrefix)+1;
    }
};