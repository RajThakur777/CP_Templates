#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a == b) return false;

        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    DSU dsu(n);

    while(q--) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
    }
    return 0;
}
