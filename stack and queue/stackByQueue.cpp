#include <bits/stdc++.h>
using namespace std;

class stackUsingSingleQueue{
    queue<int> q;
    public:
        stackUsingSingleQueue(){
        }
        void push(int x){
            int s = q.size();
            q.push(x);
            for(int i=0;i<s;i++){
                q.push(q.front());
                q.pop();
            }
        }

        void pop(){
            q.pop();
        }

        int top(){
            return q.front();
        }
        bool empty(){
            if(q.empty())
                return true;
            return false;
        }

        void display() {
        cout << "Display the Stack: ";
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main(){
    stackUsingSingleQueue st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<"Top element is "<<st.top()<<endl;
    st.pop();
    cout<<"Top element is "<<st.top()<<endl;
    st.display();
    return 0;
}