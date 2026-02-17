class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int n = nums.size();
      unordered_map<int,int> umap;

      for(int num : nums){
        umap[num]++;
      }

      for(const auto &p : umap){
        if(p.second> n/2){
            return (p.first);
        }
      }

      return -1;
    }
};
