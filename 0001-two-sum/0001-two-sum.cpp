class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap; // value -> index

        for(int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if(umap.find(diff) != umap.end()) {
                return {umap[diff], i};
            }
            umap[nums[i]] = i; // store current number after checking
        }

        return {};
    }
};