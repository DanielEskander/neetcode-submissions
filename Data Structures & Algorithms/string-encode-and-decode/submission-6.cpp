class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.size() < 1) return "";

        string res = "";
        for(const string& s : strs){
            res.append(to_string(s.length()));
            res.append("#");
            res.append(s);
        }
        return res;
    }

    vector<string> decode(string s) {
        if(s == "") return {};

        vector<string> res;
        int i = 0;
        while(i < s.length()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            res.push_back(s.substr(++j, len));
            i = j + len;
        }
        return res;
    }
};
