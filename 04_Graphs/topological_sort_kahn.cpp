#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> topo_sort(int n, vector<vector<int>> &g) {
    vector<int> indeg(n, 0);
    for(int u = 0; u < n; u++) {
        for(int v : g[u]) indeg[v]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++) if(indeg[i] == 0) q.push(i);

    vector<int> order;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for(int v : g[u]) {
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
    }

    if((int)order.size() != n) return {};
    return order;
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
    }

    vector<int> order = topo_sort(n, g);
    if(order.empty()) cout << "Cycle exists\n";
    else {
        for(int x : order) cout << x + 1 << " ";
        cout << "\n";
    }
    return 0;
}
