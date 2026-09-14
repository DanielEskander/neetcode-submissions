#include <bits/stdc++.h>
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
    vector<vector<bool>> visited;
    int directions[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    vector<string> res;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string& w : words){
            root->addWord(w);
        }

        visited.assign(board.size(), vector<bool>(board[0].size(), false));
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                dfs(board, "", r, c, root);
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& board, string word, int r, int c, TrieNode* node){
        if(r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size() ||
            visited[r][c] || node->children.find(board[r][c]) == node->children.end())
            return;
        
        visited[r][c] = true;
        char cur = board[r][c];
        node = node->children[cur];
        word += cur;
        if(node->isWord){
            res.push_back(word);
            node->isWord = false;
        }

        for(auto& d : directions){
            int nr = r + d[0];
            int nc = c + d[1];
            dfs(board, word, nr, nc, node);
        }

        visited[r][c] = false;
    }
};
