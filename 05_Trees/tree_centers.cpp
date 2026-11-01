#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> deg(n, 0);

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++) if(deg[i] <= 1) q.push(i);

    int remaining = n;
    while(remaining > 2) {
        int sz = q.size();
        remaining -= sz;

        while(sz--) {
            int u = q.front();
            q.pop();
            for(int v : g[u]) {
                deg[v]--;
                if(deg[v] == 1) q.push(v);
            }
        }
    }

    cout << "Tree center(s): ";
    while(!q.empty()) {
        cout << q.front() + 1 << " ";
        q.pop();
    }
    cout << "\n";
    return 0;
}
