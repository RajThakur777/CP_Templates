#include <bits/stdc++.h>
using namespace std;
#define ll long long

void dfs1(int u, vector<vector<int>> &g, vector<int> &vis, vector<int> &order) {
    vis[u] = 1;
    for(int v : g[u]) if(!vis[v]) dfs1(v, g, vis, order);
    order.push_back(u);
}

void dfs2(int u, vector<vector<int>> &rg, vector<int> &vis, vector<int> &component) {
    vis[u] = 1;
    component.push_back(u);
    for(int v : rg[u]) if(!vis[v]) dfs2(v, rg, vis, component);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n), rg(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        rg[v].push_back(u);
    }

    vector<int> vis(n, 0), order;
    for(int i = 0; i < n; i++) if(!vis[i]) dfs1(i, g, vis, order);

    fill(vis.begin(), vis.end(), 0);
    reverse(order.begin(), order.end());

    int cnt = 0;
    for(int u : order) {
        if(!vis[u]) {
            vector<int> component;
            dfs2(u, rg, vis, component);
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
