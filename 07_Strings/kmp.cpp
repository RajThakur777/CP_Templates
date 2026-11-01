#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> prefix_function(string &s) {
    int n = s.size();
    vector<int> pi(n, 0);

    for(int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> kmp_search(string &text, string &pattern) {
    vector<int> positions;
    if(pattern.empty()) return positions;

    vector<int> pi = prefix_function(pattern);
    int j = 0;

    for(int i = 0; i < (int)text.size(); i++) {
        while(j > 0 && text[i] != pattern[j]) j = pi[j - 1];
        if(text[i] == pattern[j]) j++;

        if(j == (int)pattern.size()) {
            positions.push_back(i - j + 1);
            j = pi[j - 1];
        }
    }
    return positions;
}

int main() {
    string s, p;
    cin >> s >> p;
    vector<int> ans = kmp_search(s, p);
    for(int x : ans) cout << x << " ";
    cout << "\n";
    return 0;
}
