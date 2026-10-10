class NumArray {
    vector<int> seg;
    int n;

public:
    // Build the Segment Tree
    int solve(int l, int r, int ind, const vector<int>& nums) {
        if (l == r) {
            return seg[ind] = nums[l];
        }
        int mid = (l + r) / 2;
        int left = solve(l, mid, 2 * ind + 1, nums);
        int right = solve(mid + 1, r, 2 * ind + 2, nums);
        return seg[ind] = left + right; // Fixed: sum of left and right segments
    }

    // Range Sum Query
    int find(int l, int r, int ind, int ql, int qr) {
        // No overlap
        if (r < ql || l > qr) {
            return 0;
        }
        // Complete overlap
        if (ql <= l && r <= qr) {
            return seg[ind];
        }
        // Partial overlap
        int mid = (l + r) / 2;
        int left = find(l, mid, 2 * ind + 1, ql, qr);
        int right = find(mid + 1, r, 2 * ind + 2, ql, qr);
        return left + right;
    }

    // Point Update Helper
    void updateTree(int l, int r, int ind, int index, int val) {
        if (l == r) {
            seg[ind] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (index <= mid) {
            updateTree(l, mid, 2 * ind + 1, index, val);
        } else {
            updateTree(mid + 1, r, 2 * ind + 2, index, val);
        }
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        if (n > 0) {
            seg.resize(4 * n, 0);
            solve(0, n - 1, 0, nums);
        }
    }

    void update(int index, int val) {
        updateTree(0, n - 1, 0, index, val);
    }

    int sumRange(int left, int right) {
        return find(0, n - 1, 0, left, right);
    }
};