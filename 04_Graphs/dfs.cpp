#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs(int u, int p, vector<vector<int>> &g, vector<int> &vis) {
    vis[u] = 1;
    for(int v : g[u]) {
        if(v == p || vis[v]) continue;
        dfs(v, u, g, vis);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> vis(n, 0);
    dfs(0, -1, g, vis);
    return 0;
}
