class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> uset(nums.begin(), nums.end()); // Efficient insertion
        int longest = 0;

        for (int n : uset) {
            // Check if 'n' is the start of a sequence
            // If n - 1 exists, then 'n' is NOT the start, so skip it
            if (uset.find(n - 1) == uset.end()) {
                int currentNum = n;
                int currentStreak = 1;

                // Keep counting the elements in the sequence
                while (uset.find(currentNum + 1) != uset.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};
