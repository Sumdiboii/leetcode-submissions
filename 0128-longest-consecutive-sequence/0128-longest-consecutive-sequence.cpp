class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        int longest = 0;

        for (int num : uset) {
            // Only start counting if num is the start of a sequence
            if (!uset.contains(num - 1)) {
                int length = 1;
                

                while (uset.contains(num + length)) {
                    
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};
