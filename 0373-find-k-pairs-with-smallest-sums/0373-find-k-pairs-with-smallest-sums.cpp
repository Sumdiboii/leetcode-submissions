class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;

        if (nums1.empty() || nums2.empty() || k == 0) {
            return ans;
        }

        // {sum, i, j}
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        int n1 = nums1.size();
        int n2 = nums2.size();

        // Push first element of each row
        for (int i = 0; i < min(n1, k); i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while (!pq.empty() && k--) {
            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});

            // Push next element in same row
            if (j + 1 < n2) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return ans;
    }
};