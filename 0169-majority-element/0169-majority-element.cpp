class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int leader = 0;
        int cnt = 0;
        for (int num : nums) {
            if (cnt == 0) {
                leader = num;
            }
            if (num == leader) {
                cnt++;
            } else {
                cnt--;
            }
        }
        return leader;
    }
};
