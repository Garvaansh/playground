#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int key, value;
  Node* next;
  Node* prev;

  Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};

/**
 * Intuition: Use a doubly linked list with a hashmap to quickly update and access recently used
 * items, keeping the most recent at the front. Approach: On get/put, move the accessed node to the
 * front; if capacity is exceeded, remove the least recently used node from the back. Time
 * Complexity: O(1) for both get and put operations. Space Complexity: O(capacity) for the hashmap
 * and linked list nodes.
 */
class LRUCache {
 public:
  int capacity;
  Node* head;
  Node* tail;
  unordered_map<int, Node*> cache;
  LRUCache(int capacity) : capacity(capacity) {
    // Dummy head and tail nodes to avoid edge cases in add and remove operations
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
  }

  void remove(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void insert_front(Node* node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
  }
  int get(int key) {
    if (cache.find(key) == cache.end()) {
      return -1;  // Key not found
    }
    Node* node = cache[key];
    remove(node);  // Move the accessed node to the front (most recently used)
    insert_front(node);
    return node->value;
  }

  void put(int key, int value) {
    if (cache.find(key) != cache.end()) {
      // If the key already exists, update the value and move it to the front
      Node* node = cache[key];
      node->value = value;
      remove(node);
      insert_front(node);
    } else {
      // If the key does not exist, create a new node
      Node* newNode = new Node(key, value);
      cache[key] = newNode;
      // Insert the new node at the front
      insert_front(newNode);

      // If the cache exceeds capacity, remove the least recently used item
      if (cache.size() > capacity) {
        Node* lru = tail->prev;  // The least recently used node is right before the tail
        cache.erase(lru->key);   // Remove it from the cache
        remove(lru);             // Remove it from the linked list
        delete lru;              // Free memory
      }
    }
  }

  ~LRUCache() {
    Node* curr = head;
    while (curr != nullptr) {
      Node* nextNode = curr->next;
      delete curr;
      curr = nextNode;
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  LRUCache* cache = nullptr;
  vector<string> results;

  int n;
  cin >> n;

  /*
  Example input:
  10
  LRUCache 2
  put 1 1
  put 2 2
  get 1
  put 3 3
  get 2
  put 4 4
  get 1
  get 3
  get 4
  */

  for (int i = 0; i < n; i++) {
    string op;
    cin >> op;

    if (op == "LRUCache") {
      int cap;
      cin >> cap;
      cache = new LRUCache(cap);
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