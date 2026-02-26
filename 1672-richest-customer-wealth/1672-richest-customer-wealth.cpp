class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {

        int rows = accounts.size();
        int cols = accounts[0].size();

        int maxWealth = 0;

        for(int i = 0; i < rows; i++) {

            int currentWealth = 0;

            for(int j = 0; j < cols; j++) {
                currentWealth += accounts[i][j];
            }

            maxWealth = max(maxWealth, currentWealth);
        }

        return maxWealth;
    }
};