#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pt;
#define x first
#define y second
 
// my idea:
// if there are too many points in space, the answer will always be 0
// I feel like this bound will be pretty small
// in a 2-dimensional plane, for a point a, we can have at most 4 other points such that there are no angles < 90deg
// in a 3-dimensional plane, we can have 6
 
// so,
// in a 4-dimensional plane, we can have 8(?)
// in a 5-dimensional plane, we can have 10(?)
// or something like that
 
// I think I'll just run a O(n^3) bruteforce whevever n <= 100, and just output 0 when it's greater
 
array<ll, 5> getv(array<ll, 5> a, array<ll, 5> b) {
    array<ll, 5> ans;
    for (int i = 0; i < 5; i++) {
        ans[i] = b[i] - a[i];
    }
    return ans;
}
 
ll dot(array<ll, 5> a, array<ll, 5> b) {
    ll ans = 0;
    for (int i = 0; i < 5; i++) {
        ans += a[i] * b[i];
    }
    return ans;
}
 
double len(array<ll, 5> a) {
    double ans = a[0];
    for (int i = 1; i < 5; i++) {
        ans = sqrt(ans * ans + a[i] * a[i]);
    }
    return abs(ans);
}
 
double angle(array<ll, 5> a, array<ll, 5> b) {
    return acos(dot(a, b) / len(a) / len(b));
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<ll, 5>> p(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> p[i][j];
        }
    }
    if (n > 100) {
        cout << 0 << '\n';
        return 0;
    }
    vector<bool> good(n, true);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i == j || i == k || j == k) {
                    continue;
                }
                if (angle(getv(p[i], p[j]), getv(p[i], p[k])) < 1.570796) {
                    good[i] = false;
                }
                // cout << angle(getv(p[i], p[j]), getv(p[i], p[k])) << '\n';
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (good[i]) {
            ans.push_back(i + 1);
        }
    }
    cout << sz(ans) << '\n';
    for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] << '\n';
    }
}