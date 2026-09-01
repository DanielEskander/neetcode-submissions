class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> goalCounts;
        unordered_map<char, int> currCounts;

        for(auto& c : t){
            goalCounts[c]++;
        }

        int i = 0, j = 0;
        int have = 0;
        int goal = goalCounts.size();
        string res = "";
        while(j < s.size()){
            currCounts[s[j]]++;

            if(goalCounts.contains(s[j]) &&
                currCounts[s[j]] == goalCounts[s[j]]) have++;
            
            while(have == goal){
                if(res.empty() || res.size() > j - i + 1){
                    res = s.substr(i, j - i + 1);
                }

                currCounts[s[i]]--;
                if(goalCounts.contains(s[i]) &&
                    currCounts[s[i]] < goalCounts[s[i]]) have--;
                i++;
            }
            j++;
        }
        return res;
    }
};
