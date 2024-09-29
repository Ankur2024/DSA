#include <bits/stdc++.h>
using namespace std;

class stackUsingTwoQueue
{
    queue<int> q1, q2;

public:
    stackUsingTwoQueue()
    {
    }
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        q2.swap(q1);
    }
    
    void pop() {
        if(q1.empty())
            return;
        q1.pop();
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty())
            return true;
        return false;
    }
    void display() {
        cout << "Display the Stack: ";
        queue<int> temp = q1;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main()
{
    stackUsingTwoQueue st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "Top element is " << st.top() << endl;
    st.pop();
    cout << "Top element is " << st.top() << endl;
    st.display();
    return 0;
}