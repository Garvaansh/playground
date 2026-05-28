#include <bits/stdc++.h>
using namespace std;

class NumArray {
   public:
    vector<int> nums;
    vector<int> block;
    int blockSize;

    NumArray(vector<int>& nums) : nums(nums) {
        int n = nums.size();
        blockSize = ceil(sqrt(n));
        block.resize(blockSize, 0);

        // Build the block array
        for (int i = 0; i < n; i++) {
            block[i / blockSize] += nums[i];
        }
    }

    void update(int index, int val) {
        // Update the block sum
        int blockIdx = index / blockSize;
        block[blockIdx] -= (nums[index]);
        block[blockIdx] += val;

        nums[index] = val;
    }

    int sumRange(int left, int right) {
        int sum = 0;
        // Case 1: left and right are in the same block
        int L = left / blockSize, R = right / blockSize;

        if (L == R) {
            for (int i = left; i <= right; i++)
                sum += nums[i];
        }

        // Case 2: left and right are in different blocks
        else {
            // Sum the full blocks between L and R
            for (int i = L + 1; i < R; i++)
                sum += block[i];

            // Sum the remaining elements in the left block
            for (int i = left; i < (L + 1) * blockSize; i++)
                sum += nums[i];

            // Sum the remaining elements in the right block
            for (int i = R * blockSize; i <= right; i++)
                sum += nums[i];
        }

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    NumArray* obj = new NumArray(nums);

    int q;
    cin >> q;

    vector<string> output;

    while (q--) {
        string op;
        cin >> op;

        if (op == "sumRange") {
            int l, r;
            cin >> l >> r;
            int res = obj->sumRange(l, r);
            output.push_back(to_string(res));
        } else if (op == "update") {
            int idx, val;
            cin >> idx >> val;
            obj->update(idx, val);
            output.push_back("null");
        }
    }

    // print like [null, 9, null, 8]
    cout << "[";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i];
        if (i != output.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}