#include<bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};


struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    void display();
    MyQueue() {front = rear = NULL;}
};

void MyQueue :: push(int x)
{
    QueueNode *temp = new QueueNode(x);
    if(front == nullptr){
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

int MyQueue :: pop()
{
    if(front == nullptr){
        cout << "Queue is empty!" << endl;
        return -1;
    }
    int x = front -> data;
    QueueNode *t = front;
    front = front -> next;
    delete t;
    return x;
}

void MyQueue :: display(){
    QueueNode *temp = front;
    while(temp!= NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    MyQueue queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);

    queue.display();

    cout << "Popped element: " << queue.pop() << endl;

    queue.display();

    cout << "Popped element: " << queue.pop() << endl;

    queue.display();

    queue.pop();
    queue.pop();  
    queue.pop();  

    return 0;
}