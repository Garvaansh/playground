#pragma once

template <typename T>
class Node {
 public:
  T val;
  Node<T>* next;
  Node<T>* prev;

  // Constructor 1 — takes only data
  explicit Node(T value) : val(value), next(nullptr), prev(nullptr) {}

  // Constructor 2 — takes both data and next
  Node(T value, Node<T>* next1, Node<T>* prev1) : val(value), next(next1), prev(prev1) {}
};