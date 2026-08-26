class Solution {
public:
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int bfs(vector<vector<int>>& grid, queue<pair<int, int>>& q, int& fresh){
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            int curFresh = fresh;
            for(int i = 0; i < size; i++){
                auto [r, c] = q.front();
                q.pop();
                for(auto d : directions){
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr < 0 || nc < 0 ||
                        nr >= grid.size() || nc >= grid[0].size() ||
                        grid[nr][nc] != 1) continue;
                    
                    grid[nr][nc] = 2;
                    q.push({nr,nc});
                    fresh--;
                }
            }
            if(curFresh != fresh){
                res++;
            }
        }
        return res;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        int res = 0;
        queue<pair<int, int>> q;
        for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 2){
                    q.push({r, c});
                }
                if(grid[r][c] == 1){
                    fresh++;
                }
            }
        }
        res = bfs(grid, q, fresh);
        return fresh > 0 ? -1 : res;
    }
};
