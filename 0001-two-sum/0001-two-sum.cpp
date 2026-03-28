class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umap;

        for (int i = 0; i < nums.size(); i++) {

            int diff = target - nums[i];
            if (umap.find(diff) != umap.end()) {
                return {i, umap[diff]};
            }

            umap[nums[i]] = i;
        }


        return {};
    }
};