class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        int x=nums.size();
        for(int i=0;i<x-n;i++){
            res.push_back(nums[i]);
            res.push_back(nums[i+n]);
        }
        return res;
    }
};