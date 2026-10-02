class MyQueue {
    stack<int> st;
    stack<int> mock;

public:
    MyQueue() {}
    
    void push(int x) {
        // Step 1: Move all elements from st to mock
        while (!st.empty()) {
            mock.push(st.top());
            st.pop();
        }

        // Step 2: Push x into empty st (it goes to the bottom)
        st.push(x);

        // Step 3: Move everything back from mock to st
        while (!mock.empty()) {
            st.push(mock.top());
            mock.pop();
        }
    }
    
    int pop() {
        int val = st.top();
        st.pop();
        return val;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};