class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for( int n : nums){
            pq.push(n);


        }

        int res = 0;

        while(k!=0){
            res = pq.top();
            pq.pop();
            k--;
        }

        return res;
    }
};