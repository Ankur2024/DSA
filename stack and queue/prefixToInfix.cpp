#include<bits/stdc++.h>
using namespace std;

string prefixToInfix(string s){
    auto isOperator  = [](char c){
        return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
    };
    stack<string> st;
    for(int i = s.length()- 1;i >= 0;i--){
        char ch = s[i];
        if(isalnum(ch)){
            st.push(string(1, ch));
        }else if(isOperator(ch)){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push("(" + op1 + ch + op2 + ")");
        }
    }
    return st.top();
}


int main() {
  string prefix = "*-A/BC-/AKL";
  cout << "Prefix expression: " << prefix << endl;
  string infix = prefixToInfix(prefix);
  cout << "Infix expression: " << infix << endl; // ((A-(B/C))*((A/K)-L))
  return 0;
}