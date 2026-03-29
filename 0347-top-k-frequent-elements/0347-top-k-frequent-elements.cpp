class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;

        for( int n : nums){
            umap[n]++;
        }

        vector<int>res;


        while (k--) {
            int maxFreq = 0;
            int element = 0;

            for (auto &p : umap) {
                if (p.second > maxFreq) {
                    maxFreq = p.second;
                    element = p.first;
                }
            }

            res.push_back(element);
            umap.erase(element);
        }


        return res;
    }
};