#include <bits/stdc++.h>
using namespace std; 

/** Approaches: 
 * ! 3. using Stack.
 * Intuition - Use two stacks to keep track of the order of elements. 
 * steps - 
 *    i. S1 -> S2
 *   ii. Value -> S1
 *  iii. S2 -> S1
 */


// Optimized approach -
class MyQueue {
public:
    stack<int> s1, s2;

    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }

    
    int peek() {
        if(!s2.empty()) return s2.top();
        else while(s1.size()) {
                s2.push(s1.top());
                s1.pop();
        }
        return s2.top();
    }
    
    // bool empty() {
    //     return (s1.empty() && s2.empty());
    // }
};



int main() {
  MyQueue q;
  vector<string> results;

    int n;
  cin >> n;
  
  for (int i = 0; i < n; ++i) {
    string op;
    cin >> op;
    
    if (op == "MyQueue") {
      results.push_back("null");
    } else if (op == "push") {
      int x;
      cin >> x;
      q.push(x);
      results.push_back("null");
    } else if (op == "peek") {
      int val = q.peek();
      results.push_back(to_string(val));
    } else if (op == "pop") {
      q.pop();
      results.push_back("null");
    // } else if (op == "empty") {
      // bool val = q.isEmpty();
      // results.push_back(val ? "true" : "false");
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