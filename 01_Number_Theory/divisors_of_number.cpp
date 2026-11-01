#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> divisors(ll n) {
    vector<ll> small, large;
    for(ll i = 1; i <= n / i; i++) {
        if(n % i == 0) {
            small.push_back(i);
            if(i != n / i) large.push_back(n / i);
        }
    }
    reverse(large.begin(), large.end());
    small.insert(small.end(), large.begin(), large.end());
    return small;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> d = divisors(n);
    for(ll x : d) cout << x << " ";
    cout << "\n";
    return 0;
}
