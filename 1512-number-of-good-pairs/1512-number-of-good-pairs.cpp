class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        unordered_map<int,int> freq;
        int cnt = 0;

        for(int num : nums) {
            cnt += freq[num];   // add how many times we've seen it
            freq[num]++;        // increase frequency
        }

        return cnt;
    }
};