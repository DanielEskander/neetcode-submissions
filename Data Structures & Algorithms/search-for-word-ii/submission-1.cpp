class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool isWord;

        TrieNode() : isWord(false) {};

        void addWord(string word){
            TrieNode* curr = this;
            for(auto& c : word){
                if(!curr->children.contains(c))
                    curr->children[c] = new TrieNode();
                curr = curr->children[c];
            }
            curr->isWord = true;
        }
};

class Solution {
public:
    unordered_set<string> res;
    vector<vector<bool>> visit;
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(auto& s : words){
            root->addWord(s);
        }

        visit.assign(board.size(), vector<bool>(board[0].size(), false));
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                dfs(board, r, c, "", root);
            }
        }
        return vector<string>(res.begin(), res.end());
    }

    void dfs(vector<vector<char>>& board, int row, int col, string word, TrieNode* node){
        if(row < 0 || col < 0 ||
            row >= board.size() || col >= board[0].size() ||
            !node->children.contains(board[row][col]) ||
            visit[row][col])
            return;
        
        visit[row][col] = true;
        node = node->children[board[row][col]];
        word += board[row][col];
        if(node->isWord){
            res.insert(word);
        }
        
        for(auto& d : directions){
            int nr = row + d[0];
            int nc = col + d[1];
            dfs(board, nr, nc, word, node);
        }
        visit[row][col] = false;
    }
};
