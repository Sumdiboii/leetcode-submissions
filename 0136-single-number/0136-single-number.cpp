class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int val = nums[0];
        int n = nums.size();

        for( int i = 1; i< n; i++){
            val = val ^ nums[i];
        }

        return val;
    }
};