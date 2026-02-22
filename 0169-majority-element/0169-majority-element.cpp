class Solution {
public:
    int majorityElement(vector<int>& nums) {
     unordered_map<int,int>umap;
     int m = nums.size();

     for( int n : nums){
        umap[n]++;
     }

     for( auto &p : umap){
        if(p.second>m/2){
            return p.first;
        }
       
     }
      return 0;
    }
};
