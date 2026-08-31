class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> times;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        times[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>>& data = times[key];
        int l = 0;
        int r = data.size() - 1;
        string res = "";
        while(l <= r){
            int m = l + (r - l) / 2;
            if(data[m].second == timestamp){
                return data[m].first;
            }
            else if(data[m].second < timestamp){
                res = data[m].first;
                l = m + 1;
            }
            else{
                r = m - 1;
            }
        }
        return res;
    }
};
