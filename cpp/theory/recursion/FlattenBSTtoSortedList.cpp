#include <bits/stdc++.h>
using namespace std;

template <typename T>
// Binary Search Tree Node
class Node {
   public:
    T data;
    Node<T>* left;
    Node<T>* right;

    Node() {
        this->data = 0;
        this->left = nullptr;
        this->right = nullptr;
    }

    Node(T data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~Node() {
        if (left) delete this->left;
        if (right) delete this->right;
    }
};

template <typename T>
class BST {
   public:
    Node<T>* insertIntoBST(Node<T>* root, T val) {
        // base case
        if (!root) {
            return new Node<T>(val);
        }

        // left subtree
        if (val < root->data) {
            root->left = insertIntoBST(root->left, val);
        }

        // right subtree
        else {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};

template <typename T>
class Solution {
   public:
    Node<int>* flatten(Node<int>* root) {
        if (!root) {
            return NULL;
        }

        Node<int>* head = flatten(root->left);
        root->left = NULL;
        root->right = flatten(root->right);

        if (head != NULL) {
            Node<int>* temp = head;
            while (temp && temp->right) {
                temp = temp->right;
            }
            temp->right = root;
        } else {
            head = root;
        }

        if (head == NULL) {
            return root;
        }

        return head;
    }
};

int main() {
    // Disable standard input and output synchronization
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    BST<int> tree;

    Node<int>* root = nullptr;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;

        root = tree.insertIntoBST(root, val);
    }

    Solution<int> sol;
    // flatten BST
    Node<int>* head = sol.flatten(root);

    // print flattened list
    cout << "Flattened BST:\n";

    Node<int>* temp = head;

    while (temp) {
        cout << temp->data << " ";
        temp = temp->right;
    }

    cout << "\n";

    delete head;

    return 0;
}