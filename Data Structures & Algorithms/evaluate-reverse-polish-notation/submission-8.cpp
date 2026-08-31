class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> eval;
        for(auto s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int op2 = eval.top(); eval.pop();
                int op1 = eval.top(); eval.pop();
                if(s == "+"){
                    eval.push(op1 + op2);
                }
                else if(s == "-"){
                    eval.push(op1 - op2);
                }
                else if(s == "*"){
                    eval.push(op1 * op2);
                }
                else if(s == "/"){
                    if(op2 == 0) eval.push(0);
                    else eval.push(op1 / op2);
                }
            }
            else{
                eval.push(stoi(s));
            }
        }
        return eval.top();
    }
};
