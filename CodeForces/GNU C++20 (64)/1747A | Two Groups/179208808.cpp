#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define siz(x) (int)(x).size()
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        ll sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
 
        ll ans = sum;
 
        ll pref = 0;
        for (int i = 0; i < n; i++) {
            pref += a[i];
            ans = max(ans, abs(abs(pref) - abs(sum - pref)));
        }
 
        ll suf = 0;
        for (int i = n - 1; i >= 0; i--) {
            suf += a[i];
            ans = max(ans, abs(abs(suf) - abs(sum - suf)));
        }
 
        cout << ans << '\n';
    }
}