class Solution {
public:
    int segTree[400007];
    vector<int>baskets;
    void build(int p, int l, int r) {
        if(l == r) {
            segTree[p] = baskets[l];
            return;
        }

        int mid = (l + r) / 2;
        build(p * 2 , l , mid);
        build(p * 2 + 1, mid+1, r);

        segTree[p] = max(segTree[2*p], segTree[2*p+1]);
    }
    int query(int p , int l , int r, int ql, int qr) {
        if(ql > r || qr < l) {
            return INT_MIN;
        }
        if(ql <= l && r <= qr) {
            return segTree[p];
        }
        int mid = (l + r) / 2;
        return max(query(p * 2 , l , mid, ql, qr), query(p*2 + 1, mid+1, r, ql,qr));
    }

    void update(int p, int l, int r, int pos, int val) {
        if(l == r) {
            segTree[p] = val;
            return;
        }
        int mid = (l + r) / 2;

        if(pos <= mid) {
            update(2 * p , l, mid, pos, val);
        }
        else {
            update(2*p + 1, mid + 1, r, pos, val);
        }
        segTree[p] = max(segTree[2*p], segTree[2*p + 1]);
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

            this->baskets = baskets;
            int m = baskets.size();
            int count = 0;

            if(m == 0) {
                return fruits.size();
            }
            build(1,0,m-1);
            for(int i = 0; i < m; i++) {
                int l = 0, r = m-1, res = -1;

                while(l <= r) {
                    int mid = (l + r) / 2;
                    if(query(1,0,m-1,0,mid) >= fruits[i]) {
                        res = mid;
                        r = mid-1;
                    }
                    else {
                        l = mid + 1;
                    }
                }
                if(res != -1 && baskets[res] >= fruits[i]) {
                    update(1,0,m-1,res,INT_MIN);
                }
                else {
                    count++;
                }
            }
            return count;
    }
};