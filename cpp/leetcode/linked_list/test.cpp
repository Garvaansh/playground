#include <bits/stdc++.h>
#include "../imports/node.h"
using namespace std; 

// convert array to linked list
Node<int>* convertarrtolist(vector<int> arr){
    Node<int>* head = new Node<int>(arr[0]);
    Node<int>* temp = head;
    for(int i = 1; i < arr.size(); i++){
        temp->next = new Node<int>(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Traverse through thew list
void travserse(Node<int>* head){
  Node<int>* temp = head;  
  cout << "Elements in linked list:" << endl;
  while(temp != nullptr){
    cout << temp->val << " ";
    temp = temp->next;
  }
}

// Finds the length of LL 
int findlength(Node<int>* head){
  Node<int>* temp = head;  
  int count = 0;
  while(temp != nullptr){
    count++;
    temp = temp->next;
  }
  return count;
}


int main() {

  int n;
  cin >> n;

  vector<int> arr(n);
  for(int i = 0; i < n; i++){
    cin >> arr[i];
  }

  Node<int>* head = convertarrtolist(arr);
  travserse(head);
  cout << endl;
  cout << "Length: " << findlength(head) << endl;

    return 0;
}