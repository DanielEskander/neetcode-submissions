class Solution {
public:
    int bfs(vector<vector<int>>& grid, int r, int c){
        int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        int local = 0;
        queue<pair<int, int>> q;
        q.push({r, c});
        while(!q.empty()){
            auto [cr, cc] = q.front();
            q.pop();
            for(auto& d : directions){
                int nr = cr + d[0];
                int nc = cc + d[1];

                if(nr < 0 || nc < 0 ||
                    nr >= grid.size() || nc >= grid[0].size() ||
                    grid[nr][nc] != 1)
                    continue;
                
                grid[nr][nc] = 0;
                q.push({nr, nc});
                local++;
            }
        }
        return local;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] != 1) continue;
                res = max(res, bfs(grid, r, c));
            }
        }
        return res;
    }
};
