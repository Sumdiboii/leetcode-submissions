class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: Count frequency
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create buckets
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);

        for (auto &p : freq) {
            int num = p.first;
            int count = p.second;
            bucket[count].push_back(num);
        }

        // Step 3: Collect top k frequent elements
        vector<int> res;

        for (int i = n; i >= 1; i--) {
            for (int num : bucket[i]) {
                res.push_back(num);
                if (res.size() == k) {
                    return res;
                }
            }
        }

        return res;
    }
};