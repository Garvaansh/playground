#include <bits/stdc++.h>
using namespace std; 

// ! Stack Implementation techniques
/** 
 * ? Using Queues 
 * * Queues are FIFO, but we can simulate LIFO by rotating after each push to keep the latest element at front.
 * ! Trade-off: Push is O(n) (due to rotation), pop/peek are O(1). Use only when queues are required.
 */

class Mystack {
public:
    queue<int> q;  // Single queue to hold elements; front will always be the stack top after rotation

    Mystack() {}  // Default constructor, queue starts empty

    // Push: Add to back, then rotate so new element becomes front (simulates stack top)
    // Why: Queues don't support direct head insertion, so rotate to maintain LIFO illusion
    void push(int x) {
        int s = q.size();  // Current size before adding new element
        q.push(x);         // Add new element to back

        // Rotate: Move front elements to back, making new element the new front
        for(int i = 0; i < s; i++) {
            q.push(q.front());  // Move front to back
            q.pop();            // Remove old front
        }
    }

    // Pop: Remove and return front (which is stack top due to rotation)
    // Why: Direct O(1) access since front is always the latest pushed element
    int pop() {
        int val = q.front();  // Get top value
        q.pop();              // Remove it
        return val;
    }

    // Peek: Return front without removing
    // Why: Inspect top without modifying queue (same as pop but no removal)
    int peek() {
        return q.front();  // Front is always the stack top
    }

    // IsEmpty: Check if queue is empty
    // Why: Direct delegation to queue's empty check (no custom logic needed)
    bool isEmpty() {
        return q.empty();
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