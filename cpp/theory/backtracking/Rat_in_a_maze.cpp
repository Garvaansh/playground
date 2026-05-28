#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;

void solve(int i, int j, int m, int n, string path, vvi& arr, vector<string>& res) {
    // Base condition 1: if i or j are out of bound, or arr[i][j] == 0
    if (i < 0 || j < 0 || i >= m || j >= n || arr[i][j] == 0) {
        return;
    }

    // Base condition 2: if we found the m-1, n-1 cell
    if (i == m - 1 && j == n - 1) {
        res.push_back(path);
        arr[i][j] = 1;  // unmark the cell before returning
        return;
    }

    // explore all the paths
    arr[i][j] = 0;  // mark the cell visited

    /** 
     * ! Ensure to check the order sometimes
     * ! they expect in lexicographical order. so it'll  be D L R U
     */

    // Move down
    path += "D";
    solve(i + 1, j, m, n, path, arr, res);
    path.pop_back();  // backtrack
    // Move up
    path += "U";
    solve(i - 1, j, m, n, path, arr, res);
    path.pop_back();  // backtrack
    // Move left
    path += "L";
    solve(i, j - 1, m, n, path, arr, res);
    path.pop_back();  // backtrack
    // Move right
    path += "R";
    solve(i, j + 1, m, n, path, arr, res);
    path.pop_back();  // backtrack

    arr[i][j] = 1;  // unmark the cell
}

vector<string> searchMaze(vvi& arr, int n) {
    // Write your code here.
    vector<string> res;
    int m = arr.size(), n = arr[0].size();
    // solve(i, j, m, n, curr-path, arr, res);
    solve(0, 0, m, n, "", arr, res);

    return res;
}

int main() {
    // Disable standard input and output synchronization
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}