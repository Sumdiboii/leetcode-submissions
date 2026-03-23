class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n   = gifts.size();

        priority_queue <int> maxheap;
        long long ans = 0;

        for( auto n : gifts){
            maxheap.push(n);
        }

        while(k--){
            maxheap.push(sqrt(maxheap.top()));
            maxheap.pop();
        }

        while(!maxheap.empty()){
            ans += maxheap.top();
            maxheap.pop();
        }

        return ans;


        
    }
};