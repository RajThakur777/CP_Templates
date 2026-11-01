#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Fenwick {
    int n;
    vector<ll> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, ll val) {
        for(; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    ll sum(int idx) {
        ll ans = 0;
        for(; idx > 0; idx -= idx & -idx) ans += bit[idx];
        return ans;
    }

    ll range_sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    Fenwick fw(n);

    for(int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        fw.add(i, x);
    }

    while(q--) {
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 1) fw.add(l, r);
        else cout << fw.range_sum(l, r) << "\n";
    }
    return 0;
}
