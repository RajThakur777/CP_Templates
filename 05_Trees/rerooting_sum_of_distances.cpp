#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> g;
vector<ll> subtree_size, ans;
ll n;

void dfs1(int u, int p, ll depth, ll &root_sum) {
    subtree_size[u] = 1;
    root_sum += depth;

    for(int v : g[u]) {
        if(v == p) continue;
        dfs1(v, u, depth + 1, root_sum);
        subtree_size[u] += subtree_size[v];
    }
}

void dfs2(int u, int p) {
    for(int v : g[u]) {
        if(v == p) continue;
        ans[v] = ans[u] - subtree_size[v] + (n - subtree_size[v]);
        dfs2(v, u);
    }
}

int main() {
    cin >> n;
    g.assign(n, {});
    subtree_size.assign(n, 0);
    ans.assign(n, 0);

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs1(0, -1, 0, ans[0]);
    dfs2(0, -1);

    for(ll x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}
