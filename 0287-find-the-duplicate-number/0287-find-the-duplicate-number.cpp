class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n  = nums.size();

        unordered_map<int,int> umap;

        for (int n : nums){
            umap[n]++;
        }

        for( const auto p : umap){
            if(p.second != 1){
                return p.first;
            }
        }
        return 0;
    }
};