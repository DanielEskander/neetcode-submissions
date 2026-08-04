class Solution {
public:
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    queue<pair<int, int>> q;
    int fresh = 0;

    int bfs(vector<vector<int>>& grid){
        int minutes = 0;
        while(!q.empty() && fresh > 0){
            int size = q.size();

            for(int j = 0; j < size; j++){
                auto [r,c] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nr = r + directions[i][0];
                    int nc = c + directions[i][1];
                    if(nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size())
                        continue;
                    
                    if(grid[nr][nc] == 1){
                        fresh--;
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
            minutes++;
        }
        return minutes;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 2){
                    q.push({r, c});
                }
                else if(grid[r][c] == 1){
                    fresh++;
                }
            }
        }
        res = bfs(grid);
        return fresh == 0 ? res : -1;
    }
};
