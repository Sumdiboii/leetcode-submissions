class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        int lmt = nums.size() / 2;


        for( int i = 0; i< nums.size(); i++){
            umap[nums[i]]++;
        }

        for( const auto&p : umap){
            if(p.second >lmt){
                return p.first;
            }
        }

        return 0;
    }
};