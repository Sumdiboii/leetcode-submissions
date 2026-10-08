class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0; 
        int cnt  = 0;

        for( int n : nums){
            if( cnt == 0){
                candidate = n;
            }

            if(n == candidate){
                cnt++;
            }else{
                cnt--;
            }
        }

        return candidate;
    }
};