class Solution {
public:
    int singleNumber(vector<int>& nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());
    int res = nums[0];



    for( int i = 1; i< n ; i++){
        res = res ^ nums[i];
    }
return res;

    }
};