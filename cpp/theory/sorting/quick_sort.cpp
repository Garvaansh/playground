#include <bits/stdc++.h>
using namespace std; 

void swap(int &a, int &b){
  if (&a != &b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}

int partition(vector<int> &arr, int low, int high){
  int pivot = arr[low];
  int left = low, right = high;

  while(left < right){
    while(arr[left] <= pivot && left <= high) left++;
    while(arr[right] > pivot && right >= low) right--;
    if(left < right) swap(arr[left], arr[right]);
  }
  swap(arr[low], arr[right]);
  return right;
  }

void quick_sort(vector<int> &arr, int low, int high){
  if(low < high){
    int pIndex = partition(arr, low, high);
    quick_sort(arr, low, pIndex - 1);
    quick_sort(arr, pIndex + 1, high);
  }
}

int main(){
  vector<int> arr = { 2, -1, 0 ,4, 4, 3, 5};
  // int n;
  // cout << "Enter the number of elements: ";
  // cin >> n;

  // cout << "Enter the elements: ";
  // for(int i = 0; i < n; i++){
  //     int x;
  //     cin >> x;
  //     arr.push_back(x);
  // }

  cout << "Original Array: ";
  for(auto it : arr) cout << it << " ";
  cout << "\n";

  quick_sort(arr, 0, arr.size() - 1);

  cout << "Sorted Array: ";
  for(auto it : arr) cout << it << " ";
  cout << "\n";

    return 0;
}