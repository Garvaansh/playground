#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);

        for (auto& it : trips) {
            int pass = it[0], start = it[1], end = it[2];
            diff[start] += pass;
            diff[end] -= pass;
        }

        for (int i = 0; i < 1000; i++) {
            if (i > 0) diff[i] += diff[i - 1];
            if (diff[i] > capacity) return false;
        }

        return true;
    }
};

int main() {
    // Disable standard input and output synchronization
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    int t;
    cin >> t;
    while (t--) {
        int n, capacity;
        cin >> n >> capacity;

        vector<vector<int>> trips(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> trips[i][0] >> trips[i][1] >> trips[i][2];
        }

        bool result = sol.carPooling(trips, capacity);
        cout << (result ? "true" : "false") << "\n";
    }

    return 0;
}