class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            // start only at the beginning of a sequence
            if (!numSet.contains(num - 1)) {
                int length = 1;

                while (numSet.contains(num + length)) {
                    length++;
                }

                longest = max(longest, length);
            }
        }
        return longest;
    }
};
