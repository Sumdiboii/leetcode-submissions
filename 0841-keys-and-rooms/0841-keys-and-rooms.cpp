class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[node] = 1;

        for (int j = 0; j < adj[node].size(); j++) {
            if (!visited[adj[node][j]]) {
                dfs(adj[node][j], visited, adj);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, 0);
        dfs(0, visited, rooms);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
};