#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<string>> vvs;

//! Optimized Version of N-Queens
class Solution {
   public:
    int N;
    unordered_set<int> cols;        // To track columns where queens are placed
    unordered_set<int> Major_diag;  // To track major diagonals (row - col)
    unordered_set<int> Minor_diag;  // To track major diagonals (row + col)

    vvs solveNQueens(int n) {
        N = n;
        // Initialize a board of n x n  with bool values, (0 for empty, 1 for queen)
        // ! for n = 3
        // { 1 0 0 }
        // { 0 0 1 }
        // { 0 1 0 }
        vector<string> board(N, string(N, '.'));
        vvs res;
        solve(board, 0, 0, res);

        return res;
    }

    void solve(vector<string>& board, int row, int col, vvs& res) {
        if (row == N) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < N; c++) {
            if (cols.count(c) || Major_diag.count(row - c) || Minor_diag.count(row + c)) {
                continue;  // Skip if placing a queen here would lead to a conflict
            }

            // Place the queen and mark the column, and diagonals are occupied
            board[row][c] = 'Q';
            cols.insert(c);
            Major_diag.insert(row - c);
            Minor_diag.insert(row + c);

            // Recur to place queens in the next row
            solve(board, row + 1, c, res);

            // Backtrack: Remove the queen and unmark the column, and diagonals
            board[row][c] = '.';
            cols.erase(c);
            Major_diag.erase(row - c);
            Minor_diag.erase(row + c);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    int n;
    cin >> n;

    vvs res = sol.solveNQueens(n);

    cout << "[\n";
    for (const auto& paths : res) {
        cout << "  [\n";
        for (const auto& path : paths) {
            cout << "    \"" << path << "\",\n";
        }
        cout << "  ],\n";
    }
    cout << "]\n";

    return 0;
}