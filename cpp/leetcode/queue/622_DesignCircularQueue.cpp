#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
 public:
  vector<int> queue;
  int front = 0, rear = -1, size = 0, capacity = 0;

  /**
   * Constructor: Initializes the circular queue with a fixed capacity.
   * Intuition: Allocate space for the queue and set initial pointers.
   * TC: O(k) for resizing the vector.
   * SC: O(k) for storing the elements.
   */
  MyCircularQueue(int k) : capacity(k) { queue.resize(capacity); }

  /**
   * enQueue: Adds an element to the rear of the queue.
   * Intuition: Increment the rear pointer in a circular manner and insert the value.
   * TC: O(1) as insertion is done in constant time.
   * SC: O(1) as no additional space is used.
   */
  bool enQueue(int value) {
    if (size == capacity) return false;

    rear = (rear + 1) % capacity;
    queue[rear] = value;
    size++;
    return true;
  }

  /**
   * deQueue: Removes an element from the front of the queue.
   * Intuition: Increment the front pointer in a circular manner and reduce the size.
   * TC: O(1) as removal is done in constant time.
   * SC: O(1) as no additional space is used.
   */
  bool deQueue() {
    if (size == 0) return false;

    front = (front + 1) % capacity;
    size--;
    return true;
  }

  /**
   * Front: Retrieves the front element of the queue.
   * Intuition: Return the value at the front pointer if the queue is not empty.
   * TC: O(1) as retrieval is done in constant time.
   * SC: O(1) as no additional space is used.
   */
  int Front() {
    if (size == 0) return -1;
    return queue[front];
  }

  /**
   * Rear: Retrieves the rear element of the queue.
   * Intuition: Return the value at the rear pointer if the queue is not empty.
   * TC: O(1) as retrieval is done in constant time.
   * SC: O(1) as no additional space is used.
   */
  int Rear() {
    if (size == 0) return -1;
    return queue[rear];
  }

  /**
   * isEmpty: Checks if the queue is empty.
   * Intuition: Compare the size with zero.
   * TC: O(1) as the check is done in constant time.
   * SC: O(1) as no additional space is used.
   */
  bool isEmpty() { return size == 0; }

  /**
   * isFull: Checks if the queue is full.
   * Intuition: Compare the size with the capacity.
   * TC: O(1) as the check is done in constant time.
   * SC: O(1) as no additional space is used.
   */
  bool isFull() { return size == capacity; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main() {
  // Disable standard input and output synchronization for faster I/O
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string command;
  vector<string> commands;
  vector<vector<int>> arguments;
  vector<string> results;

  MyCircularQueue* obj = nullptr;  // Define and initialize the object pointer

  // Read input
  while (cin >> command) {
    if (command == "MyCircularQueue") {
      int k;
      cin >> k;
      obj = new MyCircularQueue(k);  // Initialize the object
      results.push_back("null");
      commands.push_back(command);
      arguments.push_back({k});
    } else if (command == "enQueue") {
      int value;
      cin >> value;
      bool result = obj->enQueue(value);
      results.push_back(result ? "true" : "false");
      commands.push_back(command);
      arguments.push_back({value});
    } else if (command == "deQueue") {
      bool result = obj->deQueue();
      results.push_back(result ? "true" : "false");
      commands.push_back(command);
      arguments.push_back({});
    } else if (command == "Front") {
      int result = obj->Front();
      results.push_back(to_string(result));
      commands.push_back(command);
      arguments.push_back({});
    } else if (command == "Rear") {
      int result = obj->Rear();
      results.push_back(to_string(result));
      commands.push_back(command);
      arguments.push_back({});
    } else if (command == "isEmpty") {
      bool result = obj->isEmpty();
      results.push_back(result ? "true" : "false");
      commands.push_back(command);
      arguments.push_back({});
    } else if (command == "isFull") {
      bool result = obj->isFull();
      results.push_back(result ? "true" : "false");
      commands.push_back(command);
      arguments.push_back({});
    }
  }

  // Print output
  cout << "[";
  for (size_t i = 0; i < results.size(); i++) {
    cout << results[i];
    if (i != results.size() - 1) cout << ", ";
  }
  cout << "]\n";

  delete obj;  // Clean up dynamically allocated memory

  return 0;
}