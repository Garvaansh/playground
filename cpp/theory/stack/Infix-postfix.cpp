#include <bits/stdc++.h>
using namespace std; 

/** Infix to Postfix Conversion using Stack
* ? Converts infix expressions (e.g., A+B*C) to postfix (e.g., ABC*+)
* ! Uses stack for operators, outputs operands directly, handles precedence and parentheses
*/

class Inf_to_post {
  public:
  
  //* Returns precedence: ^ highest (3), */ (2), +- (1), others invalid (-1)
  int priority(char c) {
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
  }
  
  //* Main conversion: iterate chars, build postfix string
  string Con_inf_to_post(string s) {
      stack<char> st;
      string ans = "";
      //* Process each char in infix string
      for(char c : s) {
        //* Operands go directly to output
        if( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9'))
            ans += c;
        //* '(' always pushed to stack
        else if(c == '(') st.push(c);
        //* ')' pops until '(' found, discard '('
        else if(c == ')') {
          while(!st.empty() && st.top() != '(') {
            ans += st.top();
            st.pop();
          }
          if(!st.empty()) st.pop();
        }
        //* Operator: pop higher/equal precedence, then push current
        else {
          while(!st.empty() && priority(st.top()) >= priority(c)) {
            ans += st.top();
            st.pop();
          }
          st.push(c);
        }
      }
      //* Pop any remaining operators to output
      while(!st.empty()) {
        ans += st.top();
        st.pop();
      }
      return ans;
    }
};

int main() {
  Inf_to_post ob;
  int t;
  cin >> t;
  while(t--) {
      string s;
      cin >> s;
      cout << ob.Con_inf_to_post(s) << endl;
 
  }


    return 0;
}