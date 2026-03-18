#include <bits/stdc++.h>
using namespace std; 

/** Infix to Prefix conversion using Stack
 * ? Converts infix expressions (e.g., A+B*C) to prefix (e.g., +A*BC)
 * ! Uses stack for operators, reverses input, swaps parentheses, handles precedence
 */

class Inf_pre{
  public:
  //* Returns precedence: ^ highest (3), */ (2), +- (1), others invalid (-1)
  int priority(char c) {
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return -1;
  }
  
  //* Swaps '(' and ')' in string for prefix conversion
  void swap_parenthesis(string& s){
    for(char& c : s) {
        if(c == '(') c = ')';
        else if(c == ')') c = '(';
    }
  }

  //* Main conversion: reverse input, swap parens, process like postfix, reverse output
  string Conv_inf_pref(string s) {
    stack<char> st;
    string ans = "";
    reverse(s.begin(), s.end());
    swap_parenthesis(s);

    //* Process each char in reversed/swapped string
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
        //* Operator: handle right-associativity for ^, left for others
        else {
          if(c == '^') {
            while(!st.empty() && priority(st.top()) >= priority(c)) {
              ans += st.top();
              st.pop();
            }
          }
          else {
            while(!st.empty() && priority(st.top()) > priority(c)) {
              ans += st.top();
              st.pop();
            }
          }
          st.push(c);
        }
    }
    //* Pop any remaining operators to output
    while(!st.empty()) {
      ans += st.top();
      st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main() {
  Inf_pre ob;
  int t;
  cin >> t;
  while(t--) {
      string s;
      cin >> s;
      cout << ob.Conv_inf_pref(s) << endl;
  }
    return 0;
}