class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> values;
        int res = 0;
        for(const string& op : operations){
            if(op == "C") values.pop();
            else if(op == "D") values.push(values.top()*2);
            else if(op == "+"){
                int temp1 = values.top();
                values.pop();
                int temp2 = values.top();
                values.push(temp1);
                values.push(temp1 + temp2);
            }
            else{
                values.push(stoi(op));
            }
        }

        while(!values.empty()){
            res += values.top(); values.pop();
        }
        return res;
    }
};