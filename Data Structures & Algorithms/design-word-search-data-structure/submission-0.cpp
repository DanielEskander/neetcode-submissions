struct TrieNode{
    bool word;
    unordered_map<char, TrieNode*> children;
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c : word){
            if(!cur->children.contains(c)){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    bool dfs(string word, int j, TrieNode* root){
        TrieNode* cur = root;

        for(int i = j; i < word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(auto [ch, child] : cur->children){
                    if(child && dfs(word, i + 1, child)){
                        return true;
                    }
                }
                return false;
            }
            else{
                if(!cur->children.contains(c))
                    return false;
                cur = cur->children[c];
            }
        }
        return cur->word;
    }
};
