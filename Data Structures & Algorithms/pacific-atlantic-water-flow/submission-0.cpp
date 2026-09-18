class Solution {
public:
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c){
        visited[r][c] = true;

        for(auto& d : directions){
            int nr = r + d[0];
            int nc = c + d[1];

            if(nr < 0 || nr >= heights.size() ||
                nc < 0 || nc >= heights[0].size() ||
                visited[nr][nc])
                continue;
            if(heights[nr][nc] < heights[r][c])
                continue;
            
            visited[nr][nc] = true;
            dfs(heights, visited, nr, nc);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for(int r = 0; r < rows; r++){
            dfs(heights, pacific, r, 0);
        }

        for(int c = 0; c < cols; c++){
            dfs(heights, pacific, 0, c);
        }

        for(int r = 0; r < rows; r++){
            dfs(heights, atlantic, r, cols - 1);
        }

        for(int c = 0; c < cols; c++){
            dfs(heights, atlantic, rows - 1, c);
        }

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(pacific[r][c] && atlantic[r][c])
                    res.push_back({r,c});
            }
        }
        return res;
    }
};
