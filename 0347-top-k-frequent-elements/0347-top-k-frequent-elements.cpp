class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies
        unordered_map<int, int> umap;
        for(int n : nums){
            umap[n]++;
        }
        
        // Step 2: Use a min-heap to keep track of top k elements
        // Store pair as {frequency, element}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(const auto& p : umap){
            pq.push({p.second, p.first}); // Notice: frequency is p.second, element is p.first
            
            // If heap size exceeds k, remove the element with the lowest frequency
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        // Step 3: Extract elements from the heap into the result vector
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second); // Extract the element
            pq.pop();
        }
        
        return res;
    }
};
