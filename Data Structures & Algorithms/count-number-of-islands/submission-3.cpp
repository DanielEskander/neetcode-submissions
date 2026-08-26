class Solution {
public:
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>& grid, int row, int col){
        queue<pair<int,int>> q;
        q.push({row, col});
        grid[row][col] = '0';
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(auto d : directions){
                int nr = d[0] + r;
                int nc = d[1] + c;

                if(nr < 0 || nc < 0 || nr >= grid.size() || nc >= grid[0].size() ||
                    grid[nr][nc] != '1') continue;
                
                q.push({nr,nc});
                grid[nr][nc] = '0';
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == '1'){
                    res++;
                    dfs(grid, r, c);
                }
            }
        }
        return res;
    }
};
