#include<bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c == '^'){
        return 3;
    }
    if(c == '*' || c == '/'){
        return 2;
    }
    else if(c == '+' || c == '-'){
        return 1;
    }
    return -1;
}

void infixToPostfix(string s){
    stack<char> st;
    string res;
    for(int i=0; i<s.length(); i++){
        if(isalnum(s[i])){
            res += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top()!= '('){
                res += st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(s[i]) <= prec(st.top())){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
  cout << "Prefix expression: " << res << endl;
}

int main() {
  string exp = "(p+q)*(m-n)";
  cout << "Infix expression: " << exp << endl;
  infixToPostfix(exp);
  return 0;
}