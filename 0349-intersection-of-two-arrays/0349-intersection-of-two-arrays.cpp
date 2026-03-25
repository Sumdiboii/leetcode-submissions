class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset1;
        unordered_set<int> uset2;

        for (int n : nums1) {
            uset1.insert(n);
        }

        vector<int> ans;
        for (int n : nums2) {
            if (uset1.count(n)) {
                uset2.insert(n);
            }
        }

        for( auto & p : uset2){
            ans.push_back(p);
        }
        
        return ans;
    }
};