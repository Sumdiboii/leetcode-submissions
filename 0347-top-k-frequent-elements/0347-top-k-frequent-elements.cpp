class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int > umap;

        for( int n : nums){
            umap[n]++;
        }

        vector<int>res;

        while(k!=0){
            int maxcnt = INT_MIN;
            int element = 0;
            for( auto &p : umap){
                if(p.second > maxcnt){
                    maxcnt = p.second;
                    element  = p.first;
                }

            }

            res.push_back(element);
            umap.erase(element);
            k--;
        }

        return res;
    }
};