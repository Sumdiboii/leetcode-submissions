class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());

        int longest = 0;

        for (int n : uset) {

            // check if it's the start of a sequence
            if (!uset.count(n - 1)) {

                int current = n;
                int length = 1;

                while (uset.count(current + 1)) {
                    current++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};