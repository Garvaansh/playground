#include <bits/stdc++.h>
using namespace std;

void permutation(string processed, string unprocessed, vector<string>& res) {
    if (unprocessed.empty()) {
        res.push_back(processed);
        return;
    }

    char ch = unprocessed[0];
    for (size_t i = 0; i <= processed.size(); i++) {
        string first = processed.substr(0, i);
        string second = processed.substr(i, processed.size() - i);
        permutation(first + ch + second, unprocessed.substr(1), res);
    }
}

int main() {
    // Disable standard input and output synchronization
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    vector<string> res;
    permutation("", str, res);

    cout << "[";
    for (size_t i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i < res.size() - 1) {
            cout << ",";
        }
    }
    cout << "]\n";

    return 0;
}