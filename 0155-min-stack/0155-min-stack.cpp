class MinStack {
    stack<int> stk;
    stack<int> minstk;

public:
    MinStack() {}

    void push(int value) {
        stk.push(value);

        // If minstk is empty, value is the current minimum.
        // Otherwise, push the smaller of value and the current minimum.
        if (minstk.empty()) {
            minstk.push(value);
        } else {
            minstk.push(min(value, minstk.top()));
        }
    }

    void pop() {
        stk.pop();
        minstk.pop(); // Keeps the history log perfectly in sync
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minstk.top();
    }
};