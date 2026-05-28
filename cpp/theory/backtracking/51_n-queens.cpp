#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<string>> vvs;
typedef vector<vector<int>> vvi;

class Solution {
   public:
    vvs solveNQueens(int n) {
        // Initialize a board of n x n  with bool values, (0 for empty, 1 for queen)
        // ! for n = 3
        // { 1 0 0 }
        // { 0 0 1 }
        // { 0 1 0 }
        vvi board(n, vector<int>(n, 0));
        vvs res;
        solve(board, 0, 0, n, res);

        return res;
    }

    void solve(vvi& board, int row, int col, int n, vvs& res) {
        if (row == n) {
            vector<string> path;
            buildPath(board, path);
            res.push_back(path);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (isSafe(board, row, c, n)) {
                board[row][c] = 1;                 // Place the queen
                solve(board, row + 1, 0, n, res);  // Recur to place the next queen
                board[row][c] = 0;                 // Backtrack
            }
        }
    }

    // helper function to check if it's safe to place a queen at (row, col)
    bool isSafe(vvi& board, int row, int col, int n) {
        // Traverse the column upwards
        for (int r = 0; r < row; r++) {
            if (board[r][col] == 1) {
                return false;
            }
        }

        // Traverse the upper left diagonal
        for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
            if (board[r][c] == 1) {
                return false;
            }
        }

        // Traverse the upper right diagonal
        for (int r = row, c = col; r >= 0 && c < n; r--, c++) {
            if (board[r][c] == 1) {
                return false;
            }
        }

        return true;
    }

    // helper function to build the path of the current board configuration
    vector<string> buildPath(vvi& board, vector<string>& path) {
        for (const auto& row : board) {
            string s;
            for (int cell : row) {
                s += (cell == 1 ? 'Q' : '.');
            }
            path.push_back(s);
        }
        return path;
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