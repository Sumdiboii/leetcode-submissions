class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0] = 1;  // base case

        int sum = 0;
        int count = 0;

        for(int x : nums) {
            sum += x;

            if(freq.count(sum - k)) {
                count += freq[sum - k];
            }

            freq[sum]++;
        }

        return count;
    }
};
