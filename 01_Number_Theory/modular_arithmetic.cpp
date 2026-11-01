#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll mod = 1e9 + 7;

ll mod_add(ll a, ll b) {
    return ((a % mod) + (b % mod) + mod) % mod;
}

ll mod_sub(ll a, ll b) {
    return ((a % mod) - (b % mod) + mod) % mod;
}

ll mod_mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

ll mod_pow(ll a, ll b) {
    ll ans = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1) ans = mod_mul(ans, a);
        a = mod_mul(a, a);
        b >>= 1;
    }
    return ans;
}

ll mod_inv(ll a) {
    return mod_pow(a, mod - 2);
}

ll mod_div(ll a, ll b) {
    return mod_mul(a, mod_inv(b));
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << mod_pow(a, b) << "\n";
    return 0;
}
