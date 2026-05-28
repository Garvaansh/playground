#include <bits/stdc++.h>
using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> minHeap;

class Solution {
   public:
    /**  Approach 1: Use a Priority queue
     * * store all the diagonal elements in a minHeap (sorted in ascending order)
     * * then build the result matrix by popping elements from the minHeap for each diagonal
     */

    // vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    //     unordered_map<int, minHeap> mpp;
    //     int m = mat.size(), n = mat[0].size();

    //     // Store each diagonal in a separate minHeap (already sorted in ascending order)
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             mpp[j - i].push(mat[i][j]);
    //         }
    //     }

    //     // Build the result mat
    //     vector<vector<int>> res(m, vector<int>(n));
    //     for (int i = 0; i < m; i++) {
    //         for (int j = 0; j < n; j++) {
    //             res[i][j] = mpp[j - i].top();
    //             mpp[j - i].pop();
    //         }
    //     }

    //     return res;
    // }

    /** Approach 2: Use a vector and sort it
     * * apparently it's faster than a minHeap,
     * * cuz in minHeap
     * * insertoin : k log k
     * * pop : k log k
     * * total : 2 * k log k
     * where as in vector + sort
     * * insertion : k
     * * sort : k log k
     * * total : k + k log k = k log k
     */
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> mpp;
        int m = mat.size(), n = mat[0].size();

        // Store each diagonal in a separate minHeap (already sorted in ascending order)
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mpp[j - i].push_back(mat[i][j]);
            }
        }

        for (auto& it : mpp) {
            sort(it.second.begin(), it.second.end());
            
        }

        // Build the result mat
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                res[i][j] = mpp[j - i].back();
                mpp[j - i].pop_back();
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
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> mat[i][j];
            }
        }

        vector<vector<int>> result = sol.diagonalSort(mat);
        cout << "[";
        for (int row = 0; row < m; row++) {
            cout << "[";
            for (int i = 0; i < n; i++) {
                cout << result[row][i] << ((i < n - 1) ? ", " : "");
            }
            cout << "]" << ((row < m - 1) ? ",\n " : "");
        }
        cout << "]";
    }

    return 0;
}