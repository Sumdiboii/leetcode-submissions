class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size()+1;

        int maxsum = (n* (n-1))/2;
        int sum =0;

        for(int num : nums){
                sum += num;
        }

        int res = maxsum - sum;

        return res;


    }
};