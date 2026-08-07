class Solution {
public:
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    void bfs(vector<vector<int>>& image, int ogColor, int nColor, int sr, int sc){
        image[sr][sc] = nColor;
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + directions[i][0];
                int nc = c + directions[i][1];
                if(nr < 0 || nc < 0 || nr >= image.size() || nc >= image[0].size())
                    continue;
                
                if(image[nr][nc] != ogColor)
                    continue;
                
                image[nr][nc] = nColor;
                q.push({nr,nc});
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color)
            bfs(image, image[sr][sc], color, sr, sc);
        return image;
    }
};