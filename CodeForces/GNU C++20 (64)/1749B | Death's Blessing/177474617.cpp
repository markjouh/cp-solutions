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
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<ll> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
 
        int mx_id = max_element(all(b)) - b.begin();
 
        ll ans = 0;
 
        for (int i = 0; i < mx_id; i++) {
            ans += a[i];
            a[i + 1] += b[i];
        }
        for (int i = n - 1; i > mx_id; i--) {
            ans += a[i];
            a[i - 1] += b[i];
        }
        ans += a[mx_id];
 
        cout << ans << '\n';
    }
}