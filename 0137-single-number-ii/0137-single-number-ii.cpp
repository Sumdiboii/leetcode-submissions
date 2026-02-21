class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap;

        for( int n: nums){
            umap[n]++;
        }

        for(const auto &ptr : umap){
            if( ptr.second ==1){
                return ptr.first;
            }
        }
        return 0;
    }
};