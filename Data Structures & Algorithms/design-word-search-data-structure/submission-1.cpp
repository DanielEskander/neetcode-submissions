struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool isWord;
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(auto& c : word){
            if(!cur->children.contains(c)){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string word, int idx, TrieNode* root){
        TrieNode* cur = root;
        for(int i = idx; i < word.size(); i++){
            if(word[i] == '.'){
                for(auto [key, child] : cur->children){
                    if(child && dfs(word, i + 1, child)){
                        return true;
                    }
                }
                return false;
            }
            else{
                if(!cur->children.contains(word[i])){
                    return false;
                }
                cur = cur->children[word[i]];
            }
        }
        return cur->isWord;
    }
};
