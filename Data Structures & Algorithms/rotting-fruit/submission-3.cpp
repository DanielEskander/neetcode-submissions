class Solution {
public:
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int bfs(int row, int col, vector<vector<int>>& grid){
        int time = 0;
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()){
            int size = q.size();
            bool changed = false;

            for(int j = 0; j < size; j++){
                auto [r,c] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nr = r + directions[i][0];
                    int nc = c + directions[i][1];
                    if(nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size())
                        continue;
                    
                    if(grid[nr][nc] == 1){
                        changed = true;
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
            
            if(changed) time++;
        }
        return time;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 2){
                    res += bfs(r, c, grid);
                }
            }
        }

        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 1){
                    return -1;
                }
            }
        }
        return res;
    }
};
