class Solution {
public:

    vector<int> sortedSquares(vector<int>& nums) {
       int n = nums.size();

       int l =0;
       int r = n-1;
       vector<int> result(n);
       int pos = n-1;

       while(l<=r){
        if(abs(nums[l])<abs(nums[r])){
            result[pos] = nums[r] * nums[r];
            r--;
        }
        else{
             result[pos] = nums[l] * nums[l];
             l++;
        }

        pos--;
       }

       return result;
       
    }
};