class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        bool isWord;

        TrieNode() : isWord(false) {};

        void addWord(string word){
            TrieNode* cur = this;
            for(char& c : word){
                if(cur->children.find(c) == cur->children.end()){
                    cur->children[c] = new TrieNode();
                }
                cur = cur->children[c];
            }
            cur->isWord = true;
        }
};
class Solution {
public:
    unordered_set<string> res;
    vector<vector<bool>> visited;
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string& s : words){
            root->addWord(s);
        }

        visited.assign(board.size(), vector<bool>(board[0].size(), false));
        for(int r = 0; r < (int)board.size(); r++){
            for(int c = 0; c < (int)board[0].size(); c++){
                dfs(board, "", r, c, root);
            }
        }
        return vector<string>(res.begin(), res.end());
    }

    void dfs(vector<vector<char>>& board, string word, int r, int c, TrieNode* root){
        if(r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size() ||
            visited[r][c] || root->children.find(board[r][c]) == root->children.end())
            return;
        
        visited[r][c] = true;
        root = root->children[board[r][c]];
        word += board[r][c];
        if(root->isWord){
            res.insert(word);
        }

        for(auto& d : directions){
            int nr = r + d[0];
            int nc = c + d[1];
            dfs(board, word, nr, nc, root);
        }
        visited[r][c] = false;
    }
};
