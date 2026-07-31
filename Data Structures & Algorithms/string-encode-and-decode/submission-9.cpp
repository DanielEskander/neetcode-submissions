class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string s : strs){
            res += to_string(s.size());
            res += "#";
            res += s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            j++;
            res.push_back(s.substr(j,length));
            i = j + length;
        }
        return res;
    }
};
