class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> umap;

        for (int n : nums) {
            umap[n]++;
        }

        for (auto& p : umap) {

            if( p.second > 1){
                return true;
            }
        }
        return false;
    }
};