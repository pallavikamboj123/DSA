class MinStack {
public:
    stack<pair<int, int>> st;
    int m = INT_MAX;
    MinStack() {

    }

    void push(int val) {
        m = min(val, m);

        st.push(make_pair(val, m));
    }

    void pop() {
        st.pop();

        if(!st.empty()) m = st.top().second;
        else m = INT_MAX;

    }

    int top() {
        if(!st.empty()) return st.top().first;

        return st.top().first;
    }

    int getMin() {
        return st.top().second;
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