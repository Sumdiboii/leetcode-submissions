class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
       int n = nums.size();
       int maxsum = 0;
       int currsum = 0;

       for( int i = 0; i < k ; i++){
            currsum += nums[i];
            maxsum = currsum;
       }

       for(int i = k; i< n; i++){
        currsum += nums[i];
        currsum -= nums[i-k];

        maxsum = max ( maxsum, currsum);
       }
      
return ((double)maxsum/k);
    }
};