#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define ckmin(a, b) a = min(a, b)
#define ckmax(a, b) a = max(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
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
        sort(all(a));
 
        if (a[0] == a[n - 1]) {
            cout << n / 2 << '\n';
            continue;
        }
 
        vector<int> eq_bk(n);
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) {
                eq_bk[i] = 0;
            } else {
                eq_bk[i] = eq_bk[i - 1] + 1;
            }
        }
        vector<int> eq_ft(n);
        for (int i = n - 2; i >= 0; i--) {
            if (a[i] != a[i + 1]) {
                eq_ft[i] = 0;
            } else {
                eq_ft[i] = eq_ft[i + 1] + 1;
            }
        }
 
        ll cur = n - 1 - eq_ft[0];
        ll best = cur;
        for (int i = 1; i < n; i++) {
            cur -= i - eq_bk[i];
            cur += n - i - 1 - eq_ft[i];
            ckmax(best, cur);
        }
        cout << best << '\n';
    }
}