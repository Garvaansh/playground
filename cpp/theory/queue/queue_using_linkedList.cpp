#include <bits/stdc++.h>
#include "../../imports/node.h"
using namespace std; 

/** Approaches: 
 * ! 3. using Linked List.
 */

class MyQueue {
public:
  Node<int>* front;
  Node<int>* end;
  int size = 0;

  MyQueue() {
    front = nullptr;
    end = nullptr;  // Initialize empty queue
  }  

  void push(int x) {
    Node<int>* temp = new Node(x);
    if(front == NULL) {
      front = temp;
      end = temp;
    }
    else
    {
      end->next = temp;
      end = temp;
      size++;
    }
  }

  void pop() {
    if(front == NULL) return;
    Node<int>* temp = front;
    front = front->next;
    delete temp;
    size--;
  }

  int peek() {
    if(front == NULL) return -1;  // Handle empty queue case
    return front->val;                        
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