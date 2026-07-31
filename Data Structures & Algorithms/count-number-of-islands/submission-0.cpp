class Solution {
public:
    int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == '0') continue;

                bfs(r, c, grid);
                islands++;
            }
        }
        return islands;
    }
    
    void bfs(int row, int col, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        grid[row][col] = '0';
        q.push({row, col});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int r = node.first, c = node.second;
            for(int i = 0; i < 4; i++){
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];
                if(nr >= 0 && nc >= 0 && nr < grid.size() &&
                    nc < grid[0].size() && grid[nr][nc] == '1'){
                        q.push({nr, nc});
                        grid[nr][nc] = '0';
                    }
            }
        }
    }
};
