#include <bits/stdc++.h>
using namespace std; 

bool isValid(string s) {
        stack<char> st;
        for(char c : s) {
            if(c == '(' || c == '[' || c == '{') st.push(c);
            else {
                if(st.empty()) return false;
                
                char ch = st.top();
                st.pop();
                if(c == ')' && ch != '(' ||
                    c == ']' && ch != '[' || 
                    c == '}' && ch != '{' ) return false;
            }
        }
        return st.empty();
    }

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        string proc_s = s.substr(1, s.size() - 2);   // to handle the input format "string".
        cout << (isValid(proc_s) ? "true" : "false") << endl;
    }

    return 0;
}