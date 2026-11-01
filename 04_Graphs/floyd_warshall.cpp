#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m;
    cin >> n >> m;
    const ll INF = LLONG_MAX / 4;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));

    for(int i = 0; i < n; i++) dist[i][i] = 0;
    for(int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u; --v;
        dist[u][v] = min(dist[u][v], w);
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << (dist[i][j] == INF ? -1 : dist[i][j]) << " ";
        cout << "\n";
    }
    return 0;
}
