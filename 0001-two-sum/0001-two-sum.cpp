class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        int n = nums.size();

        for( int i = 0; i< n ; i++){

            int diff = target - nums[i];

            if(umap.contains(diff)){
                return {i, umap[diff]};
            }

            umap[nums[i]] = i;
        }

        return {};
    }
};