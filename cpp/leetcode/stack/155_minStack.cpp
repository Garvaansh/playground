#include <bits/stdc++.h>
using namespace std; 

/* * Approaches: 
  * 1. Using a stack of pairs to store both the value and the minimum at each level.
  *    - Time Complexity: O(1) for push, pop, top, and getMin operations.
  *    - Space Complexity: O(n) in the worst case when all elements are pushed onto the stack.
  
      class MinStack {
      public:
          stack<pair<int, int>> st;
      
          MinStack() {
              
          }
          
          void push(int val) {
              int mini = (st.empty() ? INT_MAX : st.top().second);
              st.push( 
                  {val, mini = min(val, mini)}
              );
          }
          
          void pop() {
              st.pop();
          }
          
          int top() {
              return st.top().first;
          }
          
          int getMin() {
              return st.top().second;
          }
      };

  ! 2. Using two stacks: one for the actual values and another for the minimum values.
  !    - Time Complexity: O(1) for push, pop, top, and getMin operations.
  !    - Space Complexity: O(n) in the worst case when all elements are pushed

  ? 3. Using a single stack with a variable to track the minimum.
  ?    Intuition - newVal = 2 * val - minival
  ?    similarly, to get prevVal = 2 * minVal - newVal
  ?    - Time Complexity: O(1) for push, pop, top, and getMin operations.
  ?    - Space Complexity: O(n) in the worst case when all elements are pushed   
*/

class MinStack {
public:
  stack<int> st;
  int miniVal;
  MinStack() {}

  void push(int val) {
    if (st.empty()) {
      st.push(val);
      miniVal = val;
    }
    else {
        if (val > miniVal) {
            st.push(val);
        } else {
            st.push(2 * val - miniVal);
            miniVal = val;
        }
    }
  }

  void pop () {
    if(st.empty()) return;
    if (st.top() < miniVal) miniVal = 2 * miniVal - st.top();
    st.pop();
  }
  
  int top(){
    if(st.empty()) return NULL;
    return (st.top() < miniVal) ? miniVal : st.top();
  }

  int getMin() {
    return miniVal;
  }

};

int main() {
  MinStack st;
  vector<string> results;

  int n;
  cin >> n;
  
/* * Input example:
  ?  8
  ?  MinStack
  ? push -2
  ? push 0
  ? push -3
  ? getMin
  ? pop
  ? top
  ? getMin  
*/
  for (int i = 0; i < n; ++i) {
    string op;
    cin >> op;
    
    if (op == "MinStack") {
      results.push_back("null");
    } else if (op == "push") {
      int x;
      cin >> x;
      st.push(x);
      results.push_back("null");
    } else if (op == "top") {
      results.push_back(to_string(st.top()));
    } else if (op == "pop") {
      st.pop();
      results.push_back("null");
    } else if (op == "getMin") {
      int val = st.getMin();
      results.push_back(to_string(val));
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