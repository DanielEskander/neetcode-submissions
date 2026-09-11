class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(endWord.empty() ||
            find(wordList.begin(), wordList.end(), endWord) == wordList.end()){
            return 0;
        }
        
        unordered_map<string, vector<string>> mappings;
        wordList.push_back(beginWord);
        for(string& s : wordList){
            for(int i = 0; i < (int)s.size(); i++){
                string pattern = s.substr(0, i) + "*" + s.substr(i+1);
                mappings[pattern].push_back(s);
            }
        }

        int res = 1;
        unordered_set<string> visited{beginWord};
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string cur = q.front();
                q.pop();
                if(cur == endWord)
                    return res;

                for(int j = 0; j < (int)cur.size(); j++){
                    string pattern = cur.substr(0, j) + "*" + cur.substr(j+1);
                    for(auto& w : mappings[pattern]){
                        if(!visited.contains(w)){
                            visited.insert(w);
                            q.push(w);
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }
};
