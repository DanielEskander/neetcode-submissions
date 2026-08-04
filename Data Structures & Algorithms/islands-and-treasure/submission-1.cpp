class Solution {
public:
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    queue<pair<int, int>> q;
    void bfs(vector<vector<int>>& grid){
        while(!q.empty()){
            auto [r, c] = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];
                if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() &&
                    grid[nr][nc] == INT_MAX){
                    grid[nr][nc] = 1 + grid[r][c];
                    q.push({nr, nc});
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 0)
                    q.push({r, c});
            }
        }
        bfs(grid);
    }
};
