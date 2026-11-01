#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool is_prime(ll n) {
    if(n < 2) return false;
    if(n % 2 == 0) return n == 2;

    for(ll i = 3; i <= n / i; i += 2) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    ll n;
    cin >> n;
    cout << (is_prime(n) ? "Prime" : "Not Prime") << "\n";
    return 0;
}
