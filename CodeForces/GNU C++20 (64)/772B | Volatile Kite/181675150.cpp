#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pt;
#define x first
#define y second
 
ll xp(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}
 
pt sub(pt a, pt b) {
    return {b.first - a.first, b.second - a.second};
}
 
double dist(pt a, pt b) {
    double xd = b.x - a.x;
    double yd = b.y - a.y;
    return sqrt(xd * xd + yd * yd);
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pt> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    double ans = 2e18;
    for (int i = 0; i < n; i++) {
        pt a = p[(i + n - 1) % n];
        pt b = p[i];
        pt c = p[(i + 1) % n];
 
        ans = min(ans, abs(xp(sub(b, a), sub(c, a))) / dist(a, c) / 2.0);
    }
    cout << setprecision(10) << fixed << ans << '\n';
}