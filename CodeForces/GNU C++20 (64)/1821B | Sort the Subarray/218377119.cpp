#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(x...)
#endif
 
using ll = long long;
 
#define sz(x) static_cast<int>(size(x))
#define all(x) begin(x), end(x)
 
// MODIFIED
template <class T> bool ckmin(T &a, const T b) { return b <= a ? a = b, 1 : 0; }
template <class T> bool ckmax(T &a, const T b) { return a <= b ? a = b, 1 : 0; }
 
constexpr int INF = INT_MAX / 2;
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
 
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != b[i]) {
            r = i + 1;
            break;
        }
    }
 
    if (l == -1) {
        int run = 1, ans = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                run = 0;
            }
            ckmax(ans, ++run);
        }
        cout << ans << '\n';
        return;
    }
 
    int mn_val = *min_element(b.begin() + l, b.begin() + r);
    int mx_val = *max_element(b.begin() + l, b.begin() + r);
    while (l > 0 && ckmin(mn_val, a[l - 1])) {
        l--;
    }
    while (r < n && ckmax(mx_val, a[r])) {
        r++;
    }
    cout << l + 1 << ' ' << r << '\n';
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}