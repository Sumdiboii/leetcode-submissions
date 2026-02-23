class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        int count = 0;
        int prefixSum = 0;

        unordered_map<int,int> mp;
        mp[0] = 1;  // Important: handles subarrays starting from index 0

        for(int i = 0; i < n; i++) {

            prefixSum += nums[i];

            // Check if (prefixSum - k) exists
            if(mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }

            // Store current prefix sum
            mp[prefixSum]++;
        }

        return count;
    }
};