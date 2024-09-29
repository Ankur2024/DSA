#include <bits/stdc++.h>
using namespace std;

class QueueUsingStack{
    stack<int> st1, st2;

    void transferStack1toStack2() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
    }

public:
    void push(int x){
        st1.push(x);
    }

    void pop(){
        if(st1.empty() && st2.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        if(st2.empty()) {
            transferStack1toStack2();
        }
        st2.pop();
    }

    void display(){
        if(st2.empty()) {
            transferStack1toStack2();
        }

        stack<int> temp = st2;
        cout << "Queue elements are: ";
        while(!temp.empty()){
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main(){
    QueueUsingStack qu;
    qu.push(1);
    qu.push(2);
    qu.push(3);
    qu.display();
    qu.pop();
    qu.display();

    return 0;
}
