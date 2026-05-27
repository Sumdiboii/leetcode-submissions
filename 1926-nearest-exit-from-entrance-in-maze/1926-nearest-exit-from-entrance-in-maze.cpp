class Solution {
public:
    int BFS(vector<vector<char>>& maze, pair<int, int>start){
        set<pair<int, int>>visited;
        queue<pair<int, int>>q;
        pair<int, int> node = start;
        map<pair<int, int>, int>ans;
        ans[node] = 0;
        q.push(node);
        visited.insert(node);
        while(!q.empty()){
            node = q.front();
            q.pop();
            if(node != start && (node.first == 0 || node.first == maze.size()-1 || node.second == maze[0].size() -1 || node.second == 0)){
                return ans[node];
            }

            int i=node.first;
            int j=node.second;

            if((i-1)>=0 && maze[i-1][j] == '.' && visited.find({i-1,j}) == visited.end()){
                visited.insert({i-1,j});
                ans[{i-1,j}] = ans[node]+1;
                q.push({i-1,j});
            }
            if((i+1)<=maze.size()-1 && maze[i+1][j] == '.' && visited.find({i+1,j}) == visited.end()){
                visited.insert({i+1,j});
                ans[{i+1,j}] = ans[node]+1;
                q.push({i+1,j});
            }
            if((j+1)<=maze[0].size()-1 && maze[i][j+1] == '.' && visited.find({i,j+1}) == visited.end()){
                visited.insert({i,j+1});
                ans[{i,j+1}] = ans[node]+1;
                q.push({i,j+1});
            }
            if((j-1)>=0 && maze[i][j-1] == '.' && visited.find({i,j-1}) == visited.end()){
                visited.insert({i,j-1});
                ans[{i,j-1}] = ans[node]+1;
                q.push({i,j-1});
            }


        }

        return -1;

    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        pair<int,int>start = {entrance[0], entrance[1]};
        return BFS(maze, start);
    }
};