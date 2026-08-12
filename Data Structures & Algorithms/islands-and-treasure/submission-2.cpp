class Solution {
public:
    void bfs(vector<vector<int>>& grid, queue<pair<int, int>> q){
        int INF = INT_MAX;
        int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(auto& d : directions){
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr < 0 || nc < 0 ||
                   nr >= grid.size() || nc >= grid[0].size() ||
                   grid[nr][nc] != INF) continue;
                
                grid[nr][nc] = grid[r][c] + 1;
                q.push({nr,nc});
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 0){
                    q.push({r,c});
                }
            }
        }
        bfs(grid, q);
    }
};
