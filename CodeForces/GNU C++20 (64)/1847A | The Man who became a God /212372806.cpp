#include "bits/stdc++.h"
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
 
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
 
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> d;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        d.pb(abs(a[i] - a[i + 1]));
        ans += d[i];
    }
    sort(all(d));
    reverse(all(d));
    for (int i = 0; i < k - 1; i++) {
        ans -= d[i];
    }
    cout << ans << '\n';
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