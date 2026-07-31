class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";

        string encStr = "";
        for(const string& s : strs){
            encStr.append(to_string(s.length()));
            encStr.append("#");
            encStr.append(s);
        }
        return encStr;
    }

    vector<string> decode(string s) {
        if(s.length() == 0) return {};

        vector<string> deStr;
        int i = 0;
        while(i < s.length()){
            int j = i;
            while(s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i + 1));
            j++;
            deStr.push_back(s.substr(j, len));
            i = j + len;
        }
        return deStr;
    }
};
