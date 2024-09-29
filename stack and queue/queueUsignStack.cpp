#include <bits/stdc++.h>
using namespace std;

class QueueUsingStack{
    stack<int> st1, st2;

    // Transfer all elements from st1 to st2
    void transferStack1toStack2() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
    }

public:
    // Push element into the queue
    void push(int x){
        st1.push(x);
    }

    // Pop element from the queue
    void pop(){
        // If both stacks are empty, there is no element to pop
        if(st1.empty() && st2.empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        // If st2 is empty, move elements from st1 to st2
        if(st2.empty()) {
            transferStack1toStack2();
        }
        // Pop from st2 which holds the front of the queue
        st2.pop();
    }

    // Display the elements in the queue
    void display(){
        // Transfer elements to st2 to maintain queue order
        if(st2.empty()) {
            transferStack1toStack2();
        }

        // Print the elements in st2 which holds the queue in correct order
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
