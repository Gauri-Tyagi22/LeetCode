class MinStack {
public:
stack<int>st;
stack<int>min;

    MinStack() {
       
    }
    
    void push(int value) {
       if (min.empty())
    min.push(value);
else
    min.push(std::min(value, min.top()));
        st.push(value);
       

    }
    
    void pop() {
        st.pop();
        min.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
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