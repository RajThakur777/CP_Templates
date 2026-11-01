#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> wt(n);
    vector<ll> val(n);
    for(int i = 0; i < n; i++) cin >> wt[i] >> val[i];

    vector<ll> dp(W + 1, 0);
    for(int i = 0; i < n; i++) {
        for(int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }

    cout << dp[W] << "\n";
    return 0;
}
