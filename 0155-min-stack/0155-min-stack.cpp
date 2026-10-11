class MinStack {

    stack<int> stk;
    stack<int> minstk;
public:
    MinStack() {
        
    }
    
    void push(int value) {

        if(stk.empty()){
            stk.push(value);
            minstk.push(value);
        }
        else{
            stk.push(value);
        
        minstk.push(min(minstk.top(), value));
        }

        
    }
    
    void pop() {
        stk.pop();
        minstk.pop();
    }
    
    int top() {
        int topele = stk.top();
        return topele;
    }
    
    int getMin() {
        int ele = minstk.top();
        return ele;
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