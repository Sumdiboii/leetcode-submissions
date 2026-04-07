class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        //first find the pivot element 
        int idx = -1;
        for(int i = n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }
        }
        if(idx == -1){
            reverse(nums.begin(),nums.end());
        }
        else{
            //now we will find the just greater element from this indexed element from the backend
            // for(int i = n-1;i>=0;i--){
            //     if(nums[i]>nums[idx]){
            //         swap(nums[i],nums[idx]);
            //         break;
            //     }
            // }
            //so the above approach of only swap is wrong (i.e -> 1 3 2) It will give 2 3 1 according to above approach but it should be 2 1 3
            

            //so we need to somehow reverse it 
            for(int i = n-1;i>=0;i--){
                if(nums[i]>nums[idx]){
                    swap(nums[i],nums[idx]);
                    reverse(nums.begin()+ idx + 1 , nums.end());
                    break;
                }
            }
        }
    }
};