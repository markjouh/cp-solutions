#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
 
ll cdiv(ll a, ll b) {
    return (a + b - 1) / b;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        ll n, k, b, s;
        cin >> n >> k >> b >> s;
        
        vector<ll> a(n);
        a[0] = b * k;
        s -= b * k;
        for (int i = 0; i < n; i++) {
            if (s > 0) {
                ll mn = min(k - 1, s);
                a[i] += mn;
                s -= mn;
            }
        }
 
        if (s != 0) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
    }
}