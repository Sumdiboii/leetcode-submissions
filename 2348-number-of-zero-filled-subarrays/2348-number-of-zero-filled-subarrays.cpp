class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

         long long cnt = 0; 
         long long streak = 0;


         for ( auto num : nums){
            if(num == 0 ){
                streak ++;
                cnt = cnt + streak;
            }else{
                streak = 0;
            }
         }

         return (long long ) cnt;
    }
};