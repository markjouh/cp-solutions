#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
#define fi first
#define se second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int pref = 0, suf = 0;
        for (int i = 0; i < n; i++) {
            suf += !a[i];
        }
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            // cout << pref << ' ' << suf << '\n';
            ans = min(ans, pref + max(0, suf - pref));
            pref += a[i];
            suf -= !a[i];
        }
        ans = min(ans, pref);
        cout << ans << '\n';
    }
}