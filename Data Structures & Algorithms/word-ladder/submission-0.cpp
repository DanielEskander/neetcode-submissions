class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(endWord.empty() || find(wordList.begin(), wordList.end(), endWord) == wordList.end()){
            return 0;
        }
        
        unordered_map<string, vector<string>> nei;
        wordList.push_back(beginWord);
        for(auto& word : wordList){
            for(int j = 0; j < word.size(); j++){
                string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                nei[pattern].push_back(word);
            }
        }

        int res = 1;
        unordered_set<string> visited{beginWord};
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string word = q.front(); q.pop();
                if(word == endWord) return res;
                for(int j = 0; j < word.size(); j++){
                    string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                    for(auto& neiWord : nei[pattern]){
                        if(!visited.contains(neiWord)){
                            visited.insert(neiWord);
                            q.push(neiWord);
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }
};
