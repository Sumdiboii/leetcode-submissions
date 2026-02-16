class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
  
        unordered_map<int,int> smap;
        

        for(int i=0; i<nums.size(); i++){
            int diff= target - nums[i];

            if(smap.count(diff) && smap[diff] != i){
                return{i,smap[diff]};
            }
            smap[nums[i]]=i;
        }
        return{};
    }
    
    //one pass hashmap 
};
