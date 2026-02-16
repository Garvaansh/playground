#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    if (&a != &b) { 
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}

void selection_sort(vector<int> &arr, int n){
    for(int i = 0; i < n - 1; i++){
        int mini = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }
}

int main() {
    vector<int> arr;
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << "Original Array: ";
    for(auto it : arr) cout << it << " ";
    cout << "\n";

    selection_sort(arr, n);

    cout << "Sorted Array: ";
    for(auto it : arr) cout << it << " ";
    cout << "\n";

    return 0;
}
