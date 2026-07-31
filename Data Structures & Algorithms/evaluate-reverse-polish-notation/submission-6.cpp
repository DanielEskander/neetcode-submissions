class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> tracker;
        for(const string& t : tokens){
            if(t == "+" || t == "-" || t == "*" || t == "/"){
                int op2 = tracker.top(); tracker.pop();
                int op1 = tracker.top(); tracker.pop();
                if(t == "+"){
                    tracker.push(op1 + op2);
                }
                else if(t == "-"){
                    tracker.push(op1 - op2);
                }
                else if(t == "*"){
                    tracker.push(op1 * op2);
                }
                else{
                    if(op2 == 0) tracker.push(0);
                    else tracker.push(op1 / op2);
                }
            }
            else tracker.push(stoi(t));
        }
        return tracker.top();
    }
};
