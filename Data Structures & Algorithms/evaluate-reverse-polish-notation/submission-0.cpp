class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> math_time;
        int op2, op1;
        for(const string& token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                op2 = stoi(math_time.top());
                math_time.pop();
                op1 = stoi(math_time.top());
                math_time.pop();
                if(token == "+"){
                    math_time.push(to_string(op1 + op2));
                }
                else if(token == "-"){
                    math_time.push(to_string(op1 - op2));
                }
                else if(token == "*"){
                    math_time.push(to_string(op1 * op2));
                }
                else if(token == "/"){
                    if(op2 == 0){
                        math_time.push("0");
                    }
                    else{
                        math_time.push(to_string(op1 / op2));
                    }
                }
            }
            else{
                math_time.push(token);
            }
        }
        return stoi(math_time.top());
    }
};
