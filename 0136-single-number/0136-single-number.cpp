class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int res=nums[0];

        for( int i =1;i<n;i++){
            res = res ^ nums[i];
        }
        return res;
    }
};