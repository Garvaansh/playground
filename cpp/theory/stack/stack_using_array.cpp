#include <bits/stdc++.h>
using namespace std; 

//! Stack Implementation techniques
//? 1. Using STL
// stack<int> st; 

/* ----------------------------------------------------------------------------------------- */
//? 2. Using Arrays
//* stacks are generally static spaced, so it needs to be initialized with a constant space
class Mystack {
  int st[10];
  int top;

  public:
  Mystack(){
    top = -1;
  }

  void push(int x) {
    if(top == 9) {
      cout << "Stack overflow\n";
      return;
    }
    st[++top] = x;
  }

  int pop() {
    if(top == -1) {
      cout << "Stack underflow\n";
      return -1;
    }
    return st[top--];
  }

  int peek() {
    if(top == -1) {
      cout << "Stack underflow\n";
      return -1;
    }
    return st[top];
  }

  int size() {
    return top + 1;
  }

  bool isEmpty() {
    return top == -1;
  }
  
};

int main() {
  Mystack st;
  vector<string> results;
  
  int n;
  cin >> n;
  
  for (int i = 0; i < n; ++i) {
    string op;
    cin >> op;
    
    if (op == "MyStack") {
      results.push_back("null");
    } else if (op == "push") {
      int x;
      cin >> x;
      st.push(x);
      results.push_back("null");
    } else if (op == "top") {
      int val = st.peek();
      results.push_back(to_string(val));
    } else if (op == "pop") {
      int val = st.pop();
      results.push_back(to_string(val));
    } else if (op == "empty") {
      bool val = st.isEmpty();
      results.push_back(val ? "true" : "false");
    }
  }
  
  // Print the results in the required format
  cout << "[";
  for (size_t i = 0; i < results.size(); ++i) {
    cout << results[i];
    if (i < results.size() - 1) cout << ", ";
  }
  cout << "]" << endl;
  
  return 0;
}