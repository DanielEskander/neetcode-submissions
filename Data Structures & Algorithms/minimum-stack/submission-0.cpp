class MinStack {
public:
    stack<int> s;
    stack<int> minStack;
    MinStack() {
        s = {};
    }
    
    void push(int val) {
        s.push(val);
        minStack.push(min(val, minStack.empty() ? val : minStack.top()));
    }
    
    void pop() {
        s.pop();
        minStack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
