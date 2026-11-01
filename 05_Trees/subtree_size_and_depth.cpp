#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> g;
vector<ll> subtree_size;
vector<int> depth;

void dfs(int u, int p) {
    subtree_size[u] = 1;
    for(int v : g[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        subtree_size[u] += subtree_size[v];
    }
}

int main() {
    int n;
    cin >> n;
    g.assign(n, {});
    subtree_size.assign(n, 0);
    depth.assign(n, 0);

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1);
    for(int i = 0; i < n; i++) {
        cout << "node " << i + 1 << ": size = " << subtree_size[i]
             << ", depth = " << depth[i] << "\n";
    }
    return 0;
}
