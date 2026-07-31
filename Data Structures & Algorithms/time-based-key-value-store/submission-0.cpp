class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> times;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        times[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        vector<pair<string, int>> data = times[key];
        int l = 0;
        int r = data.size() - 1;
        string res = "";
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(data[mid].second == timestamp){
                return data[mid].first;
            }
            else if(data[mid].second > timestamp){
                r = mid - 1;
            }
            else{
                res = data[mid].first;
                l = mid + 1;
            }
        }
        return res;
    }
};
