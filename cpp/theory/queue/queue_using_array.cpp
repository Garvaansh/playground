#include <bits/stdc++.h>
using namespace std; 

/** Approaches: 
 * ! 1. using STL. 
 * * queue<int> q;
 * 
 * ! 2. using arrays.
 */

class MyQueue {
public:
  vector<int> q;
  int front = -1, end = -1;

  MyQueue() : q(10) {}  

  void push(int x) {
    if (end + 1 == q.size()) return;
    if (front == -1) front = 0;
    q[++end] = x;
  }

  void pop() {
      if (front == -1 || front > end) return;  
      front++;                                  
      if (front > end) { front = -1; end = -1; }  
  }

  int peek() {
      if (front == -1 || front > end) return -1;  
      return q[front];                             
  }

  /* int size() {
      return curr_size;
  }
  */
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