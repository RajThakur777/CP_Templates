#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Point {
    ll x, y;
};

ll cross(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

string orientation(Point a, Point b, Point c) {
    ll val = cross(a, b, c);
    if(val == 0) return "Collinear";
    if(val > 0) return "Counter-clockwise";
    return "Clockwise";
}

int main() {
    Point a, b, c;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    cout << orientation(a, b, c) << "\n";
    return 0;
}
