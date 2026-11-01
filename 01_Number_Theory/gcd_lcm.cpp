#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd_ll(ll a, ll b) {
    while(b) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return abs(a);
}

ll lcm_ll(ll a, ll b) {
    if(a == 0 || b == 0) return 0;
    return abs((a / gcd_ll(a, b)) * b);
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << gcd_ll(a, b) << " " << lcm_ll(a, b) << "\n";
    return 0;
}
