class MinStack {

public:
    stack<int>st,s;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(st.empty() || val <= st.top()) st.push(val);
    }
    
    void pop() {
        if(s.top() == st.top())st.pop();
        s.pop();
    }
    
    int top() {
        
        return s.empty() ? -1 : s.top();
    }
    
    int getMin() {
        return st.empty() ? -1 : st.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */