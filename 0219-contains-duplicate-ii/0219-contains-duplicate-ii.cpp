class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> uset;
        int n = nums.size();

        int l = 0;
         for  (int r = 0; r < n; r++){

            if(r - l > k){
                uset.erase(nums[l]);
                l++;
            }




            if(uset.count(nums[r])){
                return true;
            }


            uset.insert(nums[r]);
         }


         return false;


    }
};