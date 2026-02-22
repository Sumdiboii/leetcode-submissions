class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> umap;

        // Step 1: count frequency
        for(int n : nums){
            umap[n]++;
        }

        // Step 2: move map to vector of pairs
        vector<pair<int,int>> vec;
        for(auto p : umap){
            vec.push_back(p); // {number, frequency}
        }

        // Step 3: sort based on frequency descending
        sort(vec.begin(), vec.end(),
             [](pair<int,int>& a, pair<int,int>& b){
                 return a.second > b.second;
             });

        // Step 4: take top k numbers
        vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(vec[i].first);
        }

        return result;
    }
};