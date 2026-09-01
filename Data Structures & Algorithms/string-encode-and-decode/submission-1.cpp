class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";

        string res = "";
        for(const string& s : strs){
            res += to_string(s.length());
            res += "#";
            res += s;
        }
        return res;
    }

    vector<string> decode(string s) {
        if(s == "") return {};

        vector<string> res;
        int j = 0;
        int i = 0;
        while(i < s.length()){
            while(s[j] != '#'){
                j++;
            }
            int len = stoi(s.substr(i, j));
            res.push_back(s.substr(j + 1, j + len - 1));
            j += len + 1;
            i = j;
        }
        return res;
    }
};
