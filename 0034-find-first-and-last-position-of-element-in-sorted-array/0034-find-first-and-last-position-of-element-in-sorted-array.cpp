class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2);
        ans[0] = -1;
        ans[1] = -1;

        int l = 0; int r = n-1;
        int first  = -1;
        int last = -1;

        while(l<=r){

            int mid  = l + (r-l)/2;

            if( nums[mid] == target){
                first = mid;
                r = mid-1;
            }
            else if(nums[mid] < target){
                l = mid + 1;

            }else{
                r = mid-1;
            }
        }

        ans[0] = first;


        l = 0; 
        r = n-1;
        
      

        while(l<=r){

            int mid  = l + (r-l)/2;

            if( nums[mid] == target){
                last = mid;
                l = mid+1;
            }
            else if(nums[mid] < target){
                l = mid + 1;

            }else{
                r = mid-1;
            }
        }
        ans[1] = last;

        return ans;


    }
};