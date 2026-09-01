class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(int i = 0; i < strs.size(); i++){
            result += strs[i];
            if(i < strs.size() - 1) result += " ";
        }
        return result;
    }

    vector<string> decode(string s) {
        if(s == "") return {""};

        stringstream ss(s);
        vector<string> res;
        while(getline(ss, s, ' ')){
            res.push_back(s);
        }

        return res;
    }
};
