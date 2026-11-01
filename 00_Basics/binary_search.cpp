#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for(ll i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());

    ll idx = lower_bound(v.begin(), v.end(), x) - v.begin();
    ll idx2 = upper_bound(v.begin(), v.end(), x) - v.begin();

    cout << idx << " " << idx2 << "\n";
    return 0;
}
