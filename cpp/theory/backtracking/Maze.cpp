#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

// * Goal -> a maze is given, find if there is a path from start to end
// ? We just have to print all the possible paths from start to end, and
// ! IT CAN ONLY MOVE RIGHT OR DOWN

typedef vector<vector<int>> vvi;

class Solution {
   public:
    void solve(vvi& arr, int n, int i, int j, string path, vector<string>& res) {
        if (i < 0 || j < 0 || i >= n || j >= n || arr[i][j] == 1) return;

        if (i == n - 1 && j == n - 1) {
            res.push_back(path);
            arr[i][j] = 0;
            return;
        }

        arr[i][j] = 1;

        // Traverse  right
        path += 'R';
        solve(arr, n, i, j + 1, path, res);
        path.pop_back();

        // Traverse down
        path += 'D';
        solve(arr, n, i + 1, j, path, res);
        path.pop_back();

        // Backtrack & reset the current cell to 0
        arr[i][j] = 0;
    }

    vector<string> paths(vvi& arr, int n) {
        vector<string> ans;
        string path;
        solve(arr, n, 0, 0, path, ans);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vvi arr = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    Solution sol;

    vector<string> ans = sol.paths(arr, 3);

    cout << "[";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ((i < ans.size() - 1) ? "," : "");
    }
    cout << "]\n";

    return 0;
}