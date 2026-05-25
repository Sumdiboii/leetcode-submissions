class Solution {
public:
    vector<vector<int>> result;

    void solve(vector<int>& candidates, int& target, int i, vector<int> combination, int sum) {
        if(sum == target) {
            result.push_back(combination);
            return;
        }

        if(i >= candidates.size() || sum >= target) {
            return;
        }

        combination.push_back(candidates[i]);
        solve(candidates, target, i, combination, sum + candidates[i]);

        combination.pop_back();
        solve(candidates, target, i + 1, combination, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0, {}, 0);
        return result;
    }
};