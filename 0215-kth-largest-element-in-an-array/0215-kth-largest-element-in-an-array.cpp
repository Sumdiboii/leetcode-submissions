class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for (int n : nums) {
            pq.push(n);
        }

        int ans = 0;
        while (k != 0) {
            ans = pq.top();
            pq.pop();

            k--;
        }

        return ans;
    }
};