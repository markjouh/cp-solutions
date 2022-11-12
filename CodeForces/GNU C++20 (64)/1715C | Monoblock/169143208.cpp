#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = n * (n + 1) / 2;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1]) {
            ans += (i + 1) * (n - i - 1);
        }
    }
    while (m--) {
        ll i, x;
        cin >> i >> x;
        i--;
        if (i > 0) {
            if (a[i - 1] == a[i] && a[i - 1] != x) {
                ans += i * (n - i);
            }
            if (a[i - 1] != a[i] && a[i - 1] == x) {
                ans -= i * (n - i);
            }
        }
        if (i < n - 1) {
            if (a[i] == a[i + 1] && x != a[i + 1]) {
                ans += (i + 1) * (n - i - 1);
            }
            if (a[i] != a[i + 1] && x == a[i + 1]) {
                ans -= (i + 1) * (n - i - 1);
            }
        }
        a[i] = x;
        cout << ans << '\n';
    }
}