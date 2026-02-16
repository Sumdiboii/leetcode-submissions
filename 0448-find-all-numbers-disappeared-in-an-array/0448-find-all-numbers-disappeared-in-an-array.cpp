class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> st;

        // Step 1: store all numbers
        for(int x : nums) {
            st.insert(x);
        }

        vector<int> result;

        // Step 2: check from 1 to n
        for(int i = 1; i <= nums.size(); i++) {
            if(!st.count(i)) {
                result.push_back(i);
            }
        }

        return result;
    }
};
