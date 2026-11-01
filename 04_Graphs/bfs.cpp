#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> bfs(int src, vector<vector<int>> &g) {
    int n = g.size();
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : g[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
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

    vector<int> dist = bfs(0, g);
    for(int x : dist) cout << x << " ";
    cout << "\n";
    return 0;
}
