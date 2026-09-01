class Solution {
public:
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,-1}};
    void bfs(vector<vector<int>> image, int ogColor, int nColor, int sr, int sc){
        image[sr][sc] = ncolor;
        queue<pair<int, int>> q;
        q.push({sr, sc});

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + directions[i][0];
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        bfs(image, image[sr][sc], color, sr, sc);
        return image;
    }
};