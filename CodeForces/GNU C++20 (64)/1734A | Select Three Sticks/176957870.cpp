#include <bits/stdc++.h>
using namespace std;
 
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
typedef long long ll;
 
// just solving a random div2a for fun
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int ans = 1e9;
    for (int i = 0; i + 2 < n; i++) {
        for (int j = i; j < i + 3; j++) {
            int cur = 0;
            for (int k = i; k < i + 3; k++) {
                cur += abs(a[j] - a[k]);
            }
            ans = min(ans, cur);
        }
    }
    cout << ans << '\n';
}
 
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(cin.failbit);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}