#include <bits/stdc++.h>
using namespace std; 

/** Postfix to Infix Conversion using Stack
 * ? Converts postfix expressions (e.g., AB+) to infix (e.g., (A+B))
 * ! Uses stack to build infix with parentheses for correct grouping
 */

class Post_Inf {
  public:
    //* Wraps string in parentheses for operator grouping
    string wrapper(string s){
      return '(' + s + ')';
    }

    //* Main conversion: process postfix, combine operands with operators
    string Conv_post_inf(string s) {
      stack<string> st;
      string ans = "";
      //* Process each char in postfix string
      for(char c : s) {
        //* Operands pushed as single-char strings
        if( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9')) 
          st.push(string(1, c));
        //* Operator: pop two operands, combine with operator, wrap in parens
        else {
          string t1 = st.top(); st.pop();
          string t2 = st.top(); st.pop();
          string temp = "";
          temp += t2; temp += c; temp += t1;
          st.push(wrapper(temp));
          }
        }
        return st.top();
      }
};

int main() {
  Post_Inf ob;
  int t;
  cin >> t;
  while(t--) {
      string s;
      cin >> s;
      cout << ob.Conv_post_inf(s) << endl;
  }
    return 0;
}