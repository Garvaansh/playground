#include <bits/stdc++.h>
#include "../../imports/node.h"
using namespace std; 

//! Stack Implementation techniques
/**  3. Using Linked List
* * Linked list provides dynamic sizing (no fixed capacity like arrays), but O(1) operations are still possible.
* ? Trade-off: More memory per element (for next pointer), but no wasted space or overflow issues.
*/

class Mystack {
  Node<int>* top;  // Pointer to the top node of the stack (LIFO: last in, first out)
  int sz;          // Tracks current size for O(1) size queries (avoids traversing the list)
  
public:
  Mystack() {
    top = nullptr;  // Initialize empty stack
    sz = 0;
  }

  // Push: Add element to top of stack
  // Why: Maintains LIFO by inserting at head (O(1) time, no shifting needed)
  void push(int x) {
    Node<int>* temp = new Node<int>(x, top);  // Create new node with value x, pointing to current top
    top = temp;                               // Update top to new node
    sz++;                                     // Increment size
  }

  // Pop: Remove and return top element
  // Why: LIFO removal from head (O(1), direct access). Handles underflow gracefully.
  int pop() {
    if (top == nullptr) {  // Check for empty stack to prevent crashes
      cout << "Stack underflow\n";
      return -1;  // Sentinel value for error
    }
    Node<int>* temp = top;      // Temp pointer to node being removed
    top = top->next;            // Move top to next node (or nullptr if empty)
    int value = temp->val;      // Extract value before deletion
    delete temp;                // Free memory to avoid leaks
    sz--;                       // Decrement size
    return value;
  }

  // Peek: Return top element without removing
  // Why: Inspect top without modifying stack (useful for checks without pop)
  int peek() {
    if (top == nullptr) {  // Handle empty stack
      cout << "Stack underflow\n";
      return -1;
    }
    return top->val;  // Direct access to top value
  }

  // Size: Return current number of elements
  // Why: O(1) query using counter (faster than traversing list each time)
  int size() {
    return sz;  
  }

  // IsEmpty: Check if stack has no elements
  // Why: Quick boolean check (avoids size() == 0 calls)
  bool isEmpty() {
    return sz == 0;  // Could also check top == nullptr, but size is consistent
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