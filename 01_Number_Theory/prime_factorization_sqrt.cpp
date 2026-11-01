#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<ll,ll>> prime_factors(ll n) {
    vector<pair<ll,ll>> factors;

    for(ll p = 2; p <= n / p; p++) {
        if(n % p == 0) {
            ll cnt = 0;
            while(n % p == 0) {
                n /= p;
                cnt++;
            }
            factors.push_back({p, cnt});
        }
    }

    if(n > 1) factors.push_back({n, 1});
    return factors;
}

int main() {
    ll n;
    cin >> n;

    vector<pair<ll,ll>> factors = prime_factors(n);
    for(auto [p, cnt] : factors) {
        cout << p << "^" << cnt << " ";
    }
    cout << "\n";
    return 0;
}
