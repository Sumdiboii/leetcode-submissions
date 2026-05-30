class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> umap;
        int n = nums.size();
        int res = 0;

        for( auto p : nums){
            umap[p]++;
        }

        for( auto &p : umap){
            if( p.second > n/2){
                res = p.first;
                return res;
            }
        }
return -1;
        
    }
};