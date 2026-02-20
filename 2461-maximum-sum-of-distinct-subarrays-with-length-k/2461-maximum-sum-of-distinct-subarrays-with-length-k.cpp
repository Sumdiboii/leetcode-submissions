class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_set<int> window;
        long long sum = 0;
        long long maxsum = 0;

        int left = 0;

        for(int right = 0; right < nums.size(); right++) {

            // remove duplicates
            while(window.count(nums[right])) {
                window.erase(nums[left]);
                sum -= nums[left];
                left++;
            }

            // add element
            window.insert(nums[right]);
            sum += nums[right];

            // maintain window size k
            if(right - left + 1 == k) {

                maxsum = max(maxsum, sum);

                // remove left element to slide window
                window.erase(nums[left]);
                sum -= nums[left];
                left++;
            }
        }

        return maxsum;
    }
};
