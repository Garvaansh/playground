#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vvi;

class Solution {
   public:
    void solve(int n, int from, int to, int aux, vvi& res) {
        if (n == 1) {
            res.push_back({n, from, to});
            return;
        }

        // move n-1 disks from source -> auxiliary
        solve(n - 1, from, aux, to, res);

        // move largest disk from source -> destination
        res.push_back({n, from, to});

        // move n-1 disks from auxiliary -> destination
        solve(n - 1, aux, to, from, res);
    }

    vector<vector<int>> towerOfHanoi(int n) {
        vvi res;

        solve(n, 1, 3, 2, res);

        return res;
    }
};

int main() {
    // Disable standard input and output synchronization
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 3;
    vvi res = Solution().towerOfHanoi(n);
    for (const auto& move : res) {
        cout << "Move disk " << move[0] << " from rod " << move[1] << " to rod " << move[2] << "\n";
    }

    return 0;
}