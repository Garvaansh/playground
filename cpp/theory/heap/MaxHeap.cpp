#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
 public:
  int capacity, size;
  vector<int> heap;

  MaxHeap(int capacity) : capacity(capacity) {
    this->size = 0;
    this->heap.resize(capacity);
  }

  int parent(int idx) { return (idx - 1) / 2; }
  int leftChild(int idx) { return 2 * idx + 1; }
  int rightChild(int idx) { return 2 * idx + 2; }

  bool insert(int value) {
    if (size == capacity) return false;

    heap[size] = value;
    int i = size;

    while (i > 0 && heap[parent(i)] < heap[i]) {
      swap(heap[i], heap[parent(i)]);
      i = parent(i);
    }

    size++;
    return true;
  }

  void heapify(int idx) {
    int left = leftChild(idx);
    int right = rightChild(idx);
    int largest = idx;

    if (left < size && heap[left] > heap[largest]) largest = left;
    if (right < size && heap[right] > heap[largest]) largest = right;

    if (largest != idx) {
      swap(heap[idx], heap[largest]);
      heapify(largest);
    }
  }

  int extractMax() {
    int root = heap[0];
    heap[0] = heap[size - 1];  // Move the last element to the root
    heapify(0);                // Restore the heap property
    size--;

    return root;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;

  MaxHeap* heap = nullptr;
  vector<string> results;

  while (q--) {
    string op;
    cin >> op;

    if (op == "heap") {
      int capacity;
      cin >> capacity;
      heap = new MaxHeap(capacity);
      results.push_back("null");
    }

    else if (op == "insert") {
      int val;
      cin >> val;
      heap->insert(val);
      results.push_back("null");
    }

    else if (op == "extractMax") {
      results.push_back(to_string(heap->extractMax()));
    }

    else if (op == "heapSize") {
      results.push_back(to_string(heap->size));
    }

    else if (op == "isEmpty") {
      string res = ((heap->size == 0) ? "true" : "false");
      results.push_back(res);
    }
  }

  cout << "[";
  for (const auto& res : results) {
    cout << res << " ";
  }
  cout << "]\n";

  return 0;
}