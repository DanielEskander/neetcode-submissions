class Solution {
public:
    void bfs(vector<vector<char>>& grid, int r, int c){
        int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        
        queue<pair<int, int>> q;
        grid[r][c] = '0';
        q.push({r, c});
        while(!q.empty()){
            auto [cr, cc] = q.front();
            q.pop();
            for(auto& d : directions){
                int nr = cr + d[0];
                int nc = cc + d[1]; 

                if(nr < 0 || nc < 0 ||
                    nr >= grid.size() || nc >= grid[0].size() ||
                    grid[nr][nc] != '1')
                    continue;
                
                grid[nr][nc] = '0';
                q.push({nr, nc});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == '0')
                    continue;
                
                bfs(grid, r, c);
                res++;
            }
        }
        return res;
    }
};
