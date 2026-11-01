#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll INF = LLONG_MAX / 4;

vector<ll> dijkstra(int src, vector<vector<pair<int,ll>>> &g) {
    int n = g.size();
    vector<ll> dist(n, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if(d != dist[u]) continue;

        for(auto [v, w] : g[u]) {
            if(d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,ll>>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    vector<ll> dist = dijkstra(0, g);
    for(ll d : dist) cout << (d == INF ? -1 : d) << " ";
    cout << "\n";
    return 0;
}
