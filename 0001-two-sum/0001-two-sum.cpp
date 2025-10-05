class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int diff=0;

        for(int i=0;i<nums.size();i++){

            diff =target-nums[i];

            if(map.find(diff) != map.end()){
                return {map[diff], i};
            }
            map.insert({nums[i], i});
        }
        return {};
    }
    
};
