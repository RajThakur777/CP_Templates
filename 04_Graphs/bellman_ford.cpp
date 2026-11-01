#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Edge {
    int u, v;
    ll w;
};

int main() {
    int n, m, src;
    cin >> n >> m >> src;
    --src;

    vector<Edge> edges(m);
    for(auto &e : edges) {
        cin >> e.u >> e.v >> e.w;
        --e.u; --e.v;
    }

    const ll INF = LLONG_MAX / 4;
    vector<ll> dist(n, INF);
    dist[src] = 0;

    for(int i = 0; i < n - 1; i++) {
        bool changed = false;
        for(auto e : edges) {
            if(dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }
        if(!changed) break;
    }

    bool negative_cycle = false;
    for(auto e : edges) {
        if(dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            negative_cycle = true;
        }
    }

    cout << (negative_cycle ? "Reachable negative cycle\n" : "No reachable negative cycle\n");
    for(ll d : dist) cout << (d == INF ? -1 : d) << " ";
    cout << "\n";
    return 0;
}
