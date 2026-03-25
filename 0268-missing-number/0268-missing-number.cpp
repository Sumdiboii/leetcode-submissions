class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sum = n * (n + 1) / 2;
        int aqsum = 0;

        for (int n : nums) {
            aqsum += n;
        }

        if( aqsum == sum ){
            return 0;
        }
        else{
            return sum - aqsum;
        }
    }
};