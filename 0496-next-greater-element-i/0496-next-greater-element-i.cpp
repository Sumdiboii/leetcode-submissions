class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums2.size();
        int m = nums1.size();

        stack<int> monostack;
        vector<int> ans(n, -1);
        unordered_map<int, int> umap;

        for (int i = 0; i < n; i++) {

            while (!monostack.empty() && nums2[monostack.top()] < nums2[i]) {
                ans[monostack.top()] = nums2[i];
                monostack.pop();
            }

            monostack.push(i);
        }

        for (int i = 0; i < n; i++) {
            umap[nums2[i]] = ans[i];
        }

        vector<int> result;

        for (int i = 0; i < m; i++) {
            result.push_back(umap[nums1[i]]);
        }

        return result;
    }
};