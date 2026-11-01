#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<int, vector<int>> farthest_node(int src, vector<vector<int>> &g) {
    int n = g.size();
    vector<int> dist(n, -1), parent(n, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v : g[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    int far = src;
    for(int i = 0; i < n; i++) {
        if(dist[i] > dist[far]) far = i;
    }
    return {far, parent};
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int a = farthest_node(0, g).first;
    auto [b, parent] = farthest_node(a, g);

    vector<int> path;
    for(int u = b; u != -1; u = parent[u]) path.push_back(u);
    reverse(path.begin(), path.end());

    cout << "Diameter in edges = " << (int)path.size() - 1 << "\n";
    cout << "Diameter path: ";
    for(int u : path) cout << u + 1 << " ";
    cout << "\n";
    return 0;
}
