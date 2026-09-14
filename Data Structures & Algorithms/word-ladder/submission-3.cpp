class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(endWord.empty() || find(wordList.begin(), wordList.end(), endWord) == wordList.end())
            return 0;
        
        unordered_map<string, vector<string>> groups;
        wordList.push_back(beginWord);
        for(string& s : wordList){
            for(int i = 0; i < s.size(); i++){
                string pattern = s.substr(0, i) + "*" + s.substr(i + 1);
                groups[pattern].push_back(s);
            }
        }

        int res = 1;
        unordered_set<string> visited{beginWord};
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                string node = q.front();
                q.pop();

                if(node == endWord)
                    return res;
                for(int j = 0; j < node.size(); j++){
                    string pattern = node.substr(0, j) + "*" + node.substr(j + 1);
                    for(const auto& w : groups[pattern]){
                        if(visited.find(w) == visited.end()){
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
