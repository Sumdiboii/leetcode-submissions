class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        res.reserve(2*n);

        res.insert(res.end(), nums.begin(), nums.end());
        res.insert(res.end(), nums.begin(), nums.end());

        return res;
    }
};