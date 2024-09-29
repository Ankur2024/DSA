#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;

    StackNode(int a) {
        data = a;
        next = NULL;
    }
};

class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        StackNode *temp  = new StackNode(x);
        if(top == nullptr){
            top = temp;
            return;
        }
        temp -> next = top;
        top = temp;
    }

    int pop() {
        if(top == nullptr)  
            return -1;
        int x = top -> data;
        StackNode *temp = top;
        top = top -> next;
        delete temp;
        return x;
    }
     void display() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        StackNode *temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    MyStack() { top = NULL; }
};


int main(){
 MyStack stack;

    // Push elements to the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Popped element: " << stack.pop() << endl;

    stack.display();

    return 0;
}