class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int s = nums.size();

        res.reserve(nums.size());

        unordered_map<int,int> umap;

        for( int n: nums){
            umap[n]++;
        }

        for( const auto &ptr : umap){
            if(ptr.second > s/3){
                res.push_back(ptr.first);
            }
        }

        return res;


    }
};