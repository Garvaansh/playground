#include <bits/stdc++.h>
using namespace std; 

/** Prefix to Postfix Conversion using Stack
 * ? Converts prefix expressions (e.g., +AB) to postfix (e.g., AB+)
 * ! Uses stack, processes from right to left, rearranges operands and operators
 */

class Pref_post {
  public:
    //* Main conversion: iterate from right, build postfix by rearranging
    string Conv_pref_post(string s) {
      stack<string> st;
      //* Process chars from right to left
      for(int i = s.size() - 1; i >= 0; i--) {
        char c = s[i];
        //* Operands pushed as single-char strings
        if( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9')) 
          st.push(string(1, c));
        //* Operator: pop two operands, combine as operand1 + operand2 + operator
        else {
          string t1 = st.top(); st.pop();
          string t2 = st.top(); st.pop();
          string temp = "";
          temp += t1; temp += t2; temp += c;
          st.push(temp);
        }
      }
      return st.top();
    }
};

int main() {
  Pref_post ob;
  int t;
  cin >> t;
  while(t--) {
      string s;
      cin >> s;
      cout << ob.Conv_pref_post(s) << endl;
  }
    return 0;
}