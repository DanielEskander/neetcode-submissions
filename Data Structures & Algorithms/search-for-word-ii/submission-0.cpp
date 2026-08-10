class TrieNode {
public:
    bool isWord;
    unordered_map<char, TrieNode*> children;

    TrieNode() : isWord(false) {};

    void addWord(string word){
        TrieNode* cur = this;
        for(char c : word){
            if(!cur->children.contains(c))
                cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
};

class Solution {
    unordered_set<string> res;
    vector<vector<bool>> visit;
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string s : words){
            root->addWord(s);
        }

        visit.assign(board.size(), vector<bool>(board[0].size(), false));
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                dfs(board, r, c, root, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }   

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, string word){
        int rows = board.size();
        int cols = board[0].size();
        if(r < 0 || c < 0 ||
            r >= rows || c >= cols ||
            !node->children.contains(board[r][c]) ||
            visit[r][c]){
            return;
        }

        visit[r][c] = true;
        node = node->children[board[r][c]];
        word += board[r][c];
        if(node->isWord){
            res.insert(word);
        }

        for(int i = 0; i < 4; i++){
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];
            dfs(board, nr, nc, node, word);
        }
        visit[r][c] = false;
    }
};
