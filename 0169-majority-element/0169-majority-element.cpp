class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> umap;
        int n = nums.size();

        // Count frequencies
        for(int num : nums){
            umap[num]++;
        }

        // Find majority element
        for(auto &p : umap){
            if(p.second > n/2){
                return p.first;
            }
        }

        return -1; // just in case, though problem guarantees a majority element exists
    }
};
