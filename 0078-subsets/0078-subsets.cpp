class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res,int index, vector<int> & op){
        if(index >= nums.size()){
            res.push_back(op);
            return;
        }
        solve(nums, res, index + 1, op);

        op.push_back(nums[index]);
        solve(nums, res, index + 1, op);

        op.pop_back();
        return;
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> op;
        vector<vector<int>> res;
        solve(nums, res, 0, op);
        return res;

        
    }
};