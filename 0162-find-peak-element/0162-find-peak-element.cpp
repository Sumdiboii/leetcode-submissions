class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        unordered_map<int,int> umap;

        for( int i =0; i < nums.size();i++){
            umap[nums[i]] = i;
        }

        int res  = *max_element(nums.begin(), nums.end());

        return umap[res];
    }
};