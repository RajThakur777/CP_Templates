#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    if(n >= 0) is_prime[0] = false;
    if(n >= 1) is_prime[1] = false;

    for(ll i = 2; i * i <= n; i++) {
        if(is_prime[i]) {
            for(ll j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {
    int n;
    cin >> n;

    vector<bool> is_prime = sieve(n);
    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) cout << i << " ";
    }
    cout << "\n";
    return 0;
}
