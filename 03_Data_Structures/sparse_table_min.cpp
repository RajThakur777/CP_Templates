#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct SparseTable {
    int n, K;
    vector<vector<ll>> st;
    vector<int> lg;

    SparseTable(vector<ll> &a) {
        n = a.size();
        K = 1;
        while((1 << K) <= n) K++;
        st.assign(K, vector<ll>(n));
        lg.assign(n + 1, 0);

        for(int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;
        st[0] = a;

        for(int k = 1; k < K; k++) {
            for(int i = 0; i + (1 << k) <= n; i++) {
                st[k][i] = min(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    ll query(int l, int r) {
        int k = lg[r - l + 1];
        return min(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(ll &x : a) cin >> x;
    SparseTable st(a);

    while(q--) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        cout << st.query(l, r) << "\n";
    }
    return 0;
}
