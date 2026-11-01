#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct SegmentTree {
    int n;
    vector<ll> tree;

    SegmentTree(vector<ll> &a) {
        n = (int)a.size();
        tree.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    void build(int node, int start, int end, vector<ll> &a) {
        if(start == end) {
            tree[node] = a[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, a);
        build(2 * node + 1, mid + 1, end, a);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void update(int node, int start, int end, int idx, ll val) {
        if(start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if(idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    ll query(int node, int start, int end, int l, int r) {
        if(r < start || end < l) return 0;
        if(l <= start && end <= r) return tree[node];

        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r)
             + query(2 * node + 1, mid + 1, end, l, r);
    }

    void update(int idx, ll val) { update(1, 0, n - 1, idx, val); }
    ll query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(ll &x : a) cin >> x;

    SegmentTree st(a);
    while(q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if(type == 1) st.update(a, b);
        else cout << st.query(a, b) << "\n";
    }
    return 0;
}
