#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:
    T val;
    Node<T>* next;

    // Constructor 1 — takes only data
    Node(T value) : val(value), next(nullptr) {}

    // Constructor 2 — takes both data and next
    Node(T value,  Node<T>* next1) : val(value), next(next1) {}
};

#endif
