class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxF = INT_MIN;
        int countAtMax = 0;
        vector<int> freqs(26);
        for(char& c : tasks){
            freqs[c - 'A']++;
            maxF = max(maxF, freqs[c - 'A']);
        }

        for(int i = 0; i < 26; i++){
            if(freqs[i] == maxF)
                countAtMax++;
        }

        int res = (maxF - 1) * (n + 1) + countAtMax;
        return max(res, static_cast<int>(tasks.size()));
    }
};
