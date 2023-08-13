#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
 
void solve() {
    int n, d, h;
    cin >> n >> d >> h;
    ld ans = 1.0 * d * h / 2 * n;
    int prev_top = 0;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        if (prev_top > y) {
            ld overlap_h = prev_top - y;
            ld overlap_w = overlap_h / h * d;
            ans -= overlap_w * overlap_h / 2;
        }
        prev_top = y + h;
    }
    cout << setprecision(10) << fixed << ans << '\n';
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}