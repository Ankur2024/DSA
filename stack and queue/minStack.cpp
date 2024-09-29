#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;  
    stack<int> minStack;  

public:
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (mainStack.empty()) return;

        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }

        mainStack.pop();
    }

    int top() {
        if (!mainStack.empty()) {
            return mainStack.top();
        }
        return -1;
    }

    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        return -1;
    }
};

int main() {
    MinStack s;
    s.push(10);
    s.push(5);
    s.push(15);
    s.push(3);

    cout << "Minimum element: " << s.getMin() << endl;  

    s.pop();
    cout << "Minimum element after popping: " << s.getMin() << endl;  

    s.pop();
    cout << "Minimum element after another pop: " << s.getMin() << endl;  // Output: 

    return 0;
}
