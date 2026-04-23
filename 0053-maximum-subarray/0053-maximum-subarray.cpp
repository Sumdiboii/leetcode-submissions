class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maxsum = INT_MIN;
        long long curr = 0;


        for ( int i = 0; i< nums.size(); i++){
            curr += nums[i];

            if( curr> maxsum){
                maxsum = curr;
            }


            if( curr< 0){
                curr = 0;
            }
        }


        return maxsum;
    }
};