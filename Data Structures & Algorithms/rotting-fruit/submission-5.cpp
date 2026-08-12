class Solution {
public:
    int bfs(vector<vector<int>>& grid, queue<pair<int,int>>& q, int& fresh){
        int res = 0;
        int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            int size = q.size();
            bool changed = false;
            for(int i = 0; i < size; i++){
                auto [r,c] = q.front();
                q.pop();
                for(auto& d : directions){
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if(nr < 0 || nc < 0 ||
                        nr >= grid.size() || nc >= grid[0].size() ||
                        grid[nr][nc] != 1) continue;
                    
                    changed = true;
                    fresh--;
                    grid[nr][nc] = 2;
                    q.push({nr,nc});
                }
            }
            if(changed) res++;
        }
        return fresh > 0 ? -1 : res;
    }

    int orangesRotting(vector<vector<int>>& grid) {
       queue<pair<int,int>> q;
       int fresh = 0;
       for(int r = 0; r < grid.size(); r++){
            for(int c = 0; c < grid[0].size(); c++){
                if(grid[r][c] == 2){
                    q.push({r,c});
                }
                if(grid[r][c] == 1) fresh++;
            }
       }

       return bfs(grid, q, fresh);
    }
};
