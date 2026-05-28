#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int layers = min(m / 2, n / 2);

        for (int i = 0; i < layers; i++) {
            vector<int> layer;
            int left = i, bottom = m - i - 1, right = n - i - 1, top = i;

            // left column
            for (int r = top; r <= bottom; r++) {
                layer.push_back(grid[r][left]);
            }

            // bottom row
            for (int c = left + 1; c <= right; c++) {
                layer.push_back(grid[bottom][c]);
            }

            // right column
            for (int r = bottom - 1; r >= top; r--) {
                layer.push_back(grid[r][right]);
            }

            // top row
            for (int c = right - 1; c > left; c--) {
                layer.push_back(grid[top][c]);
            }

            int len = layer.size();
            int rot = k % len;
            // rotate the layer
            reverse(layer.begin(), layer.end());
            reverse(layer.begin(), layer.begin() + rot);
            reverse(layer.begin() + rot, layer.end());

            int idx = 0;
            // left column
            for (int j = top; j <= bottom; j++) {
                grid[j][i] = layer[idx++];
            }

            // bottom row
            for (int j = left + 1; j <= right; j++) {
                grid[bottom][j] = layer[idx++];
            }

            // right column
            for (int j = bottom - 1; j >= top; j--) {
                grid[j][right] = layer[idx++];
            }

            // top row
            for (int j = right - 1; j > top; j--) {
                grid[i][j] = layer[idx++];
            }
        }

        return grid;
    }
};

int main() {
    // Disable standard input and output synchronization
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}