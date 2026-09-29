class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;

        int diff = 0;

        for(int i = 0; i< nums.size(); i++){

            diff = target - nums[i];

            if(umap.contains(diff)){
                return {i, umap[diff]};
            }

            umap[nums[i]] = i;
        }

        return {};
    }
};