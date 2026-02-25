#include <bits/stdc++.h>
using namespace std;

using vector_pair = vector<pair<int, int>>;

class Solution {
 public:
  vector_pair countBits(const vector<int>& arr) {
    vector_pair bitCounts;
    for (int num : arr) {
      // Built-in function because it is hardware accelerated
      int count = __builtin_popcount(num);
      bitCounts.push_back({num, count});
    }
    return bitCounts;
  }

  /** Other approach to count bits ->
   * count = 0;
   * while(n > 0) {
   *  n = n & (n - 1); // drops the lowest set bit
   *  count++;
   * }
   */

  /** Uses Extra space of O(n) to store count of set bits,
   * but can be avoided by simply using nlogn sort algorithm and using built-in function
   */

  void merge(vector_pair& arr, int left, int mid, int right) {
    vector_pair temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
      if (arr[i].second < arr[j].second ||
          (arr[i].second == arr[j].second && arr[i].first < arr[j].first)) {
        temp[k++] = arr[i++];
      } else {
        temp[k++] = arr[j++];
      }
    }
    while (i <= mid)
      temp[k++] = arr[i++];
    while (j <= right)
      temp[k++] = arr[j++];
    for (int m = 0; m < temp.size(); m++) {
      arr[left + m] = temp[m];
    }
  }

  void mergesort(vector_pair& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }

  vector<int> sortByBits(vector<int>& arr) {
    vector_pair bitCount = countBits(arr);
    mergesort(bitCount, 0, bitCount.size() - 1);
    vector<int> sortedArr;
    for (const auto& p : bitCount) {
      sortedArr.push_back(p.first);
    }
    return sortedArr;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
      cin >> arr[i];
    vector<int> res = Solution().sortByBits(arr);
    cout << "[";
    for (int i = 0; i < res.size(); i++)
      cout << res[i] << ((i == res.size() - 1) ? "" : " ");
    cout << "]";
    cout << endl;
  }

  return 0;
}