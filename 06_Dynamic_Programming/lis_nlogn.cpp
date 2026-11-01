#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(ll &x : a) cin >> x;

    vector<ll> dp;
    for(ll x : a) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if(it == dp.end()) dp.push_back(x);
        else *it = x;
    }

    cout << dp.size() << "\n";
    return 0;
}
