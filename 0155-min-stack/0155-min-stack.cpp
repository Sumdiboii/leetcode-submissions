class MinStack {
public:
    stack<int> stk;
    MinStack() {

    }

    void push(int val) {
        stk.push(val);
    }

    void pop() {
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        stack<int> tmp;
        int mini = stk.top();
        while (stk.size()) {
            mini = min(mini, stk.top());
            tmp.push(stk.top());
            stk.pop();
        }

        while (tmp.size()) {
            stk.push(tmp.top());
            tmp.pop();
        }

        return mini;
    }
};