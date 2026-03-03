class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> umap;

        // Step 1: count frequency
        for(int n : nums){
            umap[n]++;
        }

        // Step 2: max heap (frequency, number)
        priority_queue<pair<int,int>> pq;

        for(auto p : umap){
            pq.push({p.second, p.first});
        }

        // Step 3: get top k elements
        vector<int> ans;

        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};