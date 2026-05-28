#include <bits/stdc++.h>
using namespace std;

class MinHeap {
 public:
  int capacity, size;
  vector<int> heap;

  MinHeap(int capacity) : capacity(capacity) {
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

    while (i > 0 && heap[parent(i)] > heap[i]) {
      swap(heap[i], heap[parent(i)]);
      i = parent(i);
    }

    size++;
    return true;
  }

  void heapify(int idx) {
    int left = leftChild(idx);
    int right = rightChild(idx);
    int smallest = idx;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != idx) {
      swap(heap[idx], heap[smallest]);
      heapify(smallest);
    }
  }

  int extractMin() {
    if (size == 0) return -1; 

    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapify(0);
    return root;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int q;
  cin >> q;

  MinHeap* heap = nullptr;
  vector<string> results;

  while (q--) {
    string op;
    cin >> op;

    if (op == "heap") {
      int capacity;
      cin >> capacity;
      heap = new MinHeap(capacity);
      results.push_back("null");
    }

    else if (op == "insert") {
      int val;
      cin >> val;
      heap->insert(val);
      results.push_back("null");
    }

    else if (op == "extractMin") {
      results.push_back(to_string(heap->extractMin()));
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