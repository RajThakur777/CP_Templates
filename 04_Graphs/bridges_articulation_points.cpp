#include <bits/stdc++.h>
using namespace std;
#define ll long long

int timer_dfs = 0;
vector<int> tin, low, is_art;
vector<pair<int,int>> bridges;

void dfs(int u, int p, vector<vector<int>> &g) {
    tin[u] = low[u] = ++timer_dfs;
    int children = 0;

    for(int v : g[u]) {
        if(v == p) continue;

        if(tin[v]) {
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u, g);
            low[u] = min(low[u], low[v]);
            children++;

            if(low[v] > tin[u]) bridges.push_back({u, v});
            if(p != -1 && low[v] >= tin[u]) is_art[u] = 1;
        }
    }

    if(p == -1 && children > 1) is_art[u] = 1;
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

    tin.assign(n, 0);
    low.assign(n, 0);
    is_art.assign(n, 0);

    for(int i = 0; i < n; i++) if(!tin[i]) dfs(i, -1, g);

    cout << "Bridges:\n";
    for(auto [u, v] : bridges) cout << u + 1 << " " << v + 1 << "\n";

    cout << "Articulation points:\n";
    for(int i = 0; i < n; i++) if(is_art[i]) cout << i + 1 << " ";
    cout << "\n";
    return 0;
}
