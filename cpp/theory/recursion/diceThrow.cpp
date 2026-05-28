#include <bits/stdc++.h>
using namespace std;

void solve(string p, int target, int face, vector<string>& res) {
    if (target == 0) {
        res.push_back(p);
        return;
    }

    for (int i = 1; i <= face; i++) {
        if (target - i >= 0) {
            solve(p + to_string(i), target - i, face, res);
        }
    }
}

int count(string p, int target, int face) {
    if (target == 0) {
        return 1;
    }

    int ans  = 0;

    for (int i = 1; i <= face; i++) {
        if (target - i >= 0) {
            ans += count(p + to_string(i), target - i, face);
        }
    }

    return ans;
}

int main() {
    // Disable standard input and output synchronization
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int target, face;
    cin >> target >> face;

    /**
     * ! Returns the array list for all the combinatins
     */
     // vector<string> res;
     // solve("", target, face, res);


    // cout << "[";
    // for (size_t i = 0; i < res.size(); i++) {
    //     cout << res[i];
    //     if (i < res.size() - 1) {
      //         cout << ",";
      //     }
      // }
      // cout << "]\n";

    int cnt = count("", target, face);
    cout << cnt << "\n";

    return 0;
}