class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(endWord.empty() || find(wordList.begin(), wordList.end(), endWord) == wordList.end()){
            return 0;
        }

        unordered_map<string, vector<string>> mappings;
        wordList.push_back(beginWord);
        for(auto& w : wordList){
            for(int i = 0; i < w.size(); i++){
                string pattern = w.substr(0, i) + "*" + w.substr(i + 1);
                mappings[pattern].push_back(w);
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
                if(cur == endWord) return res;

                for(int i = 0; i < cur.size(); i++){
                    string pattern = cur.substr(0, i) + "*" + cur.substr(i+1);
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
