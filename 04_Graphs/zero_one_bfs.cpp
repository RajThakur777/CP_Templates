#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> zero_one_bfs(int src, vector<vector<pair<int,int>>> &g) {
    int n = g.size();
    const int INF = 1e9;
    vector<int> dist(n, INF);
    deque<int> dq;

    dist[src] = 0;
    dq.push_front(src);

    while(!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        for(auto [v, w] : g[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if(w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<int> dist = zero_one_bfs(0, g);
    for(int d : dist) cout << (d == (int)1e9 ? -1 : d) << " ";
    cout << "\n";
    return 0;
}
