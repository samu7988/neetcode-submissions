/* 
    Use TWO stacks:
  1. Main stack  → stores all values normally
  2. Min stack   → tracks minimum at every level

    Every time we push, we also push the current minimum onto the min stack. So at any point, minStack.top() = minimum of entire stack.
*/
class MinStack {
private:
    stack<int> st;       // main stack
    stack<int> minSt;    // tracks minimum at each level

public:
    MinStack() {}

    void push(int val) {
        st.push(val);

        // push min: either val itself or current min (whichever is smaller)
        if (minSt.empty())
            minSt.push(val);
        else
            minSt.push(min(val, minSt.top()));
    }

    void pop() {
        st.pop();
        minSt.pop();      // both stacks stay in sync
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();   // always holds current minimum
    }
};