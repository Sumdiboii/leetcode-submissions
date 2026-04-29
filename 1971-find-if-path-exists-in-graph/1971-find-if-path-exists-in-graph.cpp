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


class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].pb(v);
            adj[v].pb(u);
        }

        vector<int> vis(n, 0);

        queue<int> q;
        q.push(source);
        vis[source] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == destination){
                return true;
            }

            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return false;
    }
};