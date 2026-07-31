class Solution {
public:
    int directions[4][2] = {{-1,0}, {1,0}, {0,-1}, {0, 1}};
    int bfs(int r, int c, vector<vector<int>> grid){
        int area = 1;
        grid[r][c] = 0;
        queue<pair<int, int>> q;
        q.push({r, c});
        while(!q.empty()){
            auto [row, col] = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];
                if(nr >= 0 && nc >= 0 &&
                    nr < grid.size() && nc < grid[0].size() &&
                    grid[nr][nc] == 1){
                        q.push({nr, nc});
                        grid[nr][nc] = 0;
                        area++;
                    }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 0) continue;

                res = max(res, bfs(r, c, grid));
            }
        }
        return res;
    }
};
