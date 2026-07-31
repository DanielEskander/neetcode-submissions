class MinStack {
public:
    stack<int> reg;
    stack<int> minS;
    MinStack() {
        
    }
    
    void push(int val) {
        reg.push(val);
        if(minS.empty()) minS.push(val);
        else minS.push(min(minS.top(), val));
    }
    
    void pop() {
        reg.pop();
        minS.pop();
    }
    
    int top() {
        return reg.top();
    }
    
    int getMin() {
        return minS.top();
    }
};
