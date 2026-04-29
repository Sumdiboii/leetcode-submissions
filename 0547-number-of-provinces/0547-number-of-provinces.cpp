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
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis){
        vis[node] = 1;

        for(int j = 0; j < isConnected.size(); j++){
            if(isConnected[node][j] == 1 && !vis[j]){
                dfs(j, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);

        int provinces = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                provinces++;
                dfs(i, isConnected, vis);
            }
        }

        return provinces;
    }
};