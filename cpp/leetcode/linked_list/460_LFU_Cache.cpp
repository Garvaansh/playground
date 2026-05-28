#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int key, value, count;
  Node* next;
  Node* prev;

  Node(int key, int value) : key(key), value(value), count(1), next(nullptr), prev(nullptr) {}
};

class List {
 public:
  int size;
  Node* head;
  Node* tail;

  List() : size(0) {
    head = new Node(-1, -1);  // Dummy head
    tail = new Node(-1, -1);  // Dummy tail
    head->next = tail;
    tail->prev = head;
  }

  void addFront(Node* node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
    size++;
  }

  void remove(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
    size--;
  }
};

class LFUCache {
 public:
  // Declaration of variabled needed.
  int capacity;
  int minFreq, currsize;
  Node* head;
  Node* tail;
  unordered_map<int, Node*> cache;
  unordered_map<int, List*> freqMap;

  // Constructor to initialize the LFUCache with a given capacity.
  LFUCache(int capacity) : capacity(capacity), minFreq(0), currsize(0) {}

  void updateFreq(Node* node) {
    freqMap[node->count]->remove(node);  // Remove from current frequency list
    if (node->count == minFreq && freqMap[node->count]->size == 0) {
      minFreq++;  // If the current frequency list is empty, increment minFreq
    }

    List* nextHigherFreqList = new List;
    if (freqMap.find(node->count + 1) != freqMap.end()) {
      nextHigherFreqList = freqMap[node->count + 1];
    }

    node->count++;                              // Increment the frequency count
    nextHigherFreqList->addFront(node);         // Add to the new frequency list
    freqMap[node->count] = nextHigherFreqList;  // Update the frequency map
    cache[node->key] = node;                    // Update the cache with the new node position
  }

  int get(int key) {
    if (cache.find(key) != cache.end()) {
      Node* Node = cache[key];
      int val = Node->value;
      updateFreq(Node);
      return val;
    }
    return -1;  // Key not found
  }

  void put(int key, int value) {
    if (capacity == 0) return;  // Edge case for zero capacity

    if (cache.find(key) != cache.end()) {
      cache[key]->value = value;  // Update the value if key already exists
      updateFreq(cache[key]);     // Update the frequency of the existing key
    } else {
      if (currsize == capacity) {
        // Remove the least frequently used item if the cache is at full capacity

        List* list = freqMap[minFreq];       // Get the list of the least frequently used items
        cache.erase(list->tail->prev->key);  // Remove the least frequently used item from cache
        list->remove(list->tail->prev);      // Remove the least frequently used item from the list
        currsize--;                          // Decrement the current size of the cache
      }

      currsize++;   // Increment the current size of the cache
      minFreq = 1;  // Reset the minimum frequency to 1 for the new item
      List* newList = new List();
      if (freqMap.find(minFreq) != freqMap.end()) {
        newList = freqMap[minFreq];
      }
      Node* newNode = new Node(key, value);  // Create a new node for the new key-value pair
      newList->addFront(newNode);            // Add the new node to the front of
      cache[key] = newNode;                  // Add the new node to the cache
      freqMap[minFreq] = newList;            // Update the frequency map with the new
    }
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  LFUCache* cache = nullptr;
  vector<string> results;

  int n;
  cin >> n;

  /*
  Example input:
  11
  LFUCache 2
  put 1 1
  put 2 2
  get 1
  put 3 3
  get 2
  get 3
  put 4 4
  get 1
  get 3
  get 4
  */

  for (int i = 0; i < n; i++) {
    string op;
    cin >> op;

    if (op == "LFUCache") {
      int cap;
      cin >> cap;
      cache = new LFUCache(cap);
      results.push_back("null");
    } else if (op == "put") {
      int key, value;
      cin >> key >> value;
      cache->put(key, value);
      results.push_back("null");
    } else if (op == "get") {
      int key;
      cin >> key;
      int ans = cache->get(key);
      results.push_back(to_string(ans));
    }
  }

  cout << "[";
  for (int i = 0; i < results.size(); i++) {
    cout << results[i];
    if (i + 1 < results.size()) cout << ", ";
  }
  cout << "]\n";

  delete cache;
  return 0;
}