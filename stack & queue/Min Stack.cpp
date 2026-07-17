class MinStack {
    stack <int> st, stMin;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty() || value<=stMin.top()){
            stMin.push(value);
        }
        st.push(value);
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        if(st.top()==stMin.top()){
            stMin.pop();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }
        return st.top();
    }
    
    int getMin() {
        if(stMin.empty()){
            return -1;
        }
        return stMin.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */