class SegmentTree {
    int n;
    vector<int> tree, lazy;

public:
    SegmentTree(const vector<int>& nums) {
        n = nums.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        build(nums, 0, 0, n - 1);
    }

    void build(const vector<int>& nums, int node, int l, int r) {
        if (l == r) {
            tree[node] = nums[l];
        } else {
            int mid = (l + r) / 2;
            build(nums, 2 * node + 1, l, mid);
            build(nums, 2 * node + 2, mid + 1, r);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void push(int node, int l, int r) {
        if (lazy[node] != 0) {
            tree[node] -= lazy[node];
            if (l != r) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        push(node, l, r);
        if (r < ql || l > qr) return;

        if (ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }

        int mid = (l + r) / 2;
        update(2 * node + 1, l, mid, ql, qr, val);
        update(2 * node + 2, mid + 1, r, ql, qr, val);
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
    }

    int get(int node, int l, int r, int idx) {
        push(node, l, r);
        if (l == r) return tree[node];

        int mid = (l + r) / 2;
        if (idx <= mid)
            return get(2 * node + 1, l, mid, idx);
        else
            return get(2 * node + 2, mid + 1, r, idx);
    }

    void decrementRange(int l, int r) {
        update(0, 0, n - 1, l, r, 1);
    }

    bool isAllZero() {
        for (int i = 0; i < n; ++i) {
            if (get(0, 0, n - 1, i) != 0) return false;
        }
        return true;
    }
};




class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
         vector<int> delta(n+1, 0);

        for (auto& q : queries) {
            delta[q[0]] += 1;
            if (q[1] + 1 < n) delta[q[1] + 1] -= 1;
        }

       
        
        vector<int>newDelta(n,0);
        newDelta[0] = delta[0];
        for (int i = 1; i < n; ++i) {
            newDelta[i] = newDelta[i-1] + delta[i];
        }

        for(int i = 0; i < n; i++) {
            int reduce = nums[i] - newDelta[i];
            if(reduce > 0 )return false;
        }

        return true;
        
    }
};