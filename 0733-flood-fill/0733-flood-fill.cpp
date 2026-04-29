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
    void dfs(int r, int c, vector<vector<int>>& image, int oldColor, int newColor){
        int m = image.size();
        int n = image[0].size();

        if(r < 0 || c < 0 || r >= m || c >= n){
            return;
        }

        if(image[r][c] != oldColor){
            return;
        }

        image[r][c] = newColor;

        dfs(r + 1, c, image, oldColor, newColor);
        dfs(r - 1, c, image, oldColor, newColor);
        dfs(r, c + 1, image, oldColor, newColor);
        dfs(r, c - 1, image, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor = image[sr][sc];

        if(oldColor == color){
            return image;
        }

        dfs(sr, sc, image, oldColor, color);

        return image;
    }
};