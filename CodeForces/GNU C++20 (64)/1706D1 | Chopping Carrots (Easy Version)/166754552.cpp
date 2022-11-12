#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<bool> quo(3001);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                quo[a[i] / j] = true;
            }
        }
        int ans = 1e9;
        for (int mx = 0; mx <= 3000; mx++) {
            if (!quo[mx]) {
                continue;
            }
            bool ok = true;
            int mn = mx;
            for (int i = 0; i < n; i++) {
                int l = 0, r = k;
                while (l + 1 < r) {
                    int mid = l + (r - l) / 2;
                    (a[i] / mid <= mx ? r : l) = mid;
                }
 
                if (a[i] / r <= mx) {
                    mn = min(mn, a[i] / r);
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = min(ans, mx - mn);
            }
        }
        cout << ans << '\n';
    }
}