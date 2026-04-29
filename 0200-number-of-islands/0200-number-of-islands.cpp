static const auto fast_io = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define all(x) x.begin(), x.end()
#define pb push_back
#define f first
#define s second

// this code belongs to Sumedh Pimplikar and is my official submission towards this contest problem statement

class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if(r < 0 || c < 0 || r >= m || c >= n){
            return;
        }

        if(grid[r][c] == '0'){
            return;
        }

        grid[r][c] = '0';

        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int islands = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(i, j, grid);
                }
            }
        }

        return islands;
    }
};