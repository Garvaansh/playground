#include <bits/stdc++.h>
using namespace std; 

/** Prefix to Infix Conversion using Stack
 * ? Converts prefix expressions (e.g., +AB) to infix (e.g., (A+B))
 * ! Uses stack, processes from right to left, builds infix with parentheses
 */

class Pre_Inf {
  public:
    //* Wraps string in parentheses for operator grouping
    string wrapper(string s){
      return '(' + s + ')';
    }

    //* Main conversion: iterate from right, combine operands with operators
    string Conv_pref_inf(string s) {
      stack<string> st;
      //* Process chars from right to left
      for(int i = s.size() - 1; i >= 0; i--) {
        char c = s[i];
        //* Operands pushed as single-char strings
        if( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9')) 
          st.push(string(1, c));
        //* Operator: pop two operands, combine with operator, wrap in parens
        else {
          string t1 = st.top(); st.pop();
          string t2 = st.top(); st.pop();
          string temp = "";
          temp += t1; temp += c; temp += t2;
          st.push(wrapper(temp));
        }
      }
      return st.top();
    }
};

int main() {
  Pre_Inf ob;
  int t;
  cin >> t;
  while(t--) {
      string s;
      cin >> s;
      cout << ob.Conv_pref_inf(s) << endl;
  }
    return 0;
}