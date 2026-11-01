#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> build_spf(int n) {
    vector<int> spf(n + 1);
    for(int i = 0; i <= n; i++) spf[i] = i;

    for(ll i = 2; i * i <= n; i++) {
        if(spf[i] == i) {
            for(ll j = i * i; j <= n; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
    return spf;
}

vector<pair<int,int>> factorize(int n, vector<int> &spf) {
    vector<pair<int,int>> factors;
    while(n > 1) {
        int p = spf[n], cnt = 0;
        while(n % p == 0) {
            n /= p;
            cnt++;
        }
        factors.push_back({p, cnt});
    }
    return factors;
}

int main() {
    int n;
    cin >> n;

    vector<int> spf = build_spf(n);
    vector<pair<int,int>> factors = factorize(n, spf);

    for(auto [p, cnt] : factors) cout << p << "^" << cnt << " ";
    cout << "\n";
    return 0;
}
