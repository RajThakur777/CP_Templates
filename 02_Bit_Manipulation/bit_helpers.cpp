#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool is_set(ll n, int bit) {
    return (n >> bit) & 1LL;
}

ll set_bit(ll n, int bit) {
    return n | (1LL << bit);
}

ll clear_bit(ll n, int bit) {
    return n & ~(1LL << bit);
}

ll toggle_bit(ll n, int bit) {
    return n ^ (1LL << bit);
}

int count_set_bits(ll n) {
    return __builtin_popcountll(n);
}

bool is_power_of_two(ll n) {
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    ll n;
    cin >> n;
    cout << count_set_bits(n) << "\n";
    cout << (is_power_of_two(n) ? "YES" : "NO") << "\n";
    return 0;
}
