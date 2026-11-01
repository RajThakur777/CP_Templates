#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll phi(ll n) {
    ll ans = n;
    for(ll p = 2; p <= n / p; p++) {
        if(n % p == 0) {
            while(n % p == 0) n /= p;
            ans -= ans / p;
        }
    }
    if(n > 1) ans -= ans / n;
    return ans;
}

int main() {
    ll n;
    cin >> n;
    cout << phi(n) << "\n";
    return 0;
}
