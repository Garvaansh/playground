#include <bits/stdc++.h>
using namespace std; 

/** Postfix to Prefix Conversion using Stack
 * ? Converts postfix expressions (e.g., AB+) to prefix (e.g., +AB)
 * ! Uses stack to rearrange operands and operators
 */

class Post_pre {
  public:
    //* Main conversion: process postfix, build prefix by rearranging
    string Conv_post_pref(string s) {
      stack<string> st;
      //* Process each char in postfix string
      for(char c : s) {
        //* Operands pushed as single-char strings
        if( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9')) 
          st.push(string(1, c));
        //* Operator: pop two operands, combine as operator + operand2 + operand1
        else {
          string t1 = st.top(); st.pop();
          string t2 = st.top(); st.pop();
          string temp = "";
          temp += c; temp += t2; temp += t1;
          st.push(temp);
        }
      }
      return st.top();
    }
};

int main() {
  Post_pre ob;
  int t;
  cin >> t;
  while(t--) {
      string s;
      cin >> s;
      cout << ob.Conv_post_pref(s) << endl;
  }
    return 0;
}