#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        unordered_map<int, vector<int>> mpp;

        // Build the map of diagonals
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mpp[i + j].push_back(mat[i][j]);
            }
        }

        // reverse the list based on j + i even or odd index
        for (auto& it : mpp) {
            if (it.first & 1 == 0) {
                reverse(it.second.begin(), it.second.end());
            }
        }

        // Build the result
        vector<int> res;
        for (int i = 0; i < m + n - 1; i++) {
            for (int val : mpp[i]) {
                res.push_back(val);
            }
        }

        return res;
    }
};

int main() {
    // Disable standard input and output synchronization for faster I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> mat(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> mat[i][j];
            }
        }
        vector<int> result = sol.findDiagonalOrder(mat);
        cout << "[";
        for (int num = 0; num < result.size(); num++) {
            cout << result[num] << ((num < result.size() - 1) ? ", " : "");
        }
        cout << "]\n";
    }

    return 0;
}