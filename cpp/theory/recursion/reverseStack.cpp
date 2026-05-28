#include <bits/stdc++.h>
using namespace std;

/**
 * ! Approach 1: Using an auxiliary stack to reverse the original stack
 */
// void reverseStack(stack<int>& st) {
//     if (st.empty()) return;

//     int top = st.top();
//     st.pop();
//     reverseStack(st);

//     stack<int> aux;
//     while (!st.empty()) {
//         aux.push(st.top());
//         st.pop();
//     }

//     st.push(top);
//     while (!aux.empty()) {
//         st.push(aux.top());
//         aux.pop();
//     }
// }

/**
 * ! Approach 2: Using internal memory stack itself with helper function
 */
void insertBottom(stack<int>& st, int& top) {
    if (st.empty()) {
        st.push(top);
        return;
    }

    int curr = st.top();
    st.pop();
    insertBottom(st, top);
    st.push(curr);
}

void reverseStack(stack<int>& st) {
    if (st.empty()) return;

    int top = st.top();
    st.pop();
    reverseStack(st);

    insertBottom(st, top);
}

int main() {
    // Disable standard input and output synchronization
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> st;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    cout << " === Original Stack === \n";
    stack<int> temp = st; // Create a copy of the original stack to print its elements  
    while (!temp.empty()) {
      cout << temp.top() << " ";
      temp.pop();
    }
    cout << "\n";
    
    reverseStack(st);
    
    cout << " === Reversed Stack === \n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}