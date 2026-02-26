class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt =0;
        int r = grid.size();
        int c = grid[0].size();

        for( int i =0; i< r; i++){
            for( int j =0; j< c; j++){
                    if( grid[i][j]< 0){
                        cnt++;
                    }
            }
        }
        return cnt;
    }
};