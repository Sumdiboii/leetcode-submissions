class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int i = 0, j = n - 1;
        int ans = 0;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (citations[mid] < n - mid)
                i = mid + 1;
            else if (citations[mid] >= n - mid) {
                ans = n - mid;
                j = mid - 1;
            }
        }
        return ans;
    }
};