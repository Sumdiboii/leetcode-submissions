class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> umap;

        for (int n : nums) {
            umap[n]++;
        }

        for (const auto& p : umap) {
            if (p.second > n / 2) {
                return p.first;
            }
        }

        return 0;
    }
};