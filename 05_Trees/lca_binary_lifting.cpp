#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int LOG = 20;
vector<vector<int>> up, g;
vector<int> depth;

void dfs(int u, int p) {
    up[u][0] = p;
    for(int j = 1; j < LOG; j++) {
        up[u][j] = up[up[u][j - 1]][j - 1];
    }

    for(int v : g[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int kth_ancestor(int u, int k) {
    for(int j = 0; j < LOG; j++) {
        if(k & (1 << j)) u = up[u][j];
    }
    return u;
}

int lca(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);
    u = kth_ancestor(u, depth[u] - depth[v]);

    if(u == v) return u;

    for(int j = LOG - 1; j >= 0; j--) {
        if(up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}

int main() {
    int n, q;
    cin >> n >> q;
    g.assign(n, {});
    up.assign(n, vector<int>(LOG, 0));
    depth.assign(n, 0);

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, 0);
    while(q--) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        cout << lca(u, v) + 1 << "\n";
    }
    return 0;
}
