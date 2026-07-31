class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> res;
        unordered_set<string> ops = {"+", "-", "*", "/"};
        for(string token : tokens){
            if(ops.contains(token)){
                int op2 = res.top(); res.pop();
                int op1 = res.top(); res.pop();
                if(token == "+"){
                    op1 += op2;
                }
                else if(token == "-"){
                    op1 -= op2;
                }
                else if(token == "*"){
                    op1 *= op2;
                }
                else{
                    if(op2 == 0) op1 = 0;
                    else op1 = (int)((double)op1 / op2);
                }
                res.push(op1);
            }
            else{
                res.push(stoi(token));
            }
        }
        return res.top();
    }
};
