struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool isWord;
};
class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char& c : word){
            if(cur->children.find(c) == cur->children.end()){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }

    bool dfs(TrieNode* root, string& word, int idx){
        TrieNode* cur = root;
        for(int i = idx; i < word.size(); i++){
            if(word[i] == '.'){
                for(auto [key, child] : cur->children){
                    if(child && dfs(child, word, i + 1)){
                        return true;
                    }
                }
                return false;
            }
            else{
                if(cur->children.find(word[i]) == cur->children.end()){
                    return false;
                }
                cur = cur->children[word[i]];
            }
        }
        return cur->isWord;
    }
};
