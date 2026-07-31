class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for(const string& data : details){
            if(stoi(data.substr(data.size() - 4, 2)) > 60) res++;
        }
        return res;
    }
};